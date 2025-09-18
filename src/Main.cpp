#include <iostream>
#include "People/User.hpp"
#include "People/Badge.hpp"
#include "DataBase.hpp"
#include <string>


int main() {
    std::cout << "Hello, World!" << std::endl;
    Database db("Ap4A.db", true); // stockage autorisé

    // --- Création de 3 users ---
    User u1("Alice", 20);
    User u2("Bob", 22);
    User u3("Charlie", 25);

    int id1 = db.add_user(u1);
    int id2 = db.add_user(u2);
    int id3 = db.add_user(u3);

    std::cout << "Users insérés avec IDs : " 
              << id1 << ", " << id2 << ", " << id3 << std::endl;
    u1.setId(&id1);
    u2.setId(&id2);
    u3.setId(&id3);


    /* --- Création d’un bâtiment ---
    Batiment b1("Batiment A", 0); // 0 salles au départ
    int bid = db.add_batiment(b1);
    std::cout << "Batiment inséré avec ID : " << bid << std::endl;

    // --- Création d’une salle ---
    Salle s1("Salle 101", 0); // 0 lecteurs au départ
    int sid = db.add_salle(s1);
    std::cout << "Salle insérée avec ID : " << sid << std::endl;

    // --- Lier la salle au bâtiment ---
    db.link_salle_batiment(sid, bid);
    std::cout << "Salle " << sid << " liée au bâtiment " << bid << std::endl;*/

    return 0;
}