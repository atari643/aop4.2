#include <fstream>
#include <assert.h>
#include <iostream>
#include <vector>

#include "Graphe.h"
#include "utils.h"
using namespace std;


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
        // TODO regarder pour il est nécessaire de supprimer le dernier caractère
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

Sommet Graphe::ajouterSommet()
{
    Sommet n;
    m_sommets.insert(n);
    return n;
}

void Graphe::supprimerSommet(const Sommet &n)
{

    // Suppression des aretes incidentes
    assert(m_incidentes.find(n) != m_incidentes.end());
    for (auto e : m_incidentes.at(n))
        supprimerArete(e);
    m_incidentes.erase(m_incidentes.find(n));

    // Suppresion des sommets
    assert(m_sommets.find(n) != m_sommets.end());
    m_sommets.erase(m_sommets.find(n));
}

void Graphe::supprimerArete(const Arete &e)
{
    assert(m_aretes.find(e) != m_aretes.end());
    assert(m_extremites.find(e) != m_extremites.end());

    Sommet src = source(e);
    Sommet dest = destination(e);

    m_aretes.erase(m_aretes.find(e));
    m_extremites.erase(m_extremites.find(e));

    assert(m_incidentes.find(src) != m_incidentes.end());
    assert(m_incidentes.find(dest) != m_incidentes.end());

    set<Arete> &src_incidentes = m_incidentes[src];
    assert(src_incidentes.find(e) != src_incidentes.end());
    src_incidentes.erase(src_incidentes.find(e));

    set<Arete> &dest_incidentes = m_incidentes[dest];
    assert(dest_incidentes.find(e) != dest_incidentes.end());
    dest_incidentes.erase(dest_incidentes.find(e));
}

set<Sommet> Graphe::sommets() const
{
    return m_sommets;
}

set<Arete> Graphe::aretes() const
{
    return m_aretes;
}

set<Sommet> Graphe::voisins(Sommet n) const
{
    assert(m_incidentes.find(n) != m_incidentes.end());
    set<Sommet> voisinage;
    for (auto e : m_incidentes.at(n))
    {
        voisinage.insert(source(e).id() == n.id() ? destination(e) : source(e));
    }
    return voisinage;
}

set<Arete> Graphe::incidentes(Sommet n) const
{
    assert(m_incidentes.find(n) != m_incidentes.end());
    return m_incidentes.at(n);
}

Arete Graphe::ajouterArete(const Sommet &n1, const Sommet &n2)
{
    assert(m_sommets.find(n1) != m_sommets.end() && m_sommets.find(n2) != m_sommets.end());
    Arete e;
    m_aretes.insert(e);
    m_extremites[e] = pair<Sommet, Sommet>(n1, n2);
    m_incidentes[n1].insert(e);
    m_incidentes[n2].insert(e);
    return e;
}

Sommet Graphe::source(const Arete &e) const
{
    assert(m_aretes.find(e) != m_aretes.end());
    return m_extremites.at(e).first;
}

Sommet Graphe::destination(const Arete &e) const
{
    assert(m_aretes.find(e) != m_aretes.end());
    return m_extremites.at(e).second;
}

int Graphe::degre(const Sommet &n) const
{
    assert(m_sommets.find(n) != m_sommets.end());
    return m_incidentes.at(n).size();
}

int Graphe::nbSommets() const
{
    return m_sommets.size();
}

int Graphe::nbAretes() const
{
    return m_aretes.size();
}
