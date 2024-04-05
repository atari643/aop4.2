#include "GrapheValue.h"
#include "Coord.h"
#include "Couleur.h"
#include <fstream>
#include <string>
#include "utils.h"
#include <iostream>
using namespace std;

Coord GrapheValue::positionSommet(Sommet n) const
{
    return positions.valeur(n);
}

bool GrapheValue::charger(std::string fichier)
{
    map<int, Sommet> idSommet;

    // Ajout des sommets
    bool sommetsFinis = false;
    std::ifstream in(fichier.c_str());
    while (!in.eof())
    {
        char ligne[10000];
        in.getline(ligne, 10000);
        string lignes(ligne);
        lignes = lignes.substr(0, lignes.size());

        if (lignes == "#sommet;position;couleur;etiquette")
        {
            continue;
        }
        else if (lignes == "#aretes")
        {
            sommetsFinis = true;
        }
        else if (!sommetsFinis)
        {
            
            vector<string> allligne;
            decouper(lignes, allligne, ";");
            int id = stoi(allligne[0]);
            vector<string> coords;
            decouper(allligne[1], coords, " ");
            Sommet n = ajouterSommet();
            idSommet[id] = n;
            positionSommet(idSommet[id], Coord(stoi(coords[0]), stoi(coords[1])));
            vector<string> couls;
            decouper(allligne[2], couls, " ");

            couleurSommet(idSommet[id], Couleur(stoi(couls[0]), stoi(couls[1]), stoi(couls[2]), stoi(couls[3])));

            etiquetteSommet(idSommet[id], allligne[3]);            
            
        }
        else if (sommetsFinis && lignes != "")
        {
            vector<string> items;
            decouper(lignes, items, " ");
            if (items.size() != 2)
                return false;

            int id1 = stoi(items[0]);
            int id2 = stoi(items[1]);

            // test si les id sont corrects
            if (idSommet.find(id1) == idSommet.end() || idSommet.find(id2) == idSommet.end())
                return false;
            Sommet n1 = idSommet[id1];
            Sommet n2 = idSommet[id2];
            Arete a = ajouterArete(n1, n2);
            Couleur c1 = couleurs.valeur(n1);
            Couleur c2 = couleurs.valeur(n2);

            Couleur cArete=c1.interpoler(c2, 0.5);
            couleurArete(a, cArete);
        }
    }
    return true;
}

Sommet GrapheValue::ajouterSommet()
{
    //std::cout << "ajout sommet" << std::endl;
    Sommet n=Graphe::ajouterSommet();
    notifierAjout(n);
    return n;
}

Arete GrapheValue::ajouterArete(const Sommet &n1, const Sommet &n2)
{
    //std::cout << "ajout arete" << std::endl;
    Arete e=Graphe::ajouterArete(n1, n2);
    notifierAjout(e);
    return e;
}

void GrapheValue::supprimerSommet(const Sommet &n)
{
    //std::cout << "supprimer" << std::endl;
    notifierSuppression(n);
    Graphe::supprimerSommet(n);
}

void GrapheValue::supprimerArete(const Arete &e)
{
    //std::cout << "supprimer arete" << std::endl;
    notifierSuppression(e);
    Graphe::supprimerArete(e);
}

void GrapheValue::positionSommet(Sommet n, Coord c)
{
    //std::cout << "position sommet" << std::endl;
    notifierProprieteChangee(n);
    positions.changer(n, c);
}

void GrapheValue::positionsMinMax(Coord &min, Coord &max)
{
    //std::cout << "positions min max" << std::endl;
    for (auto n : sommets())
    {
        Coord c = positionSommet(n);
        min[0] = std::min(min[0], c[0]);
        min[1] = std::min(min[1], c[1]);
        max[0] = std::max(max[0], c[0]);
        max[1] = std::max(max[1], c[1]);
    }
}

void GrapheValue::couleurSommet(Sommet n, Couleur c)
{
    notifierProprieteChangee(n);
    couleurs.changer(n, c);
}

Couleur GrapheValue::couleurSommet(Sommet n)
{
    //std::cout << "couleur sommet 2" << std::endl;
    return couleurs.valeur(n);
}

void GrapheValue::couleurArete(Arete e, Couleur c)
{
    //std::cout << "couleur arete" << std::endl;
    notifierProprieteChangee(e);
    couleurs.changer(e, c);
}

Couleur GrapheValue::couleurArete(Arete e)
{
    //std::cout << "couleur arete 2" << std::endl;
    return couleurs.valeur(e);
}

void GrapheValue::etiquetteSommet(Sommet n, std::string etiquette)
{
    //std::cout << "etiquette" << std::endl;
    notifierProprieteChangee(n);
    labels.changer(n, etiquette);
}

std::string GrapheValue::etiquetteSommet(Sommet n) const
{
    //std::cout << "etiquette 2" << std::endl;
    return labels.valeur(n);
}

void GrapheValue::etiquetteArete(Arete e, std::string etiquette)
{
    //std::cout << "etiquette arete" << std::endl;
    notifierProprieteChangee(e);
    labels.changer(e, etiquette);
}

std::string GrapheValue::etiquetteArete(Arete e) const
{
    //std::cout << "etiquette arete 2" << std::endl;
    return labels.valeur(e);
}
