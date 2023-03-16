#ifndef GRAPHEVALUE_H
#define GRAPHEVALUE_H
#include <map>
#include <set>
#include <string>

#include "Graphe.h"

#include "Coord.h"
#include "Couleur.h"
#include "Propriete.hpp"

const Couleur COULEUR_DEFAUT = Couleur{255,0,0,255};
const std::string ETIQUETTE_DEFAUT = "";
const float METRIQUE_DEFAUT = 0.f;

class GrapheValue: public Graphe
{
private :
  
    // Proprietes
    Propriete<Couleur> m_couleurs;
    Propriete<Coord> m_positions;
    Propriete<std::string> m_labels;


public:

    bool charger(std::string fichier) override;

    Sommet ajouterSommet() override;
    Arete ajouterArete(const Sommet &n1, const Sommet & n2) override;

    void supprimerSommet(const Sommet &n) override;
    void supprimerArete(const Arete &e) override;

    // Position
    void positionSommet(Sommet n, Coord c) override;
    Coord positionSommet(Sommet n) const override;
    void positionsMinMax(Coord & min, Coord & max) override;

    // Couleur
    void couleurSommet(Sommet n, Couleur c) override;
    Couleur couleurSommet(Sommet n) override;
    void couleurArete(Arete e, Couleur c) override;
    Couleur couleurArete(Arete e) override;

    // Etiquette
    void etiquetteSommet(Sommet n, std::string etiquette) override;
    std::string etiquetteSommet(Sommet n) const override;
    void etiquetteArete(Arete e, std::string etiquette) override;
    std::string etiquetteArete(Arete e) const override;

   
    Sommet sommet(const Coord &c, int rayon) override;


};

#endif // GRAPHEVALUE_H
