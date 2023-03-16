#include <set>
#include <iostream>
#include <assert.h>

#include <SFML/Graphics.hpp>

#include "Appli.h"
#include "Couleur.h"
using namespace std;
using namespace sf;

/*
 constantes et fonction auxiliaires
 pour l'implémentation de Appli
*/

const float Appli::RAYON = 4.0;
const string Appli::FICHIER_FONT = "fonts/FreeSans.ttf";

// ---------------------------------------
Coord centerCoord(const Coord &c, const Coord &centre, const Coord &centre_fenetre, float ratio)
{
    Coord res = c;
    res -= centre;
    res *= ratio;
    res += centre_fenetre;
    return res;
}

Appli::Appli(unsigned int largeur, unsigned int hauteur)
    : // m_sommet{RAYON},
      m_montre_etiquette{false}, m_largeur{largeur}, m_hauteur{hauteur}, m_g{nullptr}, m_maj_formes(PTHREAD_MUTEX_INITIALIZER), m_interpoler_couleurs(false)

{
    sf::ContextSettings settings(0, 0, 8, 3, 1);
    // settings.antialiasingLevel = 8;
    // settings.major=3;
    // settings.minor = 1;
    m_fenetre.create(sf::VideoMode{largeur, hauteur, 32},
                     "Dessin de graphe",
                     sf::Style::Close, settings);
    m_fenetre.setFramerateLimit(50);

    m_font.loadFromFile(FICHIER_FONT);
}

void Appli::creerFormeSommet(const Sommet &n, const Coord &centre, const Coord &centre_fenetre, float ratio)
{
    pthread_mutex_lock(&m_maj_formes);

    Coord c = m_g->positionSommet(n);
    c = centerCoord(c, centre, centre_fenetre, ratio);
    sf::Vector2f pos{c.m_x, c.m_y};
    Couleur col = m_g->couleurSommet(n);
    string etiquette = m_g->etiquetteSommet(n);
    sf::CircleShape cercle;
    cercle.setOrigin({RAYON, RAYON});
    cercle.setOutlineColor(sf::Color::Black);
    cercle.setOutlineThickness(0.5);
    cercle.setPosition(pos);
    cercle.setFillColor(Color(col[0], col[1], col[2], col[3]));
    cercle.setRadius(RAYON);
    m_sommets[n] = cercle;

    string s = m_g->etiquetteSommet(n);
    sf::Text text;
    text.setFont(m_font);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(RAYON * 4);
    text.setString(s.c_str());

    FloatRect bb = text.getLocalBounds();           // retourne les positions et taille réelles de s
    float height_factor = (2. * RAYON) / bb.height; // facteur de mise à l'échelle pour la largeur
    text.setScale(height_factor, height_factor);

    // centre l'etiquette sur le sommet
    bb = text.getGlobalBounds();
    pos.x -= bb.width / 2.f;
    pos.y -= bb.height / 2.f;
    text.setPosition(pos);
    m_etiquettes[n] = text;

    pthread_mutex_unlock(&m_maj_formes);
}

void Appli::creerFormeArete(Arete e)
{
    pthread_mutex_lock(&m_maj_formes);

    Sommet src = m_g->source(e);
    Sommet dest = m_g->destination(e);

    CircleShape circle_src = m_sommets[src];
    CircleShape circle_dest = m_sommets[dest];

    sf::Vector2f pos_src = circle_src.getPosition();
    sf::Vector2f pos_dest = circle_dest.getPosition();

    sf::Color col_src;
    sf::Color col_dest;
    if (m_interpoler_couleurs)
    {
        col_src = circle_src.getFillColor();
        col_dest = circle_dest.getFillColor();
    }
    else
    {
        Couleur couleur = m_g->couleurArete(e);
        col_src = col_dest = sf::Color(couleur[0], couleur[1], couleur[2], couleur[3]);
    }
    pair<Vertex, Vertex> line{sf::Vertex(pos_src, col_src),
                              sf::Vertex(pos_dest, col_dest)};
    m_aretes[e] = line;

    pthread_mutex_unlock(&m_maj_formes);
}

