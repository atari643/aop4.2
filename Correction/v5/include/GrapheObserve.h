#ifndef GRAPHEOBSERVEH
#define GRAPHEOBSERVEH

#include <vector>
#include "GRaphe.h"
#include "ObservateurGraphe.h"

class GrapheObserve
{
private:
    bool m_observateurs_arretes;

protected:
    std::set<ObservateurGraphe *> m_observateurs;

    virtual void notifierAjout(const Sommet &n);
    virtual void notifierAjout(const Arete &e);

    virtual void notifierSuppression(const Arete &e);
    virtual void notifierSuppression(const Sommet &n);

    virtual void notifierProprieteChangee(const Sommet &n);
    virtual void notifierProprieteChangee(const Arete &e);

public:
    GrapheObserve();
    virtual ~GrapheObserve() = default;

    virtual void attacher(ObservateurGraphe *observateur);
    virtual void detacher(ObservateurGraphe *observateur);

    virtual void arreteObservation();
    virtual void demarrerObservation();
};

#endif // GRAPHEOBSERVE_H