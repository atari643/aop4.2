#ifndef OBSERVATEURGRAPHE_H
#define OBSERVATEURGRAPHE_H

#include "Graphe.h"

class ObservateurGraphe
{
public:
    ObservateurGraphe() = default;

    virtual void traiterAjout(const Sommet &n) = 0;
    virtual void traiterAjout(const Arete &e) = 0;

    virtual void traiterSuppression(const Arete &e) = 0;
    virtual void traiterSuppression(const Sommet &n) = 0;

    virtual void traiterProprieteChangee(const Sommet &n) = 0;
    virtual void traiterProprieteChangee(const Arete &e) = 0;

    virtual void traiterMiseAJourCompelete() = 0;
};
#endif // OBSERVATEURGRAPHE_H