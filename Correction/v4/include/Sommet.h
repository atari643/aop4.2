#ifndef NOEUD_H
#define NOEUD_H

#include "IdManager.h"

class Sommet
{
private :
    static IdManager m_id_manager;
    int m_id;
public:
    Sommet(bool valide = true);
    int id() const;

    bool valide() const;
    bool operator<(const Sommet &n) const;
    bool operator==(const Sommet &n) const;
  
};

#endif
