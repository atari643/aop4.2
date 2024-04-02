#ifndef SOMMET_H  
#define SOMMET_H   

class Sommet {
    public:    
        static int last_id;
        int s_id;
        bool valide;
        Sommet(bool valide = true);
        int id() const;
        bool valid() const;

};

#endif 