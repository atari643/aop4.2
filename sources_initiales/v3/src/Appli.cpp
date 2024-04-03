#include "Appli.h" 
#include <SFML/Graphics.hpp>
const float Appli::RAYON = 3.0f;
const std::string Appli::FICHIER_FONT = "./fonts/FreeSans.ttf";
const float Appli::SCALE = 1.35f;
Appli::Appli(unsigned int largeur, unsigned int hauteur)
    : m_largeur(largeur), m_hauteur(hauteur)
{
    // Initialize the window
    m_fenetre.create(sf::VideoMode(largeur, hauteur), "Application");

    // Load the font
    if (!m_font.loadFromFile(FICHIER_FONT))
    {
        // Handle font loading error
    }
    

    std::map<Sommet, sf::CircleShape> m_sommets;
    std::map<Sommet, sf::CircleShape> m_etiquette;
    std::map<Arete, std::pair<sf::Vertex, sf::Vertex> > m_aretes;
    // Set up other variables
    m_montre_etiquette = true;
    m_interpoler_couleurs = false;
    m_g = nullptr;
}

void Appli::setGraphe(GrapheValue &g)
{
    m_g = &g;
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
        // Handle other events
    }
}

void Appli::dessiner()
{
    m_fenetre.clear();
    m_fenetre.clear(sf::Color::White);
    // Draw the graph
        if (m_g != nullptr)
        {
            if (m_sommets.empty())
            {
                calculerFormesGeometriques();
            }
            for (const auto& arete : m_aretes)
            {
                m_fenetre.draw(&arete.second.first, 2, sf::Lines);
            }
            for (const auto& sommet : m_sommets)
            {
                m_fenetre.draw(sommet.second);
            }
          
            
        }

        
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
    m_sommets.erase(n);

}

void Appli::traiterSuppression(const Arete &e)
{
    m_aretes.erase(e);
}

void Appli::traiterProprieteChangee(const Sommet &n)
{
   traiterSuppression(n);
   traiterAjout(n);
}

void Appli::traiterProprieteChangee(const Arete &e)
{
    traiterSuppression(e);
    traiterAjout(e);
}

void Appli::creerFormeSommet(const Sommet &n)
{
    sf::CircleShape cercle(RAYON*2);
    cercle.setOutlineColor(sf::Color::Black);
    cercle.setOutlineThickness(1);
    
    cercle.setFillColor(sf::Color(m_g->couleurSommet(n)[0], m_g->couleurSommet(n)[1], m_g->couleurSommet(n)[2], m_g->couleurSommet(n)[3]));
    cercle.setPosition((m_g->positionSommet(n)[0] - RAYON) * SCALE, (m_g->positionSommet(n)[1] - RAYON) * SCALE);
    m_sommets[n] = cercle;
}

void Appli::creerFormeArete(Arete e)
{
    sf::Vertex ligne[] = {
        sf::Vertex(sf::Vector2f(m_g->positionSommet(m_g->source(e))[0] * SCALE, m_g->positionSommet(m_g->source(e))[1] * SCALE), sf::Color(m_g->couleurArete(e)[0], m_g->couleurArete(e)[1], m_g->couleurArete(e)[2], m_g->couleurArete(e)[3])),
        sf::Vertex(sf::Vector2f(m_g->positionSommet(m_g->destination(e))[0] * SCALE, m_g->positionSommet(m_g->destination(e))[1] * SCALE), sf::Color(m_g->couleurArete(e)[0], m_g->couleurArete(e)[1], m_g->couleurArete(e)[2]))
    };
    m_aretes[e] = std::make_pair(ligne[0], ligne[1]);
}

void Appli::calculerFormesGeometriques()
{
    for (const auto& arete : m_g->aretes())
    {
        creerFormeArete(arete);
    }
    for (const auto& sommet : m_g->sommets())
    {
        creerFormeSommet(sommet);
    }
    

}
