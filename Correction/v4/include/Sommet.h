#ifndef NOEUD_H
#define NOEUD_H


class Sommet
{
private:
    static const int INVALIDE_ID = -1;
    static int m_dernier_id;
    int m_id;

public:
    Sommet(bool valide = true);
    int id() const;

    bool valide() const;
    bool operator<(const Sommet &n) const;
    bool operator==(const Sommet &n) const;
};

#endif
