#include "function.h"
#include "staff.h"

Staff::~Staff() {};
string Staff::getId() { return id; }
string Staff::getSdt() { return sdt; }
string Staff::getName() { return name; }
string Staff::getRevenue() { return revenue; }
void Staff::setId(string id) { this->id = id; }
void Staff::setSdt(string sdt) { this->sdt = sdt; }
void Staff::setName(string name) { this->name = name; }
void Staff::setRevenue(string revenue) { this->revenue = revenue; }

/*------------------------------------Friend------------------------------------*/
bool operator>>(istream &in, Staff &staff)
{
    ClearLine(51, 3, 30);
    Gotoxy(51, 3);
    EnterString(staff.name, 30);
    toName(staff.name);
    if (checkNameObject(staff))
    {
        Sleep(200);
        ShowCursor(false);
        Gotoxy(26, 8);
        cout << "Nhân viên đã tồn tại" << endl;
        Sleep(700);
        ClearLine(26, 8, 20);
        return false;
    }
    else
    {
        int id = numberFromEmptyId("./account/emptyID.txt");
        if (id == -1)
        {
            id = getNumber("./account/staffID.txt");
            id++;
            updateNumber("./account/staffID.txt", id);
        }
        stringstream ss;
        ss << setw(3) << setfill('0') << id;
        staff.id = "S" + ss.str();

        ClearLine(51, 4, 10);
        Gotoxy(51, 4);
        EnterNumber(staff.sdt, 10, 10);
        do
        {
            ClearLine(47, 5, 30);
            Gotoxy(47, 5);
            EnterString(staff.aname, 30);
            if(checkAname(staff.aname))
            {   
                ShowCursor(false);
                Sleep(200);
                Gotoxy(26, 8);
                cout << "Tài khoản đã tồn tại";
                Sleep(700);
                ClearLine(26, 8, 20);
                ShowCursor(true);
            }
        }while(checkAname(staff.aname));
        ClearLine(47, 6, 30);
        Gotoxy(46, 6);
        EnterString(staff.password, 30);
        staff.role = "staff";
        staff.revenue = "0";
        staff.status = "OFFLINE";
    }
    return true;
}

/*------------------------------------Other------------------------------------*/
