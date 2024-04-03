#include "Appli.h"
#include "GrapheObserve.h"
using namespace std;
// Implement the member functions here

void GrapheObserve::notifierAjout(const Sommet &n)
{
    // Notify all observers that a node has been added
    for (auto observateur : m_observateurs)
    {
        observateur->traiterAjout(n);
    }
}

void GrapheObserve::notifierAjout(const Arete &e)
{
    // Notify all observers that an edge has been added
    for (auto observateur : m_observateurs)
    {
        observateur->traiterAjout(e);
    }
}

void GrapheObserve::notifierSuppression(const Arete &e)
{
    for (auto observateur : m_observateurs)
    {
        observateur->traiterSuppression(e);
    }
}

void GrapheObserve::notifierSuppression(const Sommet &n)
{
    for (auto observateur : m_observateurs)
    {
        observateur->traiterSuppression(n);
    }

}

void GrapheObserve::notifierProprieteChangee(const Sommet &n)
{
    for (auto observateur : m_observateurs)
    {
        observateur->traiterProprieteChangee(n);
    }

}

void GrapheObserve::notifierProprieteChangee(const Arete &e)
{
    for (auto observateur : m_observateurs)
    {
        observateur->traiterProprieteChangee(e);
    }

}

void GrapheObserve::attacher(ObservateurGraphe *observateur)
{
    // Add the observer to the collection
    m_observateurs.insert(observateur);
}

void GrapheObserve::detacher(ObservateurGraphe *observateur)
{
    // Remove the observer from the collection
    m_observateurs.erase(observateur);
}
