#ifndef SOMMET_H  
#define SOMMET_H   

class Sommet {
    private:
        static int last_id;
        int s_id;
        bool valide;
    public:    
        Sommet(bool valide = true);
        int id() const;
        bool valid() const;
        bool operator<(const Sommet & autre) const;
        bool operator==(const Sommet & autre) const;
};

#endif 