#ifndef STAFF_H
#define STAFF_H

#include "account.h"

class Staff : public Account
{
private:
    string id;
    string sdt;
    string name;

public:
    ~Staff();
    string getId();
    string getSdt();
    string getName();

    void setId(string);
    void setSdt(string);
    void setName(string);
};

#endif
