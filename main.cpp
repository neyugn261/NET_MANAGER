#include "function.h"

int main()
{
    SetConsoleOutputCP(65001);

    Account account;
    if (account.login())
    {
        if (account.getStatus() == "ONLINE")
        {
            cout << "Tài khoản đã đăng nhập ở một nơi khác" << endl;
            return 0;
        }
        else
        {
            account.setStatus("ONLINE");

            if (account.getRole() == "ADMIN")
            {
                Admin admin;
                admin.setPass(account.getPass());
                admin.setStatus(account.getStatus());
                admin.setName(account.getAname());
                admin.setRole(account.getRole());
                menuAdmin(admin);
            }
            else
            {
                Staff staff;
                staff.setPass(account.getPass());
                staff.setStatus(account.getStatus());
                staff.setName(account.getAname());
                staff.setRole(account.getRole());
                menuStaff(staff);
            }
        }
    }

    return 0;
}