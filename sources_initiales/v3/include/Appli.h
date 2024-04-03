#ifndef APPLI_H
#define APPLI_H
#include <SFML/Graphics.hpp>
#include "GrapheValue.h"
#include "ObservateurGraphe.h"

class Appli : public ObservateurGraphe {
    
public:
    Appli(unsigned int largeur, unsigned int hauteur);

    void setGraphe(GrapheValue &g);
    void traiterAjout(const Sommet &n) override;
    void traiterAjout(const Arete &e) override ;

    void traiterSuppression(const Arete &e) override ;
    void traiterSuppression(const Sommet &n) override ;

    void traiterProprieteChangee(const Sommet &n) override;
    void traiterProprieteChangee(const Arete &e) override;
    bool running() const;
    void exec();

private:
    sf::View m_vue;
    sf::RenderWindow m_fenetre;
    sf::Font m_font;

    std::map<Sommet, sf::CircleShape> m_sommets;
    std::map<Sommet, sf::CircleShape> m_etiquette;
    std::map<Arete, std::pair<sf::Vertex, sf::Vertex> > m_aretes; 
    GrapheValue *m_g;

    bool m_montre_etiquette;
    bool m_interpoler_couleurs;

    static const float RAYON;
    static const std::string FICHIER_FONT;
    static const float SCALE;

    unsigned int m_largeur, m_hauteur;

    void traiter_evenements();
    void dessiner();
    void creerFormeSommet(const Sommet &n);
    void creerFormeArete(Arete e);    
    void calculerFormesGeometriques();

};

#endif // APPLI_H
