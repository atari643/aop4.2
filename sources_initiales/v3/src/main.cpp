#include <iostream>
#include <deque>
#include <algorithm>
#include "GrapheValue.h"
#include "Sommet.h"
#include "Arete.h"
#include "Appli.h"
#include <pthread.h>
#include "ModeleDeForce.h"
#include "signal.h"
using namespace std;

const int LARGEUR = 1920;
const int HAUTEUR = 1080;


void * miseAJourAppli(void * param){
    GrapheValue * g = (GrapheValue *)param;
    Appli app {LARGEUR, HAUTEUR};
    app.setGraphe(*g); 
    g->attacher(&app);
    while(app.running()){
        app.exec();
    }
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t thDessiner, thMiseAJourAppli;
    if (argc != 2){
        cout << "Usage: ./app <graph_file>.txt" << endl;
        return 1;
    }
    srand(time(NULL));

    // chargement et création des graphe et fenetre d'affichage
    string fichier (argv[1]);//"graphe.txt";//"fiat.txt"
    GrapheValue g;
    if(!g.charger(fichier)){
        cout << "Erreur de chargement de fichier" << endl;
        return 1;
    }
    pthread_create(&thMiseAJourAppli, nullptr, miseAJourAppli, &g);
    pthread_create(&thDessiner, nullptr, ModeleDeForce::dessiner, &g);
    
    
    
    
    pthread_join(thMiseAJourAppli, nullptr);
    pthread_join(thDessiner, nullptr);
    
    return 0;
}
