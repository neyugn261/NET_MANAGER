#include "account.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_BACKSPACE 8

Account::~Account() {}
string Account::getAname() { return aname; }
string Account::getPass() { return password; }
string Account::getStatus() { return status; }
string Account::getRole() { return role; }

void Account::setAname(string aname) { this->aname = aname; }
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
            if (role == "ONLINE")
                cout << "Tài khoản đã đăng nhập ở một nơi khác" << endl;
            else
                cout << "Đăng nhập thất bại" << endl;
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

/*------------------------------------Friend------------------------------------*/

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
        if (temp.aname == account.aname && temp.password == account.password)
        {
            account.role = temp.role;
            file.close();
            return true;
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
    getline(ss, account.aname, '|');
    getline(ss, account.password, '|');
    getline(ss, account.role, '|');
    getline(ss, account.status);

    return true;
}

istream &operator>>(istream &in, Account &account)
{
    cout << "Username: ";
    in >> account.aname;
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
