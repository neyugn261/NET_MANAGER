#ifndef STAFF_H
#define STAFF_H

#include "account.h"

class Staff : public Account
{
private:
    string id;
    string sdt;
    string name;
    string revenue;

public:
    ~Staff();
    string getId();
    string getSdt();
    string getName();
    string getRevenue();

    void setId(string);
    void setSdt(string);
    void setName(string);
    void setRevenue(string);

    friend bool operator>>(istream &in, Staff &staff);
};
/*------------------------------------Friend------------------------------------*/
bool operator >> (istream & in, Staff &staff);
/*------------------------------------Other------------------------------------*/

#endif
