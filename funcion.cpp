#include "function.h"

/*------------------------------------CONSOLE------------------------------------*/

// Hiển thị/ẩn con trỏ chuột
void ShowCursor(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}

// Đặt vị trí con trỏ tại tọa độ (x, y)
void Gotoxy(SHORT posX, SHORT posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position = {posX, posY};
    SetConsoleCursorPosition(hStdout, Position);
}

// Nhấn ENTER để thoát và xóa màn hình
void pressEnter()
{
    cout << "\n(Nhấn ENTER để thoát)";
    while (_getch() != KEY_ENTER)
    {
    }
    system("cls");
}

/*------------------------------------MENU------------------------------------*/

// Hiển thị các tùy chọn của menu dựa trên loại và tùy chọn được chọn
void optionMenu(string typeMenu, int option)
{
    if (typeMenu == "ADMIN")
    {
        switch (option)
        {
        case 1:
            cout << "Quản lí máy tính" << endl;
            break;
        case 2:
            cout << "Quản lí nhân viên" << endl;
            break;
        case 3:
            cout << "Quản lí khách Hàng" << endl;
            break;
        case 4:
            cout << "Quản lí món ăn" << endl;
            break;
        case 5:
            cout << "Xem lịch sử" << endl;
            break;
        case 6:
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
    else if (typeMenu == "MANAGECOMPUTER")
    {
        switch (option)
        {
        case 1:
            cout << "Thêm máy" << endl;
            break;
        case 2:
            cout << "Xóa máy" << endl;
            break;
        case 3:
            cout << "Thay đổi giá của máy" << endl;
            break;
        case 4:
            cout << "Xem danh sách máy" << endl;
            break;
        case 5:
            cout << "Thoát" << endl;
            break;
        }
    }
    else if (typeMenu == "MANAGESTAFF")
    {
        switch (option)
        {
        case 1:
            cout << "Thêm nhân viên" << endl;
            break;
        case 2:
            cout << "Xem và thay đổi thông tin nhân viên" << endl;
            break;
        case 3:
            cout << "Xem danh sách nhân viên" << endl;
            break;
        case 4:
            cout << "Thoát" << endl;
            break;
        }
    }
    else if (typeMenu == "MANAGECUSTOMER")
    {
        switch (option)
        {
        case 1:
            cout << "Thêm khách hàng" << endl;
            break;
        case 2:
            cout << "Xóa khách hàng" << endl;
            break;
        case 3:
            cout << "Xem danh sách khách hàng" << endl;
            break;
        case 4:
            cout << "Thoát" << endl;
            break;
        }
    }
    else if (typeMenu == "MANAGEDISH")
    {
        switch (option)
        {
        case 1:
            cout << "Thêm món ăn" << endl;
            break;
        case 2:
            cout << "Xem và thay đổi thông tin món ăn" << endl;
            break;
        case 3:
            cout << "Xem danh sách món ăn" << endl;
            break;
        case 4:
            cout << "Thoát" << endl;
            break;
        }
    }
    else if (typeMenu == "CHANGEDISH")
    {
        switch (option)
        {
        case 1:
            cout << "Xem thông tin" << endl;
            break;

        case 2:
            cout << "Thay đổi giá" << endl;
            break;
        case 3:
            cout << "Thêm số lượng" << endl;
            break;
        case 4:
            cout << "Xóa món ăn" << endl;
            break;
        case 5:
            cout << "Thoát" << endl;
            break;
        }
    }
    else if (typeMenu == "SEENSTAFF")
    {
        switch (option)
        {
        case 1:
            cout << "Xem thông tin nhân viên" << endl;
            break;
        case 2:
            cout << "Thay đổi mật khẩu cho tài khoản nhân viên" << endl;
            break;
        case 3:
            cout << "Xóa nhân viên" << endl;
            break;
        case 4:
            cout << "Thoát" << endl;
            break;
        }
    }
    else
    {
        cout << "Không tìm thấy menu" << endl;
    }
}

// In ra menu tùy chọn với lựa chọn hiện tại được làm nổi bật
void printMenuOption(string typeMenu, int option, bool isSelected)
{
    HANDLE myConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(myConsole, isSelected ? 240 : 15);
    optionMenu(typeMenu, option);
    SetConsoleTextAttribute(myConsole, 15);
}

// Lấy số lượng tùy chọn trong menu dựa trên loại menu
int getMenuOptionCount(const string &typeMenu)
{
    if (typeMenu == "ADMIN")
        return 6;
    if (typeMenu == "MANAGECOMPUTER")
        return 5;
    if (typeMenu == "MANAGESTAFF")
        return 4;
    if (typeMenu == "MANAGECUSTOMER")
        return 4;
    if (typeMenu == "MANAGEDISH")
        return 4;
    if (typeMenu == "CHANGEDISH")
        return 5;
    if (typeMenu == "STAFF")
        return 5;
    if (typeMenu == "SEENSTAFF")
        return 4;
    // Các loại menu khác...

    // Mặc định nếu không tìm thấy menu
    return 0;
}

// Hiển thị toàn bộ menu với tùy chọn hiện tại được làm nổi bật
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
/*------------------------------------MenusAdmin------------------------------------*/

// Menu chính dành cho admin
void menuAdmin(Admin admin)
{
    ShowCursor(false);
    system("cls");
    SetConsoleTitle(TEXT("Menu admin"));
    int selectOption = 1;

    while (true)
    {
        showMenu("ADMIN", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 6 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 6) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                manageComputer(admin);
                break;
            case 2:
                manageStaff(admin);
                break;
            case 3:
                manageCustomer(admin);
                break;
            case 4:
                manageDish(admin);
                break;
            case 5:

                break;
            case 6:
                system("cls");
                return;
            }
            break;
        }
    }
    ShowCursor(true);
}