void Appli::majFormeSommet(const Sommet &n, const Coord &centre, const Coord &centre_fenetre, float ratio)
{
    pthread_mutex_lock(&m_maj_formes);

    Coord c = m_g->positionSommet(n);
    c = centerCoord(c, centre, centre_fenetre, ratio);
    sf::Vector2f pos{c.m_x, c.m_y};
    Couleur col = m_g->couleurSommet(n);
    sf::CircleShape &cercle = m_sommets[n];

    cercle.setOrigin({RAYON, RAYON});
    cercle.setOutlineColor(sf::Color::Black);
    cercle.setOutlineThickness(0.5);
    cercle.setPosition(pos);
    cercle.setFillColor(Color(col[0], col[1], col[2], col[3]));
    cercle.setRadius(RAYON);

    string etiquette = m_g->etiquetteSommet(n);
    sf::Text &text = m_etiquettes[n];
    text.setString(etiquette.c_str());

    FloatRect bb = text.getLocalBounds();           // retourne les positions et taille réelles de s
    float height_factor = (2. * RAYON) / bb.height; // facteur de mise à l'échelle pour la largeur
    text.setScale(height_factor, height_factor);

    // centre l'etiquette sur le sommet
    bb = text.getGlobalBounds();
    pos.x -= bb.width / 2.f;
    pos.y -= bb.height / 2.f;
    text.setPosition(pos);

    pthread_mutex_unlock(&m_maj_formes);
}

void Appli::majFormeArete(Arete e)
{
    pthread_mutex_lock(&m_maj_formes);

    Sommet src = m_g->source(e);
    Sommet dest = m_g->destination(e);

    CircleShape circle_src = m_sommets[src];
    CircleShape circle_dest = m_sommets[dest];

    sf::Vector2f pos_src = circle_src.getPosition();
    sf::Vector2f pos_dest = circle_dest.getPosition();

    sf::Color col_src;
    sf::Color col_dest;
    if (m_interpoler_couleurs)
    {
        col_src = circle_src.getFillColor();
        col_dest = circle_dest.getFillColor();
    }
    else
    {
        Couleur couleur = m_g->couleurArete(e);
        col_src = col_dest = sf::Color(couleur[0], couleur[1], couleur[2], couleur[3]);
    }
    pair<Vertex, Vertex> &line = m_aretes[e];
    line.first = sf::Vertex(pos_src, col_src);
    line.second = sf::Vertex(pos_dest, col_dest);

    pthread_mutex_unlock(&m_maj_formes);
}

void Appli::calculerFormesGeometriques()
{
    pthread_mutex_lock(&m_maj_formes);
    if (m_g == nullptr)
        return;
    if (!m_sommets.empty())
        m_sommets.clear();
    if (!m_etiquettes.empty())
        m_etiquettes.clear();
    pthread_mutex_unlock(&m_maj_formes);

    Coord min, max;
    m_g->positionsMinMax(min, max);
    float r = std::min((m_largeur - 2 * RAYON) / (max.m_x - min.m_x), (m_hauteur - 2 * RAYON) / (max.m_y - min.m_y));

    Coord centre{(min + max) / 2.f};
    Coord centre_fenetre{m_largeur / 2.f, m_hauteur / 2.f};

    for (Sommet n : m_g->sommets())
    {
        creerFormeSommet(n, centre, centre_fenetre, r);
    }

    for (Arete e : m_g->aretes())
        creerFormeArete(e);
}

// ---------------------------------------
bool Appli::running() const
{
    return m_fenetre.isOpen();
}
// ---------------------------------------
void Appli::exec()
{
    if (m_fenetre.isOpen())
    {
        traiter_evenements();
        dessiner();
    }
}

// ---------------------------------------
void Appli::setGraphe(GrapheValue &g)
{
    m_g = &g;
    calculerFormesGeometriques();
}

