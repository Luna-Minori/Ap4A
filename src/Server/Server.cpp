#include "Server.hpp"

Server::Server(const std::string &nom)
{
    this->nom = nom;
    running = false;
}

void Server::start()
{
    running = true;
    std::cout << "Server started" << std::endl;
}

void Server::stop()
{
    running = false;
    std::cout << "Server stopped." << std::endl;
}

bool Server::isRunning()
{
    return running;
}
/*
int Server::nbLigne(std::ifstream &fichier)
{

    int nbLigne = 0;
    std::string ligne;
    if (!fichier)
    {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return -1;
    }

    while (std::getline(fichier, ligne))
    {
        nbLigne++;
    }
    fichier.close();
    return nbLigne;
}

int Server::addUser(User user, Groups group)
{
    std::ifstream fichierLecture("DataBase.txt");
    int nbLigneCount = nbLigne(fichierLecture);
    fichierLecture.close();

    std::ofstream fichierEcriture("DataBase.txt", std::ios::app);

    if (!fichierEcriture)
    {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return -1;
    }

    fichierEcriture << user.getBadge().getId() << ";"
                    << user.getBadge().getStatus() << ";"
                    << user.getId() << ";"
                    << user.getName() << ";"
                    << user.getAge() << ";"
                    << group.getName()
                    << std::endl;
    fichierEcriture.close();

    fichierEcriture.close();
    group.addMember(user);
    std::cout << "User added to the database." << std::endl;
    return 0;
}

int findFile(const std::string &filename, int id, std::string &groupName)
{
    std::ifstream fichierLecture(filename);
    std::string ligne;
    int i = 0;
    int j = 0;

    if (!fichierLecture)
    {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return -1;
    }

    while (std::getline(fichierLecture, ligne))
    {
        size_t pos = ligne.find(';');           
        std::string idStr = ligne.substr(0, pos); // coupe la chaine pour badge ID  

        if(to_integer(idStr) == id) {
            std::string nextStr = ligne.substr(pos + 1); // suite de la chaine
            while (nextStr[i] != ';' && i < nextStr.length()) {
                i++; //on cherche le prochain ';' qui est le debut de ID utilisateur
            }

            j = i + 1;
            while (nextStr[j] != ';' && j < nextStr.length()) {
                j++; //on cherche la fin de ID utilisateur
            }
            

        }
  
    }
    fichierLecture.close();
}
/*
bool Server::OpenDoor(Badge badge, Lecteur L)
{
    if (badge.getStatus() == false)
    {
        std::cout << "Access denied. Badge inactive." << std::endl;
        return false;
    }

    find()*/
