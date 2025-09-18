#include <vector>
#include <string>
#include "Batiments.hpp"


Batiment::Batiment(const std::string& nom) : nom_(nom) {}


void Batiment::ajouterSalle(const Salle& salle) {
    salles_.push_back(salle);
}
    
const std::vector<Salle>& getSalles() const { return salles_; }

void Batiment::setNbSalles(int newNbSalles) {}

std::string getNom() const { return nom_; }

void Batiment::setNom(const std::string& newNom) { nom_ = newNom; }

int Batiment::getId() const { return id_; }

void Batiment::setId(int newId) { id_ = newId; }

int Batiment::getNbSalles() const { return salles_.size(); }

void Batiment::setNbSalles(int newNbSalles) { nbSalles_ = newNbSalles; }



