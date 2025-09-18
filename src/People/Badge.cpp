
#include "Badge.hpp"


Badge::Badge(int id){
    this->id = id;
    status = true;
}

int Badge::getId() { return id; }
bool Badge::getStatus() { return status; }
void Badge::setStatus(bool newStatus) { status = newStatus; }
void Badge::setId(int newId) { id = newId; }
