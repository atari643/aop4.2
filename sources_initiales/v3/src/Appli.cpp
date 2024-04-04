#include "Appli.h"
#include <SFML/Graphics.hpp>

float Appli::RAYON = 2.0f;
const std::string Appli::FICHIER_FONT = "./fonts/FreeSans.ttf";
float Appli::SCALE = 2.0f;
Appli::Appli(unsigned int largeur, unsigned int hauteur)
    : m_largeur(largeur), m_hauteur(hauteur)
{
    pthread_mutex_init(&m_mAJFormes, NULL);
    // Initialize the window
    sf::VideoMode vm = sf::VideoMode(m_largeur, m_hauteur);
    m_fenetre.create(vm, "Application", sf::Style::Default, sf::ContextSettings(0, 0, 8));
    m_font.loadFromFile(FICHIER_FONT); // Remove duplicate font loading
    m_vue.setSize(m_largeur, m_hauteur);
    std::map<Sommet, sf::CircleShape> m_sommets;
    std::map<Sommet, sf::CircleShape> m_etiquette;
    std::map<Arete, std::pair<sf::Vertex, sf::Vertex>> m_aretes;
    // Set up other variables
    m_montre_etiquette = true;
    m_interpoler_couleurs = false;
    m_g = nullptr;
}

void Appli::setGraphe(GrapheValue &g)
{
    m_g = &g;
    calculerFormesGeometriques();
}

bool Appli::running() const
{
    return m_fenetre.isOpen();
}

void Appli::exec()
{
    while (running())
    {
        traiter_evenements();
        dessiner();
    }
}

void Appli::traiter_evenements()
{
    sf::Event event;
    while (m_fenetre.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_fenetre.close();
        }
        else if (event.type == sf::Event::MouseWheelScrolled)
        {
            if (event.mouseWheelScroll.delta > 0)
            {
                m_vue.zoom(0.9f);
                RAYON *= 0.9f;
            }
            else
            {
                m_vue.zoom(1.1f);
                RAYON *= 1.1f;
            }
            m_vue.setCenter(m_fenetre.mapPixelToCoords(sf::Vector2i(event.mouseWheelScroll.x, event.mouseWheelScroll.y)));
            m_fenetre.setView(m_vue);
        }
        else if (event.type == sf::Event::Resized)
        {
            // Resize the window
            m_vue.setSize(event.size.width, event.size.height);
            m_fenetre.setView(m_vue);}
        }
}

void Appli::dessiner()
{
    pthread_mutex_lock(&m_mAJFormes);

    m_fenetre.clear(sf::Color::White);
    
    for (std::pair<Arete, std::pair<sf::Vertex, sf::Vertex>> a : m_aretes)
    {
        sf::Vertex line[] = {a.second.first, a.second.second};
        m_fenetre.draw(line, 5, sf::Lines);
    }

    for (const std::pair<Sommet, sf::CircleShape> values : m_sommets)
    {

        const sf::CircleShape cs = values.second;
        m_fenetre.draw(cs);
    }

    const Sommet s = *m_g->sommets().begin();
    Coord min = m_g->positionSommet(s);
    Coord max = Coord();
    m_g->positionsMinMax(min, max);
    pthread_mutex_unlock(&m_mAJFormes);
    m_fenetre.display();
}

void Appli::traiterAjout(const Sommet &n)
{
    creerFormeSommet(n);
}

void Appli::traiterAjout(const Arete &e)
{
    creerFormeArete(e);
}

void Appli::traiterSuppression(const Sommet &n)
{
    pthread_mutex_lock(&m_mAJFormes);
    m_sommets.erase(n);
    pthread_mutex_unlock(&m_mAJFormes);
}

void Appli::traiterSuppression(const Arete &e)
{
    pthread_mutex_lock(&m_mAJFormes);
    m_aretes.erase(e);
    pthread_mutex_unlock(&m_mAJFormes);
}

void Appli::traiterProprieteChangee(const Sommet &n)
{
    pthread_mutex_lock(&m_mAJFormes);

    sf::CircleShape &cs = m_sommets[n];
    Coord coord = m_g->positionSommet(n);
    Couleur color = m_g->couleurSommet(n);
    cs.setPosition(coord[0], coord[1]);
    cs.setFillColor(sf::Color(color[0], color[1], color[2], color[3]));
    cs.setRadius(RAYON*2);
    cs.setOutlineThickness(RAYON);
    pthread_mutex_unlock(&m_mAJFormes);

    for (Arete a : m_g->incidentes(n))
    {
        traiterProprieteChangee(a);
    }
}
void Appli::traiterProprieteChangee(const Arete &e)
{
    pthread_mutex_lock(&m_mAJFormes);

    Coord src = m_g->positionSommet(m_g->source(e));
    Coord dst = m_g->positionSommet(m_g->destination(e));
    std::pair<sf::Vertex, sf::Vertex> &pos = m_aretes[e];
    pos.first.position = sf::Vector2f(src[0], src[1]);
    pos.second.position = sf::Vector2f(dst[0], dst[1]);

    pthread_mutex_unlock(&m_mAJFormes);
}

void Appli::creerFormeSommet(const Sommet &n)
{
    pthread_mutex_lock(&m_mAJFormes);

    sf::CircleShape cercle(RAYON * 2);
    cercle.setOutlineColor(sf::Color::Black);
    cercle.setOutlineThickness(1);

    cercle.setFillColor(sf::Color(m_g->couleurSommet(n)[0], m_g->couleurSommet(n)[1], m_g->couleurSommet(n)[2], m_g->couleurSommet(n)[3]));
    cercle.setPosition((m_g->positionSommet(n)[0] - RAYON) * SCALE, (m_g->positionSommet(n)[1] - RAYON) * SCALE);
    m_sommets[n] = cercle;
    pthread_mutex_unlock(&m_mAJFormes);
}

void Appli::creerFormeArete(Arete e)
{
    pthread_mutex_lock(&m_mAJFormes);

    sf::Vertex ligne[] = {
        sf::Vertex(sf::Vector2f(m_g->positionSommet(m_g->source(e))[0] * SCALE, m_g->positionSommet(m_g->source(e))[1] * SCALE), sf::Color(m_g->couleurArete(e)[0], m_g->couleurArete(e)[1], m_g->couleurArete(e)[2], m_g->couleurArete(e)[3])),
        sf::Vertex(sf::Vector2f(m_g->positionSommet(m_g->destination(e))[0] * SCALE, m_g->positionSommet(m_g->destination(e))[1] * SCALE), sf::Color(m_g->couleurArete(e)[0], m_g->couleurArete(e)[1], m_g->couleurArete(e)[2]))};
    m_aretes[e] = std::make_pair(ligne[0], ligne[1]);
    pthread_mutex_unlock(&m_mAJFormes);
}

void Appli::calculerFormesGeometriques()
{
    for (const auto &arete : m_g->aretes())
    {
        creerFormeArete(arete);
    }
    for (const auto &sommet : m_g->sommets())
    {
        creerFormeSommet(sommet);
    }
}
