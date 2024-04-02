#include <iostream> // permet d'afficher dans le terminal

#include "Foo.h" // on inclut la déclaration de classe

using namespace std; // l'espace de nom standard contient un grnad nombre de fonctionnalités 

// on doit préfixer le nom de chaque méthode par le nom de la classe:: sinon le compilateur n'a aucun moyen
// de savoir qu'il s'agit d'une méthode de cette classe
Foo::Foo(){
    m_attr1 = 10;
}

void Foo::bar() {
    cout << "valeur attribut " << m_attr1 << endl; // sans "using namespace std;", il faudrait spécifier que
                                                   // cout et endl sont ceux définis dans std. 
                                                   // Il fautdrait alors écrire :
                                                   // std::cout << "valeur attribut " << m_attr1 << std::endl;
}

void Foo::methodePrivee(){
    cout << "inutile" << endl;
}
