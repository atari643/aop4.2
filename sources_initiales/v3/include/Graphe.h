
#ifndef GRAPHE_H  
#define GRAPHE_H   


#include <set>
#include <map>
#include <string>

#include "Arete.h"
#include "Sommet.h"

class Graphe
{
private:
    std::map< Sommet, std::set<Arete> > sommets2Incidentes;
    std::map<Arete, std::pair<Sommet, Sommet> > aretes2Extremites;
    std::set<Sommet> l_sommets;
    std::set<Arete> l_aretes;
public:
    virtual bool charger(std::string fichier);
    Sommet ajouterSommet();
    Arete ajouterArete(const Sommet & n1, const Sommet& n2);
    void supprimerSommet( const Sommet &n);

    void supprimerArete(const Arete &e);

    std::set<Sommet> sommets() const;
    std::set<Arete> aretes() const;
    std::set<Sommet> voisins(const Sommet& n) const;
    std::set<Arete> incidentes(const Sommet& n) const;
    Sommet source(const Arete &e) const;
    Sommet destination(const Arete &e) const;
    int degre(const Sommet& n) const;
    int nbSommets() const;
    int nbAretes() const;

};


#endif