#ifndef ARETE_H
#define ARETE_H

#include "IdManager.h"

class Arete
{
private :
    static IdManager m_id_manager;
    int m_id;

public:
    Arete(bool valide = true);
    
    int id() const;
    bool valide() const;
    bool operator<(const Arete &e) const;
    bool operator==(const Arete &e) const;
};

#endif // ARETE_H
