#include "DataBase.hpp"
#include <iostream>

Database::Database(const std::string &dbfile, bool authorized)
    : storage_(make_db_storage(dbfile)), is_authorized_(authorized)
{
    storage_.sync_schema(); // crée les tables si besoin
}



void Database::set_authorized(bool v) { is_authorized_ = v; }

int Database::add_user(const User &u) { return storage_.insert(u); }
int Database::add_badge(const Badge &b) { return storage_.insert(b); }
int Database::link_user_badge(int user_id, int badge_id){return storage_.insert(UserBadge{0, user_id, badge_id});}
int Database::add_batiment(const Batiment &b) { return storage_.insert(b); }
int Database::add_salle(const Salle &s) { return storage_.insert(s); }
int Database::add_lecteur(const Lecteur &l) { return storage_.insert(l); }
int Database::link_lecteur_salle(int lecteur_id, int salle_id){return storage_.insert(LecteurSalle{0, lecteur_id, salle_id});}
int Database::link_salle_batiment(int salle_id, int batiment_id){return storage_.insert(SalleBatiment{0, salle_id, batiment_id});}

// getters protégés
std::optional<User> Database::get_user_by_id(int id)
{
    if (!is_authorized_)
        return std::nullopt;
    try
    {
        return storage_.get<User>(id);
    }
    catch (...)
    {
        return std::nullopt;
    }
}

std::optional<std::vector<Badge>> Database::get_badges_for_user(int user_id)
{
    if (!is_authorized_)
        return std::nullopt;

    auto rows = storage_.select(columns(&UserBadge::badge_id), where(c(&UserBadge::user_id) == user_id));

    std::vector<Badge> out;

    for (auto &r : rows)
    {
        int bid = std::get<0>(r);
        try
        {
            out.push_back(storage_.get<Badge>(bid));
        }
        catch (...)
        {
        }
    }
    return out;
}

std::optional<std::vector<Lecteur>> Database::get_lecteurs_for_salle(int salle_id)
{
    if (!is_authorized_)
        return std::nullopt;

    auto rows = storage_.select(columns(&LecteurSalle::lecteur_id), where(c(&LecteurSalle::salle_id) == salle_id));

    std::vector<Lecteur> out;
    for (auto &r : rows)
    {
        int lid = std::get<0>(r);
        try
        {
            out.push_back(storage_.get<Lecteur>(lid));
        }
        catch (...)
        {
        }
    }
    return out;
}

UserBadge userBadge(User user, Badge badge){
    return UserBadge{0, user.getId(), badge.getId()};
}

SalleBatiment salleBatiment(Salle s, Batiment b){
    return SalleBatiment{0, s.getId(), b.getId()};
}

LecteurSalle lecteurSalle(Lecteur L, Salle s){
    return LecteurSalle{0, L.getId(), s.getId()};
}
