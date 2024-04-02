#include <iostream> // permet d'afficher dans le terminal

#include "Arete.h" // on inclut la déclaration de classe

using namespace std; // l'espace de nom standard contient un grnad nombre de fonctionnalités 

int Arete::last_id = 0; // si vous avez déclaré un attibut static 
Arete::Arete(bool valide){
    this->valide = valide;
}
int Arete::id() const{
    return s_id;

}
bool Arete::valid() const {
    return valide;
}