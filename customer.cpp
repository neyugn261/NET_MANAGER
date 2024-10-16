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

bool getCustomerFromFile(fstream &file, Customer &customer)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;
    stringstream ss(line);
    getline(ss, customer.id, '|');
    getline(ss, customer.name, '|');
    getline(ss, customer.sdt, '|');
    getline(ss, customer.email, '|');
    getline(ss, customer.contribute);
    return true;
}
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
    while (getCustomerFromFile(file, temp))
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
        int id = numberFromEmptyIdCustomer();
        if (id == -1)
        {
            id = getNumberOfCustomer();
            id++;
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

void updateCustomerToFile(Customer customer)
{
    fstream file1("./customer/listCustomer.txt", ios::in);
    fstream temp1("./customer/temp1.txt", ios::out);
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
    Customer tempCustomer;
    while (getCustomerFromFile(file1, tempCustomer))
    {
        if (tempCustomer.getName() == customer.getName())
        {
            tempCustomer = customer;
        }
        temp1 << tempCustomer.getId() << "|" << tempCustomer.getName() << "|" << tempCustomer.getSdt() << "|" << tempCustomer.getEmail() << "|" << tempCustomer.getContribute() << endl;
    }
    file1.close();
    temp1.close();
    system("del .\\customer\\listCustomer.txt");
    system("ren .\\customer\\temp1.txt listCustomer.txt");
}

bool dataOfEmptyIdCustomer(fstream &file, int &count)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;
    stringstream ss(line);
    ss >> count;
    return true;
}

int numberFromEmptyIdCustomer()
{
    int count = -1;
    string path1 = "./customer/EmptyID.txt";
    string tempPath1 = "./customer/temp1.txt";
    fstream file1(path1, ios::in);
    fstream temp1(tempPath1, ios::out);
    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    if (!temp1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    if (dataOfEmptyIdCustomer(file1, count))
    {
        int ans = count;
        while (dataOfEmptyIdCustomer(file1, count))
        {
            temp1 << count << endl;
        }
        file1.close();
        temp1.close();
        system("del .\\customer\\EmptyID.txt");
        system("ren .\\customer\\temp1.txt emptyID.txt");
        return ans;
    }
    file1.close();
    temp1.close();
    system("del .\\customer\\temp1.txt");
    return count;
}

int getNumberOfCustomer()
{
    int count = -1;
    fstream file("./customer/customerID.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    else
        file >> count;
    file.close();
    return count;
}
