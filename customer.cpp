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

bool checkCustomer(Customer &customer)
{
    string filename = "./customer/listCustomer.txt";
    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }

    Customer temp;
    while (getObjectFromFile(file, temp))
    {
        if (temp.getName() == customer.getName())
        {
            customer = temp;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool operator>>(istream &in, Customer &customer)
{
    cout << "Nhập tên khách hàng: ";
    in >> customer.name;
    if (checkCustomer(customer))
    {
        cout << "Khách hàng đã tồn tại!" << endl;
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

        cout << "Nhập số điện thoại: ";
        in >> customer.sdt;
        cout << "Nhập email: ";
        in >> customer.email;
        customer.contribute = "0";
    }
    return true;
}

/*------------------------------------Other------------------------------------*/


