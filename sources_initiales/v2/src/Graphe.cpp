#include <iostream> // permet d'afficher dans le terminal
#include <vector>
#include <fstream>
#include "Graphe.h" // on inclut la déclaration de classe
#include "utils.h"
using namespace std; // l'espace de nom standard contient un grnad nombre de fonctionnalités 


Sommet Graphe::ajouterSommet()
{
    Sommet s;
    l_sommets.insert(s);
    return s;

}

Arete Graphe::ajouterArete(const Sommet & n1, const Sommet& n2)
{
    Arete a;
    l_aretes.insert(a);
    l_sommets.insert(n1);
    l_sommets.insert(n2);
    sommets2Incidentes[n1].insert(a);
    sommets2Incidentes[n2].insert(a);
    aretes2Extremites[a] = make_pair(n1, n2);
    return a;
}

std::set<Sommet> Graphe::sommets() const
{
    return l_sommets;
}

std::set<Arete> Graphe::aretes() const
{
    return l_aretes;
}

std::set<Sommet> Graphe::voisins(const Sommet& n) const
{
    std::set<Sommet> voisin;
    for(auto a : sommets2Incidentes.at(n)){
        if(aretes2Extremites.at(a).first == n){
            voisin.insert(aretes2Extremites.at(a).second);
        }else{
            voisin.insert(aretes2Extremites.at(a).first);
        }
    }
    return voisin;
}

std::set<Arete> Graphe::incidentes(const Sommet& n) const
{
    std::set<Arete> incident;
    for(auto a : sommets2Incidentes.at(n)){
        if(aretes2Extremites.at(a).first == n || aretes2Extremites.at(a).second == n){
            incident.insert(a);
        }
    }
    return incident;

}

Sommet Graphe::source(const Arete &e) const
{
    return aretes2Extremites.at(e).first;
}

Sommet Graphe::destination(const Arete &e) const
{
    return aretes2Extremites.at(e).second;
}

int Graphe::degre(const Sommet& n) const
{
    return incidentes(n).size();
}

int Graphe::nbSommets() const
{
    return sommets().size();
}

int Graphe::nbAretes() const
{
    return aretes().size();
}

void Graphe::supprimerArete(const Arete &e)
{
    l_aretes.erase(e);
    sommets2Incidentes.at(aretes2Extremites.at(e).first).erase(e);
    sommets2Incidentes.at(aretes2Extremites.at(e).second).erase(e);
    aretes2Extremites.erase(e);

}

void Graphe::supprimerSommet(const Sommet &n)
{
    for(auto a : incidentes(n)){
        supprimerArete(a);
    }
    l_sommets.erase(n);
    sommets2Incidentes.erase(n);
}


bool Graphe::charger(std::string fichier)
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
            lignes = lignes.substr(0, lignes.size()-1);
            if (lignes == "#sommets"){
                continue;
            }
            else if (lignes == "#aretes")
            {
                sommetsFinis = true;
            }
            else if (!sommetsFinis)
            {
                int id = stoi(lignes);
                if (idSommet.find(id) != idSommet.end())
                    return false; // deux fois le meme identifiant dans le fichier
                Sommet n = ajouterSommet();
                idSommet[id] = n;
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
                ajouterArete(n1, n2);
            }
        }
        return true;
    }

