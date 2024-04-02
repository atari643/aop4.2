#include <iostream> // permet d'afficher dans le terminal

#include "Arete.h" // on inclut la déclaration de classe

using namespace std; // l'espace de nom standard contient un grnad nombre de fonctionnalités 

int Arete::last_id = 0; // si vous avez déclaré un attibut static 
Arete::Arete(bool valide){
    if(valide){
        a_id = last_id;
        last_id++;
    }
}
int Arete::id() const{
    return a_id;

}
bool Arete::valid() const {
    return valide;
}
bool Arete::operator<(const Arete & autre) const {
    if(a_id < autre.id()){
        return true;
    }else{
        return false;
    }
}
bool Arete::operator==(const Arete & autre) const {
    if(a_id == autre.id()){
        return true;
    }else{
        return false;
    }
}
