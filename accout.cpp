#include "function.h"
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

        ShowCursor(false);
        Gotoxy(0, 12);
        Sleep(500);
        cout << "Tài khoản hoặc mật khẩu không đúng";
        Sleep(2000);
        system("cls");
        ShowCursor(true);
    }
    system("cls");
    cout << "Đã nhập sai quá 3 lần!" << endl;
    pressEnter();
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

    while (getObjectFromFile(file, temp))
    {

        if (temp.aname == account.aname && temp.password == account.password)
        {
            account = temp;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// ╣ ╠
istream &operator>>(istream &in, Account &account)
{
    Gotoxy(0, 0);
    cout << "╔════════════════════════════════╗" << endl
         << "║            Đăng nhập           ║" << endl
         << "╠════════════════════════════════╣" << endl
         << "║ Tài khoản:                     ║" << endl
         << "║ ┌────────────────────────────┐ ║" << endl
         << "║ │                            │ ║" << endl
         << "║ └────────────────────────────┘ ║" << endl
         << "║ Mật khẩu:                      ║" << endl
         << "║ ┌────────────────────────────┐ ║" << endl
         << "║ │                            │ ║" << endl
         << "║ └────────────────────────────┘ ║" << endl
         << "╚════════════════════════════════╝" << endl;

    Gotoxy(4, 5);
    EnterString(account.aname, 26);
    Gotoxy(4, 9);
    enterpassword(account.password, 26);

    return in;
}
/*------------------------------------Other------------------------------------*/
void enterpassword(string &password,int n)
{
    password.clear();
    char ch;
    while (true)
    {
        ch = getch();
        if (ch == KEY_ENTER)
            if (password.empty())
            {
                //
            }
            else
            {
                break;
            }
        else if (ch == KEY_BACKSPACE && !password.empty())
        {
            cout << "\b \b";
            password.pop_back();
        }
        else if (ch != KEY_BACKSPACE && password.length() < n)
        {
            password += ch;
            cout << "•";
        }
    }
}
