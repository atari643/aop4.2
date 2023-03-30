#include <iostream>

#include "Graphe.h"
#include "Sommet.h"
#include "Arete.h"
using namespace std;


int main(int argc, char *argv[])
{
    if (argc != 2){
        cout << "Usage: ./app <graph_file>.csv" << endl;
        return 1;
    }

    // chargement et création des graphe et fenetre d'affichage
    string fichier (argv[1]);//"graphe.txt";//"fiat.txt"
    Graphe g;
    if(!g.charger(fichier)){
        cout << "Erreur de chargement de fichier" << endl;
        return 1;
    }
    cout << g.nbSommets() << " " << g.nbAretes() << endl;
    return 0;
}

