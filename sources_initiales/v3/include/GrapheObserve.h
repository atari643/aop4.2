#ifndef __GRAPHEOBSERVER_H__
#define __GRAPHEOBSERVER_H__

#include "ObservateurGraphe.h"
class GrapheObserve
{
protected:
    std::set<ObservateurGraphe *> m_observateurs;

    virtual void notifierAjout(const Sommet &n);
    virtual void notifierAjout(const Arete &e);

    virtual void notifierSuppression(const Arete &e);
    virtual void notifierSuppression(const Sommet &n);

    virtual void notifierProprieteChangee(const Sommet &n);
    virtual void notifierProprieteChangee(const Arete &e);

public:
    GrapheObserve() = default;
    virtual ~GrapheObserve() = default;

    virtual void attacher(ObservateurGraphe *observateur);
    virtual void detacher(ObservateurGraphe *observateur);
};


#endif // __GRAPHEOBSERVER_H__