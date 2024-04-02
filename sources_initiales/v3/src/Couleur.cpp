#include "Couleur.h"

using namespace std;
Couleur::Couleur() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

Couleur::Couleur(int r, int g, int b, int a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;

}

Couleur Couleur::interpoler(const Couleur &c, float valeur) {
    return Couleur(
        this->r + (c.r - this->r) * valeur,
        this->g + (c.g - this->g) * valeur,
        this->b + (c.b - this->b) * valeur,
        this->a + (c.a - this->a) * valeur
    );
}

const int& Couleur::operator[](int canal) const {
    return canal == 0 ? this->r : canal == 1 ? this->g : canal == 2 ? this->b : this->a;
}

int& Couleur::operator[](int canal) {
    return canal == 0 ? this->r : canal == 1 ? this->g : canal == 2 ? this->b : this->a;
}

bool Couleur::operator==(const Couleur &c) const {
    return this->r == c.r && this->g == c.g && this->b == c.b && this->a == c.a;
}
