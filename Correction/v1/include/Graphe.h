#ifndef GRAPHE_H
#define GRAPHE_H
#include <map>
#include <set>
#include <string>

#include "Sommet.h"
#include "Arete.h"

class Graphe
{
private :
    std::set<Sommet> m_sommets;
    std::set<Arete> m_aretes;

    std::map<Sommet, std::set<Arete> > m_incidentes;
    std::map<Arete, std::pair<Sommet,Sommet> > m_extremites;

public:
    Graphe();

    bool charger(std::string fichier);

    Sommet ajouterSommet();
    Arete ajouterArete(const Sommet &n1, const Sommet & n2);

    void supprimerSommet(const Sommet &n);
    void supprimerArete(const Arete &e);

    std::set<Sommet> sommets() const;
    std::set<Arete> aretes() const;

    std::set<Sommet> voisins(Sommet n) const;
    std::set<Arete> incidentes(Sommet n) const;

    Sommet source(const Arete &e) const;
    Sommet destination(const Arete &e) const;

    int degre(const Sommet &n) const;

    int nbSommets() const;
    int nbAretes() const;
};

#endif // GRAPHE_H
