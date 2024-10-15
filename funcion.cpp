#include "function.h"

/*------------------------------------CONSOLE------------------------------------*/

void ShowCursor(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}

void Gotoxy(SHORT posX, SHORT posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position = {posX, posY};
    SetConsoleCursorPosition(hStdout, Position);
}
void pressEnter()
{
    cout << "\n(Nhấn ENTER để thoát)";
    while (_getch() != KEY_ENTER)
    {
    }
    system("cls");
}
/*------------------------------------MENU------------------------------------*/
void optionMenu(string typeMenu, int option)
{
    if (typeMenu == "ADMIN")
    {
        switch (option)
        {
        case 1:
            cout << "Quản lí món ăn" << endl;
            break;
        case 2:
            cout << "Quản lí máy" << endl;
            break;
        case 3:
            cout << "Quản lí khách Hàng" << endl;
            break;
        case 4:
            cout << "Quản lí nhân viên" << endl;
            break;
        case 5:
            cout << "Thoát" << endl;
            break;
        }
    }
    else if (typeMenu == "STAFF")
    {
        switch (option)
        {
        case 1:
            cout << "Đặt máy và thức ăn" << endl;
            break;
        case 2:
            cout << "Tình trạng máy" << endl;
            break;
        case 3:
            cout << "Lịch sử ca" << endl;
            break;
        case 4:
            cout << "Khách Hàng" << endl;
            break;
        case 5:
            cout << "Thoát" << endl;
            break;
        }
    }
}

void printMenuOption(string typeMenu, int option, bool isSelected)
{
    HANDLE myConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(myConsole, isSelected ? 240 : 15);
    optionMenu(typeMenu, option);
    SetConsoleTextAttribute(myConsole, 15);
}

int getMenuOptionCount(const string &typeMenu)
{
    if (typeMenu == "ADMIN")
        return 5;
    if (typeMenu == "STAFF")
        return 5;

    // Mặc định nếu không tìm thấy menu
    return 0;
}

void showMenu(string typeMenu, int selectOption)
{
    int optionCount = getMenuOptionCount(typeMenu);
    if (optionCount > 0)
    {
        Gotoxy(0, 1);
        for (int i = 1; i <= optionCount; ++i)
            printMenuOption(typeMenu, i, i == selectOption);
    }
    else
        cout << "Menu not found!" << endl;
}
void menuAdmin(Admin admin)
{
    ShowCursor(false);
    system("cls");
    SetConsoleTitle(TEXT("Menu admin"));
    int selectOption = 1;
    int count = getMenuOptionCount("ADMIN");
    while (true)
    {
        showMenu("ADMIN", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? count : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == count) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:

                break;
            case 5:
                system("cls");
                return;
            }
            break;
        }
    }
    ShowCursor(true);
}
void menuStaff(Staff staff)
{
    ShowCursor(false);
    system("cls");
    SetConsoleTitle(TEXT("Menu Staff"));
    int selectOption = 1;
    int count = getMenuOptionCount("STAFF");
    while (true)
    {
        showMenu("STAFF", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? count : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == count) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:

                break;
            case 5:
                system("cls");
                return;
            }
            break;
        }
    }
    ShowCursor(true);
}