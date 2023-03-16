#ifndef GRAPHE_H
#define GRAPHE_H
#include <map>
#include <set>
#include <string>

#include "Sommet.h"
#include "Arete.h"
#include "Coord.h"
#include "Couleur.h"


class Graphe
{
protected :
    std::set<Sommet> m_sommets;
    std::set<Arete> m_aretes;

    std::map<Sommet, std::set<Arete> > m_incidentes;
    std::map<Arete, std::pair<Sommet,Sommet> > m_extremites;

public:
    Graphe() = default;
    
    virtual bool charger(std::string fichier);

    virtual Sommet ajouterSommet();
    virtual Arete ajouterArete(const Sommet &n1, const Sommet & n2);

    virtual void supprimerSommet(const Sommet &n);
    virtual void supprimerArete(const Arete &e);

    virtual std::set<Sommet> sommets() const;
    virtual std::set<Arete> aretes() const;

    virtual std::set<Sommet> voisins(Sommet n) const;
    virtual std::set<Arete> incidentes(Sommet n) const;

    virtual Sommet source(const Arete &e) const;
    virtual Sommet destination(const Arete &e) const;

    virtual int degre(const Sommet &n) const;

    virtual int nbSommets() const;
    virtual int nbAretes() const;

    // Position
    virtual void positionSommet(Sommet n, Coord c) = 0;
    virtual Coord positionSommet(Sommet n) const = 0;
    virtual void positionsMinMax(Coord & min, Coord & max) = 0;

    // Couleur
    virtual void couleurSommet(Sommet n, Couleur c) = 0;
    virtual Couleur couleurSommet(Sommet n) = 0;
    virtual void couleurArete(Arete e, Couleur c) = 0;
    virtual Couleur couleurArete(Arete e) = 0;

    // Etiquette
    virtual void etiquetteSommet(Sommet n, std::string etiquette) = 0;
    virtual std::string etiquetteSommet(Sommet n) const = 0;
    virtual void etiquetteArete(Arete e, std::string etiquette) = 0;
    virtual std::string etiquetteArete(Arete e) const = 0;

   
    virtual Sommet sommet(const Coord &c, int rayon) = 0;


};

#endif // GRAPHE_H
