#ifndef USER_HPP
#define USER_HPP
#include "Badge.hpp"

class User {
public:
    User(const std::string& name, int *id, int age, Badge *badge=nullptr);
    User(const std::string& name, int age, Badge *badge=nullptr);
    int getId();
    std::string getName();
    int getAge();
    Badge getBadge();
    void setId(int *newId);
    void setName(std::string& newName);
    void setAge(int newAge);
private:
    std::string name;
    int *id;
    int age;
    Badge *badge;
};      
#endif // USER_HPP