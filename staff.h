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

    friend bool getStaffFromFile(fstream &file, Staff &staff);
    friend void updateStaffToFile(Staff staff);
};
/*------------------------------------Friend------------------------------------*/
bool getStaffFromFile(fstream &file, Staff &staff);
void updateStaffToFile(Staff staff);
/*------------------------------------Other------------------------------------*/
bool dataOfEmptyId(fstream &file, int &count);
int numberFromEmptyIdSt();
int getNumberOfStaff();
void updateNumberOfStaff(int count);
bool checkStaff(Staff &staff);


#endif