// Các menu phụ dành cho admin
void manageComputer(Admin admin)
{
    system("cls");
    SetConsoleTitle(TEXT("Menu quản lí máy tính"));
    int selectOption = 1;

    while (true)
    {
        showMenu("MANAGECOMPUTER", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 5 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 5) ? 1 : selectOption + 1;
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
}

void manageCustomer(Admin admin)
{
    system("cls");
    SetConsoleTitle(TEXT("Menu quản lí khách hàng"));
    int selectOption = 1;

    while (true)
    {
        showMenu("MANAGECUSTOMER", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 4 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 4) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:

                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void manageStaff(Admin admin)
{
    system("cls");
    SetConsoleTitle(TEXT("Menu quản lí staff"));
    int selectOption = 1;

    while (true)
    {

        showMenu("MANAGESTAFF", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 4 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 4) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            system("cls");
            switch (selectOption)
            {
            case 1:
                addStaff(admin);
                break;
            case 2:
                seenstaff(admin);
                break;
            case 3:
                seenListStaff(admin);
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void addStaff(Admin admin)
{
    ShowCursor(true);
    Account account;
    Staff staff;
    string name;
    string sdt;
    cin >> account;
    if (!checkAccount(account))
    {

        cout << "\nNhập tên: ";
        cin >> name;
        cout << "Nhập số điện thoại: ";
        cin >> sdt;

        int id = numberFromEmptyIdSt();
        if (id == -1)
        {
            id = getNumberOfStaff();
            id++;
            updateNumberOfStaff(id);
        }

        stringstream ss;
        ss << setw(3) << setfill('0') << id;
        string ID = "ST" + ss.str();

        staff.setName(name);
        staff.setSdt(sdt);
        staff.setId(ID);
        staff.setRole("STAFF");
        staff.setAname(account.getAname());
        staff.setPass(account.getPass());
        staff.setStatus("OFFLINE");
        admin.addStaff(staff);
        ShowCursor(false);
        pressEnter();
    }
    else
    {
        ShowCursor(false);
        cout << "Tài khoản đã tồn tại!" << endl;
        pressEnter();
    }
}

void seenstaff(Admin admin)
{
    ShowCursor(true);
    Staff staff;
    int count = 0;
    cout << "(Nhập sai quá 3 lần tự động thoát)" << endl;
    while (count++ < 3)
    {
        cout << "Nhập tên nhân viên: ";
        string name;
        cin >> name;
        staff.setName(name);
        if (checkStaff(staff))
        {
            ShowCursor(false);
            system("cls");
            SetConsoleTitle(TEXT("Menu quản lí thông tin staff"));
            int selectOption = 1;

            while (true)
            {
                system("cls");
                cout << "     Nhân viên: " << staff.getName() << endl;
                showMenu("SEENSTAFF", selectOption);
                int key = _getch();
                switch (key)
                {
                case KEY_UP:
                    selectOption = (selectOption == 1) ? 4 : selectOption - 1;
                    break;
                case KEY_DOWN:
                    selectOption = (selectOption == 4) ? 1 : selectOption + 1;
                    break;
                case KEY_ENTER:
                    system("cls");
                    switch (selectOption)
                    {
                    case 1:
                        in4Staff(admin, staff);

                        break;
                    case 2:
                        changeSPassword(admin, staff);
                        break;
                    case 3:
                        deleteStaff(admin, staff);
                        return;
                    case 4:
                        system("cls");
                        return;
                    }
                }
            }
            ShowCursor(true);
            return;
        }

        system("cls");
        cout << "(Nhập sai quá 3 lần tự động thoát: " << count << " lần)" << endl;
        cout << "Không tìm thấy tên nhân viên!" << endl;
    }
    system("cls");
    ShowCursor(false);
}

void in4Staff(Admin admin, Staff staff)
{
    admin.seenStaff(staff);
    pressEnter();
}

void deleteStaff(Admin admin, Staff staff)
{
    admin.deleteStaff(staff);
    pressEnter();
}

void changeSPassword(Admin admin, Staff staff)
{
    ShowCursor(true);
    admin.changeSPassword(staff);
    ShowCursor(false);
    pressEnter();
}

void seenListStaff(Admin admin)
{
    system("cls");
    // SetConsoleTitle(TEXT("Danh sách nhân viên"));
    admin.seenListStaff();
    pressEnter();
}

void manageDish(Admin admin)
{
    system("cls");
    SetConsoleTitle(TEXT("Menu quản món ăn"));
    int selectOption = 1;

    while (true)
    {
        showMenu("MANAGEDISH", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 4 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 4) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            system("cls");
            switch (selectOption)
            {
            case 1:
                addDish(admin);
                break;
            case 2:
                changeDish(admin);
                break;
            case 3:
                seenListDish(admin);
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void addDish(Admin admin)
{
    system("cls");
    ShowCursor(true);
    Dish dish;
    if (cin >> dish)
    {
        admin.addDish(dish);
    }
    ShowCursor(false);
    pressEnter();
}

void changeDish(Admin admin)
{
    ShowCursor(true);
    Dish dish;
    int count = 0;
    cout << "(Nhập sai quá 3 lần tự động thoát)" << endl;
    while (count++ < 3)
    {
        cout << "Nhập tên món ăn: ";
        string name;
        cin >> name;
        dish.setName(name);
        if (checkDish(dish))
        {
            ShowCursor(false);
            system("cls");
            SetConsoleTitle(TEXT("Menu thay đổi thông tin món ăn"));
            int selectOption = 1;

            while (true)
            {
                system("cls");
                cout << "     Món ăn: " << dish.getName() << endl;
                showMenu("CHANGEDISH", selectOption);
                int key = _getch();
                switch (key)
                {
                case KEY_UP:
                    selectOption = (selectOption == 1) ? 5 : selectOption - 1;
                    break;
                case KEY_DOWN:
                    selectOption = (selectOption == 5) ? 1 : selectOption + 1;
                    break;
                case KEY_ENTER:
                    system("cls");
                    switch (selectOption)
                    {
                    case 1:
                        in4Dish(admin, dish);
                        break;
                    case 2:
                        changeCost(admin, dish);
                        break;
                    case 3:
                        addQuanlity(admin, dish);
                        break;
                    case 4:
                        deleteDish(admin, dish);
                        return;
                    case 5:
                        system("cls");
                        return;
                    }
                    break;
                }
            }
            ShowCursor(true);
            return;
        }
        system("cls");
        cout << "(Nhập sai quá 3 lần tự động thoát: " << count << " lần)" << endl;
        cout << "Không tìm thấy tên món ăn!" << endl;
    }
    system("cls");
    ShowCursor(false);
}

void in4Dish(Admin admin, Dish dish)
{
    admin.seenDish(dish);
    pressEnter();
}

void changeCost(Admin admin, Dish dish)
{
    ShowCursor(true);
    admin.changeCost(dish);
    ShowCursor(false);
    pressEnter();
}

void deleteDish(Admin admin, Dish dish)
{
    admin.deleteDish(dish);
    pressEnter();
}

void seenListDish(Admin admin)
{
    system("cls");
    // SetConsoleTitle(TEXT("Danh sách món ăn"));
    admin.seenListDish();
    pressEnter();
}

void addQuanlity(Admin admin, Dish dish)
{
    ShowCursor(true);
    admin.addQuanlity(dish);
    ShowCursor(false);
    pressEnter();
}
/*------------------------------------Menustaff------------------------------------*/
void menuStaff(Staff staff)
{
    ShowCursor(false);
    system("cls");
    SetConsoleTitle(TEXT("Menu Staff"));
    int selectOption = 1;
    while (true)
    {
        showMenu("STAFF", selectOption);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 5 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 5) ? 1 : selectOption + 1;
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