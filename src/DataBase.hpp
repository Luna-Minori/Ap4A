#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "sqlite_orm/sqlite_orm.h"
#include "User.hpp"
#include "Badge.hpp"
#include "Lecteurs.hpp"
#include "Salle.hpp"
#include "Batiment.hpp"
#include <sqlite3.h>
#include <optional>
#include <string>
#include <vector>

//Table de LIAISON
struct UserBadge { int id; int user_id; int badge_id; };
struct LecteurSalle { int id; int lecteur_id; int salle_id; };
struct SalleBatiment { int id; int salle_id; int batiment_id; };

using namespace sqlite_orm;

inline auto make_db_storage(const std::string &filename = "example.db") {
    return make_storage(filename,
    make_table("users",
        make_column("id", &User::setId, &User::getId, primary_key()),
        make_column("name", &User::getName, &User::setName),
        make_column("age", &User::getAge, &User::setAge)
        ),
        make_table<Badge>("badges",
            make_column("id", &Badge::getId, &Badge::setId, primary_key()),
            make_column("status", &Badge::getStatus, &Badge::setStatus)
        ),
        make_table("user_badges",
            make_column("user_id", &UserBadge::user_id),
            make_column("badge_id", &UserBadge::badge_id),
            primary_key(&UserBadge::user_id, &UserBadge::badge_id)
        ),
        make_table<Batiment>("batiments",
            make_column("id", &Batiment::getId, &Batiment::setId, primary_key()),
            make_column("nom", &Batiment::getNom, &Batiment::setNom),
            make_column("nb_salles", &Batiment::getNbSalles, &Batiment::setNbSalles)
        ),
        make_table<Salle>("salles",
            make_column("id", &Salle::getId, &Salle::setId, primary_key()),
            make_column("nom", &Salle::getNom, &Salle::setNom),
            make_column("nb_lecteurs", &Salle::getNbLecteurs, &Salle::setNbLecteurs)
        ),
        make_table<Lecteur>("lecteurs",
            make_column("id", &Lecteur::setId,&Lecteur::getId, primary_key()),
            make_column("nom", &Lecteur::getNom, &Lecteur::setNom),
            make_column("status", &Lecteur::setStatus, &Lecteur::getStatus)
        ),
        make_table<LecteurSalle>("lecteur_salle",
            make_column("lecteur_id", &LecteurSalle::lecteur_id),
            make_column("salle_id", &LecteurSalle::salle_id),
            primary_key(&LecteurSalle::lecteur_id, &LecteurSalle::salle_id)
        ),
        make_table<SalleBatiment>("salle_batiment",
            make_column("salle_id", &SalleBatiment::salle_id),
            make_column("batiment_id", &SalleBatiment::batiment_id),
            primary_key(&SalleBatiment::salle_id, &SalleBatiment::batiment_id)
        )
    );
}

using Storage = decltype(make_db_storage());

class Database {
public:
    explicit Database(const std::string &dbfile = "example.db", bool authorized = false);

    void set_authorized(bool v);

    int add_user(const User &u);
    int add_badge(const Badge &b);
    int link_user_badge(int user_id, int badge_id);
    int add_batiment(const Batiment &b);
    int add_salle(const Salle &s);
    int add_lecteur(const Lecteur &l);
    int link_lecteur_salle(int lecteur_id, int salle_id);
    int link_salle_batiment(int salle_id, int batiment_id);

    std::optional<User> get_user_by_id(int id);
    std::optional<std::vector<Badge>> get_badges_for_user(int user_id);
    std::optional<std::vector<Lecteur>> get_lecteurs_for_salle(int salle_id);

    UserBadge userBadge(User user, Badge badge);
    SalleBatiment salleBatiment(Salle s, Batiment b);
    LecteurSalle lecteurSalle(Lecteur L, Salle s);

private:
    Storage storage_;
    bool is_authorized_;
};



#endif // DATABASE_HPP