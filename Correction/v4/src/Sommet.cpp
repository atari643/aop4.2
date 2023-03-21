#include "Sommet.h"

// IdManager Sommet::m_id_manager;
int Sommet::m_dernier_id = 0;

Sommet::Sommet(bool valide) : m_id(valide ? m_dernier_id++ : INVALIDE_ID)
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
