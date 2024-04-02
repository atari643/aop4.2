#include <iostream> // permet d'afficher dans le terminal

#include "Sommet.h" // on inclut la déclaration de classe

using namespace std; // l'espace de nom standard contient un grnad nombre de fonctionnalités 

int Sommet::last_id = 0; // si vous avez déclaré un attibut static 
Sommet::Sommet(bool valide){
    this->valide = valide;
}
int Sommet::id() const{
    return s_id;

}
bool Sommet::valid() const {
    return valide;
}