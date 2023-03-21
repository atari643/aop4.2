#ifndef ARETE_H
#define ARETE_H

class Arete
{
private:
    static const int INVALIDE_ID = -1;
    static int m_dernier_id;
    int m_id;

public:
    Arete(bool valide = true);

    int id() const;
    bool valide() const;
    bool operator<(const Arete &e) const;
    bool operator==(const Arete &e) const;
};

#endif // ARETE_H
