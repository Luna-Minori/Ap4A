#ifndef SALLE_HPP
#define SALLE_HPP

#include <string>
#include "Lecteurs.hpp"
#include "Groups.hpp"


class Salle {
public:
    Salle::Salle(const std::string& nomSalle, int nbLecteur, std::vector<Groups> groupe);
    std::string getNom();
    void setNom(const std::string& newNom);
    int getId();
    void setId(int newId);
    int getNbLecteurs();
    void setNbLecteurs(int newNbLecteurs);
    void setLecteurs(std::vector<Lecteur> newLecteurs);
    std::vector<Lecteur> getLecteurs();
    

private:
    std::string nom;
    int id;
    int nbLecteurs;
    std::vector<Lecteur> lecteurs;
};
#endif // SALLE_HPP