#include "function.h"
#include "staff.h"


Staff::~Staff() {};
string Staff::getId() { return id; }
string Staff::getSdt() { return sdt; }
string Staff::getName() { return name; }
void Staff::setId(string id) { this->id = id; }
void Staff::setSdt(string sdt) { this->sdt = sdt; }
void Staff::setName(string name) { this->name = name; }

/*------------------------------------Friend------------------------------------*/


void updateStaffToFile(Staff staff)
{
    fstream file1("./account/listStaff.txt", ios::in);
    fstream temp1("./account/temp1.txt", ios::out);
    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    Staff tempStaff;
    while(getObjectFromFile(file1, tempStaff)){
        if(tempStaff.getAname() == staff.getAname()){
            tempStaff = staff;
        }
        temp1 << tempStaff.getId() << "|" << tempStaff.getAname() << "|" << tempStaff.getPass() << "|" << tempStaff.getRole() << "|" << tempStaff.getStatus() << "|" << tempStaff.getName() << "|" << tempStaff.getSdt() << endl;
    }
    file1.close();
    temp1.close();
    system("del .\\account\\listStaff.txt");
    system("ren .\\account\\temp1.txt listStaff.txt");

    fstream file2("./account/listAccount.txt", ios::in);
    fstream temp2("./account/temp2.txt", ios::out);
    if (!file2.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp2.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    Account tempAccount;
    while (getObjectFromFile(file2, tempAccount))
    {
        if (tempAccount.getAname() == staff.getAname())
        {
            tempAccount.setPass(staff.getPass());
            tempAccount.setRole(staff.getRole());
            tempAccount.setStatus(staff.getStatus());
        }
        temp2 << tempAccount.getAname() << "|" << tempAccount.getPass() << "|" << tempAccount.getRole() << "|" << tempAccount.getStatus() << endl;
    }
    file2.close();
    temp2.close();
    system("del .\\account\\listAccount.txt");
    system("ren .\\account\\temp2.txt listAccount.txt");     
    
}
/*------------------------------------Other------------------------------------*/


