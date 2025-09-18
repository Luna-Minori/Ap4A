
#include <string>
#include "User.hpp"


User::User(const std::string& name, int *id, int age, Badge *badge=nullptr){
    this->name = name;
    this->id = id;
    this->age = age;
    this->badge = badge;
};

User::User(const std::string& name, int age, Badge *badge=nullptr){
    this->name = name;
    this->age = age;
    this->badge = badge;
    this->id = nullptr;
};

int User::getId() { return *id; }
std::string User::getName() { return name; }
int User::getAge() { return age; }
Badge User::getBadge() { return *badge; }
void User::setId(int *newId) { id = newId; }
void User::setName(std::string& newName) { name = newName; }
void User::setAge(int newAge) { age = newAge; }