// ---------------------------------------

void Appli::traiter_evenements()
{
    sf::Event evenement;
    while (m_fenetre.pollEvent(evenement))
    {
        switch (evenement.type)
        {
        case sf::Event::Closed: // gestionnaire de fenêtre
            m_fenetre.close();
            break;
        case sf::Event::KeyPressed: // clavier
            switch (evenement.key.code)
            {
            case sf::Keyboard::Escape: // touche échappement
                m_fenetre.close();
                break;
            case sf::Keyboard::L: // touche L
                m_montre_etiquette = !m_montre_etiquette;
                break;
            case sf::Keyboard::I: // touche I
                m_interpoler_couleurs = !m_interpoler_couleurs;
                for (Arete e : m_g->aretes())
                    majFormeArete(e);

                break;
            default:
                // autre touche
                break;
            };
        default:
            break;
        }
    }
}

// ---------------------------------------

void Appli::dessiner()
{
    pthread_mutex_lock(&m_maj_formes);
    // cout << "Dessin.." << flush;
    m_fenetre.clear(sf::Color::White);

    // dessin des aretes
    for (auto e : m_g->aretes())
    {
        Vertex line[] = {m_aretes[e].first, m_aretes[e].second};
        m_fenetre.draw(line, 2, sf::Lines);
    }

    // dessin des sommets
    for (auto n : m_g->sommets())
    {
        m_fenetre.draw(m_sommets[n]);
        if (m_montre_etiquette)
            m_fenetre.draw(m_etiquettes[n]);
    }
    pthread_mutex_unlock(&m_maj_formes);

    m_fenetre.display();
}

void Appli::traiterAjout(const Sommet &n)
{
    assert(m_sommets.find(n) == m_sommets.end());
    Coord min, max;
    m_g->positionsMinMax(min, max);
    // float r = std::min(m_largeur / (max.m_x - min.m_x), m_hauteur / (max.m_y - min.m_y));
    float r = std::min((m_largeur - 2 * RAYON) / (max.m_x - min.m_x), (m_hauteur - 2 * RAYON) / (max.m_y - min.m_y));
    Coord centre{(min + max) / 2.f};
    Coord centre_fenetre{m_largeur / 2.f, m_hauteur / 2.f};
    creerFormeSommet(n, centre, centre_fenetre, r);
}

void Appli::traiterAjout(const Arete &e)
{
    assert(m_aretes.find(e) == m_aretes.end());
    creerFormeArete(e);
}

void Appli::traiterSuppression(const Arete &e)
{
    assert(m_aretes.find(e) != m_aretes.end());
    m_aretes.erase(m_aretes.find(e));
}

void Appli::traiterSuppression(const Sommet &n)
{
    assert(m_sommets.find(n) != m_sommets.end());
    m_sommets.erase(m_sommets.find(n));
}

void Appli::traiterProprieteChangee(const Sommet &n)
{
    assert(m_sommets.find(n) != m_sommets.end());
    Coord min, max;
    m_g->positionsMinMax(min, max);
    float r = std::min((m_largeur - 2 * RAYON) / (max.m_x - min.m_x), (m_hauteur - 2 * RAYON) / (max.m_y - min.m_y));
    // float r = std::min(m_largeur / (max.m_x - min.m_x), m_hauteur / (max.m_y - min.m_y));
    Coord centre{(min + max) / 2.f};
    Coord centre_fenetre{m_largeur / 2.f, m_hauteur / 2.f};
    majFormeSommet(n, centre, centre_fenetre, r);

    for (Arete e : m_g->incidentes(n))
    {
        majFormeArete(e);
    }
}

void Appli::traiterProprieteChangee(const Arete &e)
{
    assert(m_aretes.find(e) != m_aretes.end());
    majFormeArete(e);
}

void Appli::traiterMiseAJourCompelete()
{
    calculerFormesGeometriques();
}