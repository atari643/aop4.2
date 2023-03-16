#include <iostream>
#include <deque>
#include <algorithm>
#include <chrono>
#include <pthread.h>

#include "GrapheValue.h"
#include "ModeleDeForce.h"
#include "Sommet.h"
#include "Arete.h"
#include "Appli.h"
#include "utils.h"
using namespace std;


// Pas obligatroire : pour chronometrer et gerer les FPS
template <
    class result_t = std::chrono::milliseconds,
    class clock_t = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds>
auto since(std::chrono::time_point<clock_t, duration_t> const &start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
};

void *majVue(void *app)
{
    int fps = 10;
    float frequency = 1000. / fps;
    Appli *appli = (Appli *)app;
    auto start = std::chrono::steady_clock::now();

    while (appli->running())
    {
        if (since(start).count() > frequency)
        {
            appli->exec();
            start = std::chrono::steady_clock::now();
        }
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: ./app <graph_file>.txt" << endl;
        return 1;
    }
    srand(time(NULL));

    // chargement et création des graphe et fenetre d'affichage
    string fichier(argv[1]); //"graphe.txt";//"fiat.txt"
    GrapheValue g;
    if (!g.charger(fichier))
    {
        cout << "Erreur de chargement de fichier" << endl;
        return 1;
    }

    Appli app{LARGEUR, HAUTEUR};
    app.setGraphe(g);

    g.attacher(&app);

    pthread_t th_vue;
    pthread_create(&th_vue, nullptr, majVue, &app);

    // dessinerGrapheValue(g);
    pthread_t th_dessin;
   // pthread_create(&th_dessin, nullptr, dessinerGrapheValue, &g);
    pthread_create(&th_dessin, nullptr, ModeleDeForce::dessiner, &g);

    pthread_join(th_vue, nullptr);

    pthread_join(th_dessin, nullptr);
    // // pour ne pas fermer la fenêtre après le dessin
    // while (app.running()){
    //     app.exec();
    // }

    return 0;
}
