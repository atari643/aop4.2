#include <iostream>
#include <deque>
#include <algorithm>
#include <chrono>
#include <pthread.h>

#include "GrapheValue.h"
#include "Sommet.h"
#include "Arete.h"
#include "Appli.h"
using namespace std;

const int LARGEUR = 1200;
const int HAUTEUR = 800;

const float MAX_ATTRACTIVE = 100. * 3;
const float MAX_REPULSIVE = 20. * 3;
const float MAX_DEPLACEMENT = 20.;
const float EDGE_LENGTH = 10. * 3;
const float GRAVITE = .01;

void calculerDistances(const GrapheValue &g, Sommet n, map<Sommet, int> &distance)
{
    // TODO
}

void calculerDistances(const GrapheValue &g, Sommet n, map<Sommet, map<Sommet, int>> &distance)
{
    // TODO
}

void initialiserDessin(GrapheValue &g, unsigned int largeur, unsigned int hauteur)
{
    for (Sommet n : g.sommets())
    {
        Coord c{rand() % (largeur), rand() % (hauteur)};
        g.positionSommet(n, c);
    }
}

void initialiserIntelligementDessin(GrapheValue &g, unsigned int largeur, unsigned int hauteur)
{
    // TODO
    for (Sommet n : g.sommets())
    {
        Coord c{rand() % (largeur), rand() % (hauteur)};
        g.positionSommet(n, c);
    }
}

Coord calculerAttractions(const GrapheValue &g, Sommet n)
{
    Coord cn = g.positionSommet(n);
    Coord att;
    for (Sommet u : g.voisins(n))
    {
        Coord cu = g.positionSommet(u);
        Coord dir = (cu - cn) / (cu - cn).norm();
        float dist = (cu - cn).norm();
        dist *= dist;
        att += dir * dist / (EDGE_LENGTH * EDGE_LENGTH);
    }
    if (att.norm() > MAX_ATTRACTIVE)
    {
        att = att / att.norm();
        att = att * MAX_ATTRACTIVE;
    }
    return att;
}

Coord calculerRepulsions(const GrapheValue &g, Sommet n)
{
    Coord cn = g.positionSommet(n);
    Coord rep;
    for (Sommet u : g.sommets())
    {
        if (u == n)
            continue;
        Coord cu = g.positionSommet(u);
        Coord dir = cn - cu;
        float dist = dir.norm();
        dir = dir / dist;
        dist *= dist;
        if (dist > 1E-3)
        {
            rep += dir * (EDGE_LENGTH / dist);
        }
    }

    if (rep.norm() > MAX_REPULSIVE)
    {
        rep /= rep.norm();
        rep *= MAX_REPULSIVE;
    }
    return rep;
}

Coord calculerForces(const GrapheValue &g, Sommet n)
{
    return calculerRepulsions(g, n) + calculerAttractions(g, n);
}

Coord calculerBarycentre(const GrapheValue &g)
{
    Coord barycentre;
    for (Sommet n : g.sommets())
    {
        barycentre += g.positionSommet(n);
    }
    return barycentre / g.nbSommets();
}

Coord calculerForceGravite(const GrapheValue &g, Sommet n, const Coord &barycentre)
{
    return (barycentre - g.positionSommet(n)) * GRAVITE;
}

void deplacer(GrapheValue &g, Sommet n, Coord deplacement, float max_deplacement)
{
    if (deplacement.norm() > max_deplacement)
    {
        deplacement /= deplacement.norm();
        deplacement *= max_deplacement;
    }
    g.positionSommet(n, g.positionSommet(n) + deplacement);
}

void *dessinerGrapheValue(void *vg)
{
    GrapheValue *g = (GrapheValue *)vg;
    //  g->arreteObservation();
    // initialisation aléatoire
    initialiserDessin(*g, LARGEUR, HAUTEUR);

    //  g->demarrerObservation();

    float max_deplacement = MAX_DEPLACEMENT;
    // répéter autant de fois qu'il y a de sommets
    unsigned int nb_sommets = 200; // g->nbSommets;
    for (unsigned int i = 0; i < nb_sommets; ++i)
    {
        //  g->arreteObservation();
        Coord barycentre = calculerBarycentre(*g);
        for (Sommet n : g->sommets())
        {
            Coord deplacement = calculerForces(*g, n);
            deplacement = deplacement + calculerForceGravite(*g, n, barycentre);

            deplacer(*g, n, deplacement, max_deplacement);
        }
        max_deplacement = MAX_DEPLACEMENT * (1. - float(i) / nb_sommets);
        //   g->demarrerObservation();
    }
}

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
    int fps = 25;
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
    pthread_create(&th_dessin, nullptr, dessinerGrapheValue, &g);

    pthread_join(th_vue, nullptr);

    pthread_join(th_dessin, nullptr);
    // // pour ne pas fermer la fenêtre après le dessin
    // while (app.running()){
    //     app.exec();
    // }

    return 0;
}
