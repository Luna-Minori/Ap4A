#ifndef BADGE_HPP
#define BADGE_HPP

#include <string>

class Badge {
private:
    int id;
    bool status;

public:
    Badge(int id);
    int getId();
    void setId(int newId);
    bool getStatus();
    void setStatus(bool newStatus);
};
#endif // BADGE_HPP