#ifndef GROUPS_HPP
#define GROUPS_HPP

#include <vector>
#include <string>
#include <algorithm>
#include "User.hpp"
#include "Salle.hpp"

class Groups {

protected:
    std::string name;
    std::vector<User> members;
    std::vector<Salle> Permission;
public:
    Groups(std::string groupName);
    void addMember(User user);
    void removeMember(User user);
    std::string getName();
    std::vector<User> getMembers();
};
#endif // GROUPS_HPP