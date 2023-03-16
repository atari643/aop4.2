#include <fstream>
#include <assert.h>
#include <iostream>
#include <vector>

#include "GrapheValue.h"
#include "utils.h"
using namespace std;


bool GrapheValue::charger(std::string fichier) {
    map<unsigned int , Sommet> idSommet;

    // Ajout des sommets
    bool stop = false;
    std::ifstream in(fichier.c_str());
    while (!in.eof() && !stop) {
        char ligne[10000];
        in.getline(ligne, 10000);
        string lignes(ligne);

        if(lignes == "#sommet;position;couleur;etiquette")
            continue;
        else if(lignes == "#aretes"){
            stop = true;
        }
        else {
            vector<string> items;
            decouper(lignes, items, ";");

            if(items.size() != 4) return false;

            int id = stoi(items[0].c_str());
            if(idSommet.find(id) != idSommet.end())
                return false; // deux fois le meme identifiant dans le fichier
            Sommet n = ajouterSommet();
            idSommet[id] = n;

            // position
            string position = items[1];
            vector<string> positions;
            decouper(position, positions, " ");
            if(positions.size() != 2)
                return false;
            Coord pos {stof(positions[0]), stof(positions[1])};
            positionSommet(n, pos);

            // couleur
            string couleur = items[2];
            vector<string> couleurs;
            decouper(couleur, couleurs, " ");
            if(couleurs.size() != 4) return false;

            Couleur col {stoi(couleurs[0]), stoi(couleurs[1]),
                        stoi(couleurs[2]), stoi(couleurs[3])};
            couleurSommet(n, col);

            // etiquette
            etiquetteSommet(n, items[3]);
        }
    }

    // Ajout des aretes
    while (!in.eof()) {
        char ligne[10000];
        in.getline(ligne, 10000);
        string lignes(ligne);

        if(lignes != "") {// derniere ligne "vide"
            vector<string> items;
            decouper (lignes, items, " ");
            if(items.size() != 2) return false;

            int id1 = stoi(items[0]);
            int id2 = stoi(items[1]);

            // test si les id sont corrects
            if(idSommet.find(id1) == idSommet.end() || idSommet.find(id2)==idSommet.end())
                return false;
            Sommet n1 = idSommet[id1];
            Sommet n2 = idSommet[id2];
            ajouterArete(n1,n2);
        }
    }

    return true;
}


Sommet GrapheValue::ajouterSommet(){
    Sommet n = Graphe::ajouterSommet();
    m_positions.changer(n, Coord{});
    m_couleurs.changer(n,COULEUR_DEFAUT);
    m_labels.changer(n,ETIQUETTE_DEFAUT);
  
    notifierAjout(n);
    return n;
}

void GrapheValue::supprimerSommet(const Sommet &n){
    Graphe::supprimerSommet(n);
    m_positions.supprimer(n);
    m_couleurs.supprimer(n);
    m_labels.supprimer(n);

    notifierSuppression(n);
}

void GrapheValue::supprimerArete(const Arete &e){
    Graphe::supprimerArete(e);
    m_couleurs.supprimer(e);
    m_labels.supprimer(e);
    notifierSuppression(e);
}


Arete GrapheValue::ajouterArete(const Sommet &n1, const Sommet & n2) {
    Arete e = Graphe::ajouterArete(n1, n2);
    m_couleurs.changer(e, COULEUR_DEFAUT);
    m_labels.changer(e, ETIQUETTE_DEFAUT);

    notifierAjout(e);
    return e;
}

// Position
void GrapheValue::positionsMinMax(Coord & min, Coord & max){
    min = max = Coord();
    for (auto n : m_sommets){
        Coord c = positionSommet(n);

        if(min == Coord() && max == Coord()){
            min = c;
            max = c;
        }
        else {
            if(c.m_x < min.m_x)
                min.m_x = c.m_x;
            if(c.m_y < min.m_y)
                min.m_y = c.m_y;
            if(c.m_x > max.m_x)
                max.m_x = c.m_x;
            if(c.m_y > max.m_y)
                max.m_y = c.m_y;
        }
    }
}

void GrapheValue::positionSommet(Sommet n, Coord c){
    m_positions.changer(n,c);

    notifierProprieteChangee(n);
}

Coord GrapheValue::positionSommet(Sommet n) const{
    return m_positions.valeur(n);
}

// Couleur
void GrapheValue::couleurSommet(Sommet n, Couleur c){
    m_couleurs.changer(n,c);
    
    notifierProprieteChangee(n);
}

Couleur GrapheValue::couleurSommet(Sommet n){
    return m_couleurs.valeur(n);
}

void GrapheValue::couleurArete(Arete e, Couleur c){
    m_couleurs.changer(e,c);
    
    notifierProprieteChangee(e);
}

Couleur GrapheValue::couleurArete(Arete e){
    return m_couleurs.valeur(e);
}

// Etiquette
void GrapheValue::etiquetteSommet(Sommet n, std::string etiquette){
    m_labels.changer(n,etiquette);
    
    notifierProprieteChangee(n);
}

string GrapheValue::etiquetteSommet(Sommet n) const{
    return m_labels.valeur(n);
}

void GrapheValue::etiquetteArete(Arete e, std::string etiquette){
    m_labels.changer(e,etiquette);
    
    notifierProprieteChangee(e);
}

string GrapheValue::etiquetteArete(Arete e) const{
    return m_labels.valeur(e);
}

Sommet GrapheValue::sommet(const Coord &c, int rayon) {
    Sommet resultat = Sommet(false);
    for(auto n : m_sommets){
        Coord coord = m_positions.valeur(n);
        float dist = (c.m_x-coord.m_x)*(c.m_x-coord.m_x) + (c.m_y-coord.m_y)*(c.m_y-coord.m_y);
        if(dist < rayon * rayon){
            resultat = n;
        }
    }
    return resultat;
}
