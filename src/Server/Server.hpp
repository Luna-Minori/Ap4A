#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <string>
#include "../People/User.hpp"
//#include "../Structure/Batiments.hpp"
#include "../Groups/Groups.hpp"
#include <iostream>
#include <fstream>

class Server {

private:
    int nbLigne(std::ifstream &fichier);
protected:
    std::string nom;
    bool running;

public:
    Server(const std::string& nom);
    void start();
    void stop();
    bool isRunning();
    int addUser(User user, Groups group);
    bool OpenDoor(Badge badge, Lecteur L);
};

#endif // SERVER_HPP