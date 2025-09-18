#include <vector>
#include <string>
#include "Lecteurs.hpp"

    Lecteur::Lecteur(const std::string& nom, int id){
        this->nom = nom;
        this->id = id;
        status = 0;
    }
    std::string Lecteur::getNom() { return nom; }
    void Lecteur::setNom(const std::string& newNom) { nom = newNom; }
    int Lecteur::getId() { return id; }
    void Lecteur::setId(int newId) { id = newId; }
    bool Lecteur::getStatus() { return status; }
    void Lecteur::setStatus(bool newStatus) { status = newStatus; }