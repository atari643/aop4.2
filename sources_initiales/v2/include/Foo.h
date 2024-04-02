#ifndef FOO_H   // <--- garde, permet de ne pas déclarer la classe plusieurs fois lors d'inclusion multiples
#define FOO_H   // on définit FOO_H afin de ne plus redéfinir la classe

class Foo {
    public:    // les méthodes et attibuts en dessous sont publiques

        Foo();   // le constructeur porte le nom de la classe
        void bar(); 

    private:  // les méthodes et attributs en dessous sont privés

        // un attribut
        int m_attr1;

        //une méthode
        void methodePrivee(); // on utilise le camel case
};

#endif  // "ferme" ifndef