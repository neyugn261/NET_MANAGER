#ifndef ACCOUNT_H
#define ACCOUNT_H 1

#include <iostream>
using namespace std;

class Account
{
protected:
    string aname;
    string password;
    string status;
    string role;

public:
    ~Account();

    string getAname();
    string getPass();
    string getStatus();
    string getRole();

    void setAname(string);
    void setPass(string);
    void setStatus(string);
    void setRole(string);

    bool login();

    friend istream &operator>>(istream &in, Account &account);
    friend bool checkAccount(Account &account);
};

/*------------------------------------Friend------------------------------------*/
bool checkAccount(Account &account);
istream &operator>>(istream &in, Account &account);
/*------------------------------------Other------------------------------------*/
void enterpassword(string &password);

#endif