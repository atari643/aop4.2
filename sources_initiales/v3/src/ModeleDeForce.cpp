#include "ModeleDeForce.h"
#include <cmath>
#include <thread>
#include <iostream>
#include <vector>

float maxDeplacement=20;
int IDEAL = 60;
ModeleDeForce::ModeleDeForce(GrapheValue *g)
{
    m_g = g;

}

void ModeleDeForce::executer()
{
    srand(time(NULL));
    initialiserDessin(1920,1080);

    int iterations = 0;

    while(maxDeplacement > 0 && iterations < 2000)
    {
        std::vector<std::thread> threads;
        for (auto sommet : m_g->sommets())
        { 
            threads.push_back(std::thread([this, sommet](){
                Coord deplacement = calculerForces(sommet);
                deplacer(sommet, deplacement);
            }));
            
        }
        for (auto &t : threads)
        {
            t.join();
        }
        iterations++;
        printf("Iterations: %d\n", iterations);
        maxDeplacement *=0.99;

    }

}
void ModeleDeForce::initialiserDessin( unsigned int largeur, unsigned int hauteur)
{
    for (auto sommet : m_g->sommets())
    {
        Coord c = {float(rand() % largeur), float(rand() % hauteur)};
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
    Coord position_v = m_g->positionSommet(v);
    for(auto u : m_g->voisins(v))
    {
        Coord position_voisin = m_g->positionSommet(u);
        Coord vu =  position_voisin - position_v;
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