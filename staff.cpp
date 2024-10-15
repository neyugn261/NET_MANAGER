#include "staff.h"

Staff::~Staff() {};
string Staff::getId() { return id; }
string Staff::getSdt() { return sdt; }
string Staff::getName() { return name; }
void Staff::setId(string id) { this->id = id; }
void Staff::setSdt(string sdt) { this->sdt = sdt; }
void Staff::setName(string name) { this->name = name; }