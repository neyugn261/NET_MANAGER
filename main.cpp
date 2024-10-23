#include "function.h"

int main()
{
    SetConsoleOutputCP(65001);

    Account account;
    if (account.login())
    {
        if (account.getStatus() == "ONLINE")
        {
            system("cls");
            cout << "Tài khoản đã đăng nhập ở một nơi khác" << endl;
            pressEnter();
            return 0;
        }
        else
        {
            if (account.getRole() == "ADMIN")
            {
                Admin admin;
                admin.setPass(account.getPass());
                admin.setStatus("ONLINE");
                admin.setAname(account.getAname());
                admin.setRole(account.getRole());
                updateAdminToFile(admin);
                menuAdmin(admin);
            }
            else
            {
                Staff staff;                  
                staff.setAname(account.getAname());
                checkAnameStaff(staff);
                staff.setStatus("ONLINE");
                updateStaffToFile(staff);
                menuStaff(staff);
            }
        }
    }

    return 0;
}