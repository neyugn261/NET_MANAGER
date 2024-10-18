#ifndef CUSTOMER_H
#define CUSTOMER_H 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

// gồm: id, name, sdt, email, contribute


class Customer
{
private:
    string id;
    string name;
    string sdt;
    string email;
    string contribute;

public:
    ~Customer();
    string getId();
    string getName();
    string getSdt();
    string getEmail();
    string getContribute();

    void setId(string);
    void setName(string);
    void setSdt(string);
    void setEmail(string);
    void setContribute(string);        
  
    friend bool checkCustomer(Customer &customer);
    friend bool operator>>(istream &in, Customer &customer);
};
/*------------------------------------Friend------------------------------------*/
bool checkCustomer(Customer &customer);
bool operator>>(istream &in, Customer &customer);
/*------------------------------------Other------------------------------------*/


#endif
