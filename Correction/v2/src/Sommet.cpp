#include "Sommet.h"

IdManager Sommet::m_id_manager;

Sommet::Sommet(bool valide) : m_id(valide ? m_id_manager.obtenir() : -1)
{
}

int Sommet::id() const
{
    return m_id;
}

bool Sommet::valide() const
{
    return (m_id != -1);
}

bool Sommet::operator<(const Sommet &n) const
{
    return m_id < n.m_id;
}

bool Sommet::operator==(const Sommet &n) const{
    return m_id == n.m_id;
}
