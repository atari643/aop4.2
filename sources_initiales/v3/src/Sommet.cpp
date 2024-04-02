#include <iostream> // permet d'afficher dans le terminal

#include "Sommet.h" // on inclut la déclaration de classe

using namespace std; // l'espace de nom standard contient un grnad nombre de fonctionnalités 

int Sommet::last_id = 0; // si vous avez déclaré un attibut static 
Sommet::Sommet(bool valide){
    if(valide){
        s_id = last_id;
        last_id++;
    }else{
        s_id=-1;
    }
}
int Sommet::id() const{
    return s_id;

}
bool Sommet::valid() const {
    return valide;
}
bool Sommet::operator<(const Sommet & autre) const {
    if(s_id < autre.id()){
        return true;
    }else{
        return false;
    }
}
bool Sommet::operator==(const Sommet & autre) const {
    if(s_id == autre.id()){
        return true;
    }else{
        return false;
    }
}