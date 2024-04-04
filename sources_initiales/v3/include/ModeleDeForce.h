#ifndef __MODELEDEFORCE_H__
#define __MODELEDEFORCE_H__

#include "GrapheValue.h"
class ModeleDeForce{
    GrapheValue * m_g;

public:
    ModeleDeForce(GrapheValue *g);
    static void * dessiner(void * vg);
    void initialiserDessin( unsigned int largeur, unsigned int hauteur);

    Coord calculerAttractions(const Sommet& v);
    Coord calculerRepulsions(const Sommet &v);

    Coord calculerForces(const Sommet &v);

    void deplacer(const Sommet &v, Coord deplacement);
    void executer();
    ModeleDeForce() = delete;
    Coord calculerForceGravite(const Sommet &n);
};
#endif // __MODELEDEFORCE_H__