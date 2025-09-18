
#include <string>
#include <vector>
#include "Server/Lecteurs.hpp"
#include "Groups.hpp"
#include "Salle.hpp"

Salle::Salle(const std::string& nomSalle, int nbLecteur, std::vector<Groups> groupe){
        nom = nomSalle;
        for(int i=0; i<nbLecteur; i++){
            std::string nomL = "Lecteur " + std::to_string(i+1);
            Lecteur lecteur(nomL, i+1);
            lecteurs.push_back(lecteur);
        }
    }

std::string Salle::getNom() { return nom; }
void Salle::setNom(const std::string& newNom) { nom = newNom; }
int Salle::getId() { return id; }
void Salle::setId(int newId) { id = newId; }
int Salle::getNbLecteurs() { return nbLecteurs; }
void Salle::setNbLecteurs(int newNbLecteurs) { nbLecteurs = newNbLecteurs; }
void Salle::setLecteurs(std::vector<Lecteur> newLecteurs) { lecteurs = newLecteurs; }
std::vector<Lecteur> Salle::getLecteurs() { return lecteurs; }

    