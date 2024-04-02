#ifndef __COULEUR_H__
#define __COULEUR_H__


class Couleur {
    private:
        int r;
        int g;
        int b;
        int a;
    public:
        Couleur();
        Couleur(int r, int g, int b, int a);
        Couleur interpoler(const Couleur &c, float valeur);
        const int& operator[](int canal) const;
        int& operator[](int canal);
        bool operator==(const Couleur & c) const;
};

#endif // __COULEUR_H__