#ifndef LECTEURS_HPP
#define LECTEURS_HPP

#include <string>

class Lecteur {
public:
    Lecteur(const std::string& nomL, int id);
    std::string getNom();
    void setNom(const std::string& newNom);
    int getId();
    void setId(int newId);
    bool getStatus();
    void setStatus(bool newStatus);

private:
    std::string nom;
    int id;
    bool status;
};

#endif // LECTEURS_HPP