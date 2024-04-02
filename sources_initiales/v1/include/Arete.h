#ifndef ARETE_H  
#define ARETE_H   

class Arete {
    public:    
        static int last_id;
        int s_id;
        bool valide;
        Arete(bool valide = true);
        int id() const;
        bool valid() const;

};

#endif 