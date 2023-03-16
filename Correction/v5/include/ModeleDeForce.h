#ifndef DESSINGRAPHE_H
#define DESSINGRAPHE_H
#include "GrapheValue.h"

class ModeleDeForce
{
private:
    GrapheValue * m_g;
    Coord m_barycentre;
    
    ModeleDeForce() = delete;
    ModeleDeForce(GrapheValue *g);

    const float MAX_ATTRACTIVE = 100. * 3;
    const float MAX_REPULSIVE = 20. * 3;
    const float MAX_DEPLACEMENT = 20.;
    const float EDGE_LENGTH = 10. * 3;
    const float GRAVITE = .01;

    void initialiserDessin( unsigned int largeur, unsigned int hauteur);
    void initialiserIntelligementDessin( unsigned int largeur, unsigned int hauteur);
    Coord calculerAttractions(const Sommet& n);
    Coord calculerRepulsions(const Sommet &n);
    Coord calculerForces(const Sommet &n);
    Coord calculerBarycentre();
    Coord calculerForceGravite(const Sommet &n);
    void deplacer(const Sommet &n, Coord deplacement, float max_deplacement);
    void executer();

public:
    static void *dessiner(void *vg);
};

#endif // DESSINGRAPHE_H