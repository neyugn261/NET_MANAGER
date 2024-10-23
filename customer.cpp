#include "function.h"
#include "customer.h"

Customer::~Customer() {}
string Customer::getId() { return id; }
string Customer::getName() { return name; }
string Customer::getSdt() { return sdt; }
string Customer::getEmail() { return email; }
string Customer::getContribute() { return contribute; }
void Customer::setId(string id) { this->id = id; }
void Customer::setName(string name) { this->name = name; }
void Customer::setSdt(string sdt) { this->sdt = sdt; }
void Customer::setEmail(string email) { this->email = email; }
void Customer::setContribute(string contribute) { this->contribute = contribute; }

/*------------------------------------Friend------------------------------------*/

bool operator>>(istream &in, Customer &customer)
{   
    ClearLine(42, 3, 30);
    Gotoxy(42,3);
    EnterString(customer.name, 25);
    toName(customer.name);
    if (checkNameObject(customer))
    {
        Sleep(200);
        ShowCursor(false);
        Gotoxy(26, 7);
        cout << "Khách hàng đã tồn tại" << endl;
        Sleep(700);
        ClearLine(26, 7, 20);
        return false;
    }
    else
    {
        int id = numberFromEmptyId("./customer/emptyID.txt");
        if (id == -1)
        {
            id = getNumber("./customer/customerID.txt");
            id++;
            updateNumber("./customer/customerID.txt", id);
        }
        stringstream ss;
        ss << setw(3) << setfill('0') << id;
        customer.id = "C" + ss.str();

        ClearLine(46, 4, 10);
        Gotoxy(46, 4);
        EnterNumber(customer.sdt, 10,10);
        ClearLine(38, 5, 35);
        Gotoxy(38, 5);
        EnterString(customer.email, 35);
        customer.contribute = "0";
    }
    return true;
}
    


/*------------------------------------Other------------------------------------*/
