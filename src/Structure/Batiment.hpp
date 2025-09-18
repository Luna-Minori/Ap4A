#ifndef BATIMENTS_HPP
#define BATIMENTS_HPP

#include <string>
#include <vector>
#include "Salle.hpp"

class Batiment {
public:
    Batiment(int nb_salles);
    int getNbSalles(); 
    void setNbSalles(int newNbSalles);
    int getId();
    void setId(int newId);
    std::string getNom();
    void setNom(std::string& newNom);
private :
    int id;
    int nbSalles;
    std::string nom;
    std::vector<Salle> salles;
};


#endif // BATIMENTS_HPP