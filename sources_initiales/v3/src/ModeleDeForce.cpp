#include "ModeleDeForce.h"
#include <cmath>
float maxDeplacement=20;
int IDEAL = 30;
ModeleDeForce::ModeleDeForce(GrapheValue *g)
{
    m_g = g;
}

void ModeleDeForce::executer()
{
    initialiserDessin(1200,800);
    while(maxDeplacement > 0)
    {
        for (auto sommet : m_g->sommets())
        {
            Coord deplacement = calculerForces(sommet);
            deplacer(sommet, deplacement);
            
        }
        maxDeplacement-=0.3;
    }

}
void ModeleDeForce::initialiserDessin( unsigned int largeur, unsigned int hauteur)
{
    for (auto sommet : m_g->sommets())
    {
        Coord c = {rand() % largeur, rand() % hauteur};
        m_g->positionSommet(sommet, c);
    }
}
Coord ModeleDeForce::calculerForces(const Sommet &v)
{
    return calculerAttractions(v) + calculerRepulsions(v) + calculerForceGravite(v);
}

Coord ModeleDeForce::calculerAttractions(const Sommet &v)
{
    Coord sommeForce = {0, 0};
    for(auto voisin : m_g->voisins(v))
    {
        Coord vu =  m_g->positionSommet(voisin) - m_g->positionSommet(v);
        float dist = vu.norm();
        sommeForce += (vu * ((float) dist / (float) pow(IDEAL, 2)));

    }
    if(sommeForce.norm() > 300){
        sommeForce /= sommeForce.norm(); // vecteur unitaire
        sommeForce *= 300; // vecteur de norme MAX_ATTRACTIVE
    }
    return sommeForce;
}
Coord ModeleDeForce::calculerRepulsions(const Sommet &v)
{
    Coord force = Coord();
    const Coord & coord_v =  m_g->positionSommet(v);
    for (const Sommet & u : m_g->sommets())
    {
        if (!(u == v))
        {   
        float dist = (m_g->positionSommet(u) - coord_v).norm();
        force += (coord_v - m_g->positionSommet(u)) * (IDEAL / pow(dist, 3));
        }
    }
    if (force.norm() > 60)
    {
        force /= force.norm();  // vecteur unitaire
        force *= 60; // vecteur de norme MAX_ATTRACTIVE
    }
    return force;

}

void ModeleDeForce::deplacer(const Sommet &v, Coord deplacement)
{
    Coord c = m_g->positionSommet(v);
    int deplacementNorm = deplacement.norm(); 

    if (deplacementNorm > maxDeplacement) {
        deplacement /= deplacementNorm;
        deplacement *= maxDeplacement; 
    }

    m_g->positionSommet(v, m_g->positionSommet(v) + deplacement);
}

Coord ModeleDeForce::calculerForceGravite(const Sommet &n)
{
    Coord bary;
    for (Sommet s : m_g->sommets()){
        bary += m_g->positionSommet(s);
    }
    bary /= m_g->sommets().size();

    Coord vbary =  bary - m_g->positionSommet(n);

    return vbary * 0.01;

}


void * ModeleDeForce::dessiner(void *vg){
    GrapheValue * m_g =  (GrapheValue *) vg;
    ModeleDeForce mdf = ModeleDeForce(m_g);
    mdf.executer();

    pthread_exit(0);
}