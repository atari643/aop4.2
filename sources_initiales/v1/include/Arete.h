#ifndef ARETE_H  
#define ARETE_H   

#include "Sommet.h"
class Arete {
    private:
        static int last_id;
        int a_id;
        bool valide;
    public:    
        Arete(bool valide = true);
        int id() const;
        bool valid() const;
        bool operator<(const Arete & autre) const;
        bool operator==(const Arete & autre) const;
};  

#endif 