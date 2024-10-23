#include "iostream"
#include "windows.h"

using namespace std;
int main()
{
    SetConsoleOutputCP(65001);
    cout << "╔══════╗" << endl;
    cout << "║ Text ║" << endl;
    cout << "╠══════╣" << endl;
    cout << "║  1.  ║" << endl;
    cout << "╚══════╝" << endl;
    return 0;

  /*        ╔════════════════════════════════════╗
            ║            Thông tin               ║
            ╠════════════════════════════════════╣
      ❯❯❯❯  ║  Tên: pepsi          ID: D001      ║────────────────────┐"
      ❯❯❯❯  ║  Giá: 10000 (VND)    Đơn vị: lon   ║ Giá: 10000,1200... │"
            ║  Số lượng: 50                      ║ Số lưong: 50,100...│".
            ╚════════════════════════════════════╝────────────────────┘"*/
}
// ╔══════╗
// ║ Text ║
// ╠══════╣
// ║  1.  ║
// ╚══════╝
/*Đặng Đăng Khoa
istream &operator>>(istream &is, Account &account)
{
    int count = 0;
    while (count < 3)
    {
        system("cls");
        cout << "┌───────────────────────────────────┐" << endl
             << "│               LOGIN               │" << endl
             << "├───────────────────────────────────┤" << endl
             << "│Username:                          │" << endl
             << "├───────────────────────────────────┤" << endl
             << "│Password:                          │" << endl
             << "└───────────────────────────────────┘" << endl;

        while (account.username.empty())
        {
            Gotoxy(11, 3);
            getline(is, account.username);
        }

        while (account.password.empty())
        {
            Gotoxy(11, 5);
            enterPassword(account.password);
        }

        if (checkAccount(account))
        {
            if (account.isLocked)
            {
                Gotoxy(0, 7);
                cout << "Tài khoản đã bị khóa!" << endl;
                account.username.clear();
                account.password.clear();
                Sleep(555);
                continue;
            }
            if (account.status)
            {
                Gotoxy(0, 7);
                cout << "Tài khoản đã đăng nhập ở máy khác!" << endl;
                account.username.clear();
                account.password.clear();
                count++;
                Sleep(555);
                continue;
            }
            else
            {
                Gotoxy(0, 7);
                cout << "Đăng nhập thành công!" << endl;
                return is;
            }
        }
        else
        {
            Gotoxy(0, 7);
            cout << "Đăng nhập thất bại!" << endl;
            account.username.clear();
            account.password.clear();
            count++;
            Sleep(555);
        }
    }
    return is;
}
*/