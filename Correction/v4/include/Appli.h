#ifndef APPLI_H
#define APPLI_H
#include <SFML/Graphics.hpp>
#include <pthread.h>
#include <utility>

#include "GrapheValue.h"
#include "ObservateurGraphe.h"

class Appli : public ObservateurGraphe
{
public:
    Appli(unsigned int largeur, unsigned int hauteur);

    void setGraphe(GrapheValue &g);

    bool running() const;
    void exec();

private:
    pthread_mutex_t m_maj_formes;
    sf::RenderWindow m_fenetre;
    sf::Font m_font;

    std::map<Sommet, sf::CircleShape> m_sommets;
    std::map<Sommet, sf::Text> m_etiquettes;

    std::map<Arete, std::pair<sf::Vertex, sf::Vertex>> m_aretes;

    // sf::Text m_etiquette;
    GrapheValue *m_g;

    bool m_montre_etiquette;
    bool m_interpoler_couleurs;

    static const float RAYON;
    static const std::string FICHIER_FONT;

    unsigned int m_largeur, m_hauteur;

    void calculerFormesGeometriques();
    void creerFormeSommet(const Sommet &n, const Coord &center, const Coord &centre_fenetre, float ratio);
    void creerFormeArete(Arete e);
    void majFormeSommet(const Sommet &n, const Coord &center, const Coord &centre_fenetre, float ratio);
    void majFormeArete(Arete e);

protected:
    void traiter_evenements();
    void dessiner();

    void traiterAjout(const Sommet &n) override;
    void traiterAjout(const Arete &e) override;

    void traiterSuppression(const Arete &e) override;
    void traiterSuppression(const Sommet &n) override;

    void traiterProprieteChangee(const Sommet &n) override;
    void traiterProprieteChangee(const Arete &e) override;

    void traiterMiseAJourCompelete() override;
};

#endif // APPLI_H
