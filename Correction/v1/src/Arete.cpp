#include "Arete.h"

// IdManager Arete::m_id_manager;
int Arete::m_dernier_id = 0;

Arete::Arete(bool valide) : m_id(valide ? m_dernier_id++ : INVALIDE_ID)
{}

int Arete::id() const {
    return m_id;
}

bool Arete::valide() const{
    return (m_id != INVALIDE_ID);
}

bool Arete::operator<(const Arete &e) const {
    return m_id < e.m_id;
}

bool Arete::operator==(const Arete &e) const{
    return m_id == e.m_id;
}

