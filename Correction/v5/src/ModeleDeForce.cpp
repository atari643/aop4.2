#include "ModeleDeForce.h"
#include "utils.h"
#include <math.h>

ModeleDeForce::ModeleDeForce(GrapheValue *g): m_g(g){}

void * ModeleDeForce::dessiner(void *g){
    GrapheValue * gv = (GrapheValue *) g;
    ModeleDeForce algo_dessin (gv);
    algo_dessin.executer();
}


void ModeleDeForce::initialiserDessin(unsigned int largeur, unsigned int hauteur)
{
    for (const Sommet& n : m_g->sommets())
    {
        Coord c{rand() % (largeur), rand() % (hauteur)};
        m_g->positionSommet(n, c);
    }
}

void ModeleDeForce::initialiserIntelligementDessin( unsigned int largeur, unsigned int hauteur)
{
    // TODO
    for (const Sommet &n : m_g->sommets())
    {
        Coord c{rand() % (largeur), rand() % (hauteur)};
        m_g->positionSommet(n, c);
    }
}

Coord ModeleDeForce::calculerAttractions(const Sommet& n)
{
    Coord cn = m_g->positionSommet(n);
    Coord att;
    for (const Sommet& u : m_g->voisins(n))
    {
        Coord cu = m_g->positionSommet(u);
        Coord dir = (cu - cn) / (cu - cn).norm();
        float dist = (cu - cn).norm();
        dist *= dist;
        att += dir * dist / (EDGE_LENGTH * EDGE_LENGTH);
    }
    if (att.norm() > MAX_ATTRACTIVE)
    {
        att = att / att.norm();
        att = att * MAX_ATTRACTIVE;
    }
    return att;
}

Coord ModeleDeForce::calculerRepulsions(const Sommet& n)
{
    Coord cn = m_g->positionSommet(n);
    Coord rep;
    for (const Sommet& u : m_g->sommets())
    {
        if (u == n)
            continue;
        Coord cu = m_g->positionSommet(u);
        Coord dir = cn - cu;
        float dist = dir.norm();
        dir = dir / dist;
        dist *= dist;
        if (dist > 1E-3)
        {
            rep += dir * (EDGE_LENGTH / dist);
        }
    }

    if (rep.norm() > MAX_REPULSIVE)
    {
        rep /= rep.norm();
        rep *= MAX_REPULSIVE;
    }
    return rep;
}

Coord ModeleDeForce::calculerForces(const Sommet& n)
{
    return calculerRepulsions( n) + calculerAttractions(n);
}

Coord ModeleDeForce::calculerBarycentre()
{
    Coord barycentre;
    for (Sommet n : m_g->sommets())
    {
        barycentre += m_g->positionSommet(n);
    }
    return barycentre / m_g->nbSommets();
}

Coord ModeleDeForce::calculerForceGravite(const Sommet& n)
{
    return (m_barycentre - m_g->positionSommet(n)) * GRAVITE;
}

void ModeleDeForce::deplacer(const Sommet& n, Coord deplacement, float max_deplacement)
{
    if (deplacement.norm() > max_deplacement)
    {
        deplacement /= deplacement.norm();
        deplacement *= max_deplacement;
    }
    m_g->positionSommet(n, m_g->positionSommet(n) + deplacement);
}

void ModeleDeForce::executer()
{   
    initialiserDessin(LARGEUR, HAUTEUR);


    float max_deplacement = MAX_DEPLACEMENT;
    // répéter autant de fois qu'il y a de sommets
    unsigned int nb_iter = sqrt(m_g->nbAretes());
    for (unsigned int i = 0; i < nb_iter; ++i)
    {
        //  g->arreteObservation();
        m_barycentre = calculerBarycentre();
        for (const Sommet &n : m_g->sommets())
        {
            Coord deplacement = calculerForces(n);
            deplacement = deplacement + calculerForceGravite(n);

            deplacer(n, deplacement, max_deplacement);
        }
        max_deplacement = MAX_DEPLACEMENT * (1. - float(i) / nb_iter);
    }
}