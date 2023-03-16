#include "GrapheObserve.h"

using namespace std;

GrapheObserve::GrapheObserve() : m_observateurs_arretes(false) {}

void GrapheObserve::notifierAjout(const Sommet &n)
{
    if (m_observateurs_arretes)
        return;
    for (ObservateurGraphe *obs : m_observateurs)
    {
        obs->traiterAjout(n);
    }
}

void GrapheObserve::notifierAjout(const Arete &e)
{

    if (m_observateurs_arretes)
        return;
    for (ObservateurGraphe *obs : m_observateurs)
    {
        obs->traiterAjout(e);
    }
}

void GrapheObserve::notifierSuppression(const Arete &e)
{

    if (m_observateurs_arretes)
        return;
    for (ObservateurGraphe *obs : m_observateurs)
    {
        obs->traiterSuppression(e);
    }
}
void GrapheObserve::notifierSuppression(const Sommet &n)
{

    if (m_observateurs_arretes)
        return;
    for (ObservateurGraphe *obs : m_observateurs)
    {
        obs->traiterSuppression(n);
    }
}

void GrapheObserve::notifierProprieteChangee(const Sommet &n)
{

    if (m_observateurs_arretes)
        return;
    for (ObservateurGraphe *obs : m_observateurs)
    {
        obs->traiterProprieteChangee(n);
    }
}
void GrapheObserve::notifierProprieteChangee(const Arete &e)
{
    if (m_observateurs_arretes)
        return;
    for (ObservateurGraphe *obs : m_observateurs)
    {
        obs->traiterProprieteChangee(e);
    }
}

void GrapheObserve::attacher(ObservateurGraphe *observateur)
{
    m_observateurs.insert(observateur);
}

void GrapheObserve::detacher(ObservateurGraphe *observateur)
{
    if (m_observateurs.find(observateur) != m_observateurs.end())
    {
        m_observateurs.erase(observateur);
    }
}

void GrapheObserve::arreteObservation()
{
    m_observateurs_arretes = true;
}

void GrapheObserve::demarrerObservation()
{
    m_observateurs_arretes = false;
    for (ObservateurGraphe *obs : m_observateurs)
    {
        obs->traiterMiseAJourCompelete();
    }
}