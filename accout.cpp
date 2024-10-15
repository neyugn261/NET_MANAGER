#include "account.h"
#include <fstream>
#include <sstream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_BACKSPACE 8

Account::~Account() {}
string Account::getName() { return name; }
string Account::getPass() { return password; }
string Account::getStatus() { return status; }
string Account::getRole() { return role; }
void Account::setName(string name) { this->name = name; }
void Account::setPass(string pass) { this->password = pass; }
void Account::setStatus(string status) { this->status = status; }
void Account::setRole(string role) { this->role = role; }

bool Account::login()
{
    system("cls");
    int count = 0;
    while (count++ < 3)
    {
        cin >> *this;
        if (checkAccount(*this))
        {
            system("cls");
            return true;
        }
        else
        {
            cout << "\nĐăng nhập thất bại" << endl;
        }
    }
    system("cls");
    cout << "Đã nhập sai quá 3 lần!" << endl;
    cout << "\n(Nhấn ENTER để thoát)";
    while (_getch() != KEY_ENTER)
    {
    }
    system("cls");
    return false;
}

/*------------------------------------Other------------------------------------*/

bool checkAccount(Account &account)
{
    string filename = "./account/listAccount.txt";
    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }

    Account temp;
    while (getAccountFromFile(file, temp))
    {
        if (temp.name == account.name && temp.password == account.password)
        {
            if (temp.getStatus() == "ONLINE")
            {
                cout << "Tài khoản đang được sử dụng!" << endl;
                return false;
            }
            else
            {
                account.role = temp.role;
                account.setStatus("ONLINE");
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

bool getAccountFromFile(fstream &file, Account &account)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;

    stringstream ss(line);
    getline(ss, account.name, '|');
    getline(ss, account.password, '|');
    getline(ss, account.role, '|');
    getline(ss, account.status);

    return true;
}

istream &operator>>(istream &in, Account &account)
{
    cout << "Username: ";
    in >> account.name;
    cout << "Password: ";
    enterpassword(account.password);
    return in;
}
/*------------------------------------Other------------------------------------*/
void enterpassword(string &password)
{
    password.clear();
    char ch;
    while (true)
    {
        ch = getch();
        if (ch == KEY_ENTER)
            break;
        else if (ch == KEY_BACKSPACE && !password.empty())
        {
            cout << "\b \b";
            password.pop_back();
        }
        else if (ch != KEY_BACKSPACE)
        {
            password += ch;
            cout << "•";
        }
    }
}