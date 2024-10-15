#include "function.h"

int main()
{
    SetConsoleOutputCP(65001);

    Account account;
    if (account.login())
    {
        if (account.getRole() == "ADMIN")
        {
            Admin admin;
            admin.setPass(account.getPass());
            admin.setStatus(account.getStatus());
            admin.setName(account.getName());
            admin.setRole(account.getRole());
            menuAdmin(admin);
        }
        else
        {
            Staff staff;
            staff.setPass(account.getPass());
            staff.setStatus(account.getStatus());
            staff.setName(account.getName());
            staff.setRole(account.getRole());
            menuStaff(staff);
        }
    }

    return 0;
}