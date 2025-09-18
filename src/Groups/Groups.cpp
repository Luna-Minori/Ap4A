#include "Groups.hpp"

Groups::Groups(std::string groupName) : name(groupName) {}

void Groups::addMember(User user)
{
    members.push_back(user);
}

void Groups::removeMember(User user)
{
    members.erase(
        std::remove(members.begin(), members.end(), user),
        members.end());
}

std::string Groups::getName()
{
    return name;
}

std::vector<User> Groups::getMembers()
{
    return members;
}
