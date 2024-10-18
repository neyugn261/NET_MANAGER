#include "function.h"

// ╔════════════════════════╗
// ║       Menu Admin       ║
// ╠════════════════════════╣
// ║  1. Quản lí máy tính   ║
// ║  2. Quản lí nhân viên  ║
// ║  3. Quản lí khách hàng ║
// ║  4. Quản lí món ăn     ║
// ║  5. Xem lịch sử        ║
// ║  6. Thoát              ║
// ╚════════════════════════╝

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

void ClearLine(SHORT posY)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    Gotoxy(0, posY);
    for (int i = 0; i < consoleWidth; i++)
    {
        cout << " ";
    }
}

void printSpace(int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << " ";
    }
}
void ClearLine(SHORT posX, SHORT posY, int length)
{
    Gotoxy(posX, posY);
    for (int i = 0; i < length; i++)
    {
        cout << " ";
    }
}

/*------------------------------------MENU------------------------------------*/

// Hiển thị các tùy chọn của menu dựa trên loại và tùy chọn được chọn
void optionMenu(string typeMenu, int option)
{
    if (typeMenu == "ADMIN")
    {
        // tôi muốn độ dài là 30 vd: " 1.Quản lí máy tính           "
        switch (option)
        {
        case 1:
            cout << " 1.Quản lí máy tính           ";
            break;
        case 2:
            cout << " 2.Quản lí nhân viên          ";
            break;
        case 3:
            cout << " 3.Quản lí khách hàng         ";
            break;
        case 4:
            cout << " 4.Quản lí món ăn             ";
            break;
        case 5:
            cout << " 5.Xem lịch sử                ";
            break;
        case 6:
            cout << " 6.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "STAFF")
    {
        switch (option)
        {
        case 1:
            cout << " 1.Quản lí máy tính           ";
            break;
        case 2:
            cout << " 2.Quản lí khách hàng         ";
            break;
        case 3:
            cout << " 3.Quản lí món ăn             ";
            break;
        case 4:
            cout << " 4.Xem lịch sử                ";
            break;
        case 5:
            cout << " 5.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "MANAGECOMPUTER")
    {
        switch (option)
        {
        case 1:
            cout << " 1.Thêm máy tính              ";
            break;
        case 2:
            cout << " 2.Xem thông tin máy          ";
            break;
        case 3:
            cout << " 3.Xem danh sách máy          ";
            break;
        case 4:
            cout << " 4.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "MANAGESTAFF")
    {
        switch (option)
        {
        case 1:
            cout << " 1.Thêm nhân viên             ";
            break;
        case 2:
            cout << " 2.Xem thông tin nhân viên    ";
            break;
        case 3:
            cout << " 3.Xem danh sách nhân viên    ";
            break;
        case 4:
            cout << " 4.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "MANAGECUSTOMER")
    {
        switch (option)
        {
        case 1:
            cout << " 1.Thêm khách hàng            ";
            break;
        case 2:
            cout << " 2.Xem thông tin khách hàng   ";
            break;
        case 3:
            cout << " 3.Xem danh sách khách hàng   ";
            break;
        case 4:
            cout << " 4.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "MANAGEDISH")
    {
        switch (option)
        {
        case 1:
            cout << " 1.Thêm món ăn                ";
            break;
        case 2:
            cout << " 2.Xem thông tin món ăn       ";
            break;
        case 3:
            cout << " 3.Xem danh sách món ăn       ";
            break;
        case 4:
            cout << " 4.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "CHANGEDISH")
    {
        switch (option)
        {       
        case 1:
            cout << " 2.Thay đổi giá               ";
            break;
        case 2:
            cout << " 3.Thay đổi số lượng          ";
            break;
        case 3:
            cout << " 4.Xóa món ăn                 ";
            break;
        case 4:
            cout << " 5.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "SEENSTAFF")
    {
        switch (option)
        {
        case 1:
            cout << " 1.Xem thông tin nhân viên    ";
            break;
        case 2:
            cout << " 2.Thay đổi mật khẩu          ";
            break;
        case 3:
            cout << " 3.Xóa nhân viên              ";
            break;
        case 4:
            cout << " 4.Thoát                      ";
            break;
        }
    }
    else if (typeMenu == "SEENCOMPUTER")
    {
        switch (option)
        {
        case 1:
            cout << " 1.Xem thông tin máy          ";
            break;
        case 2:
            cout << " 2.Thay đổi giá tiền          ";
            break;
        case 3:
            cout << " 3.Xóa máy                    ";
            break;
        case 4:
            cout << " 4.Thoát                      ";
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
        return 4;
    if (typeMenu == "MANAGESTAFF")
        return 4;
    if (typeMenu == "MANAGECUSTOMER")
        return 4;
    if (typeMenu == "MANAGEDISH")
        return 4;
    if (typeMenu == "CHANGEDISH")
        return 4;
    if (typeMenu == "STAFF")
        return 5;
    if (typeMenu == "SEENSTAFF")
        return 4;
    if (typeMenu == "SEENCOMPUTER")
        return 4;
    // Các loại menu khác...

    // Mặc định nếu không tìm thấy menu
    return 0;
}

string getNameOfMenu(string typeMenu)
{

    // canh chữ giữa nhưng số lượng kí tự là 30 tính luôn space vd: "          Menu Admin          "
    if (typeMenu == "ADMIN")
        return "          Menu Admin          ";
    if (typeMenu == "MANAGECOMPUTER")
        return "       Quản lí máy tính       ";
    if (typeMenu == "MANAGESTAFF")
        return "      Quản lí nhân viên       ";
    if (typeMenu == "MANAGECUSTOMER")
        return "     Quản lí khách hàng       ";
    if (typeMenu == "MANAGEDISH")
        return "        Quản lí món ăn        ";
    if (typeMenu == "CHANGEDISH")
        return "                              ";
    if (typeMenu == "STAFF")
        return "          Menu Staff          ";
    if (typeMenu == "SEENSTAFF")
        return "                              ";
    if (typeMenu == "SEENCOMPUTER")
        return "                              ";
    // Các loại menu khác...
    return "          Menu not found          ";
}

// Hiển thị toàn bộ menu với tùy chọn hiện tại được làm nổi bật
void showMenu(string typeMenu, int selectOption)
{

    int optionCount = getMenuOptionCount(typeMenu);
    if (optionCount > 0)
    {
        Gotoxy(0, 0);
        cout << "╔══════════════════════════════╗" << endl;
        cout << "║" << getNameOfMenu(typeMenu) << "║" << endl;
        cout << "╠══════════════════════════════╣" << endl;
        for (int i = 1; i <= optionCount; ++i)
        {
            cout << "║";
            printMenuOption(typeMenu, i, i == selectOption);
            cout << "║" << endl;
        }
        cout << "╚══════════════════════════════╝" << endl;
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
            selectOption = (selectOption == 1) ? 4 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 4) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                addComputer(admin);
                break;
            case 2:
                seenComputer(admin);
                break;
            case 3:
                seenListComputer(admin);
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void addComputer(Admin admin)
{
    system("cls");
    ShowCursor(true);
    Computer computer;

    if (cin >> computer)
    {
        admin.addComputer(computer);
    }
    ShowCursor(false);
    pressEnter();
}

void seenComputer(Admin admin)
{
    system("cls");
    ShowCursor(true);
    Computer computer;
    int count = 0;
    cout << "(Nhập sai quá 3 lần tự động thoát)" << endl;
    while (count++ < 3)
    {
        cout << "Nhập ID máy: ";
        string temp;
        cin >> temp;

        stringstream ss;
        ss << setw(3) << setfill('0') << temp;
        string id = "PC" + ss.str();

        computer.setName(id);
        if (checkObject(computer))
        {
            ShowCursor(false);
            system("cls");
            SetConsoleTitle(TEXT("Menu quản lí thông tin máy"));
            int selectOption = 1;

            while (true)
            {
                showMenu("SEENCOMPUTER", selectOption);

                Gotoxy(1, 1);
                int space = (30 - computer.getName().length()) / 2;
                for (int i = 0; i < space; i++)
                    cout << " ";
                cout << computer.getName() << endl;

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
                        in4Computer(admin, computer);
                        break;
                    case 2:
                        changeCost(admin, computer);
                        break;
                    case 3:
                        deleteComputer(admin, computer);
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
        cout << "Không tìm thấy ID máy!" << endl;
    }
    ShowCursor(false);
    system("cls");
}

void in4Computer(Admin admin, Computer computer)
{
    system("cls");
    admin.seenComputer(computer);
    pressEnter();
}

void changeCost(Admin admin, Computer computer)
{
    system("cls");
    ShowCursor(true);
    admin.changeCost(computer);
    ShowCursor(false);
    pressEnter();
}

void deleteComputer(Admin admin, Computer computer)
{
    system("cls");
    ShowCursor(true);
    admin.deleteComputer(computer);
    ShowCursor(false);
    pressEnter();
}

void seenListComputer(Admin admin)
{
    system("cls");
    admin.seenListComputer();
    pressEnter();
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
                addCustomer(admin);
                break;
            case 2:
                deleteCustomer(admin);
                break;
            case 3:
                seenListCustomer(admin);
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void addCustomer(Admin admin)
{
    system("cls");
    ShowCursor(true);
    Customer customer;
    if (cin >> customer)
    {
        admin.addCustomer(customer);
    }
    ShowCursor(false);
    pressEnter();
}

void deleteCustomer(Admin admin)
{
    system("cls");
    ShowCursor(true);
    Customer customer;
    int count = 0;
    cout << "(Nhập sai quá 3 lần tự động thoát)" << endl;
    while (count++ < 3)
    {
        cout << "Nhập tên khách hàng: ";
        string name;
        cin >> name;
        customer.setName(name);
        if (checkObject(customer))
        {
            system("cls");
            ShowCursor(false);
            admin.deleteCustomer(customer);
            pressEnter();
            return;
        }

        system("cls");
        cout << "(Nhập sai quá 3 lần tự động thoát: " << count << " lần)" << endl;
        cout << "Không tìm thấy tên khách hàng!" << endl;
    }
    system("cls");
    ShowCursor(false);
}

void seenListCustomer(Admin admin)
{
    system("cls");
    admin.seenListCustomer();
    pressEnter();
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

        // đường dẫn

        int id = numberFromEmptyId("./staff/emtyId.txt");

        if (id == -1)
        {
            id = getNumber("./staff/staffID.txt");
            id++;
            updateNumber("staff/staffID.txt", id);
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
        if (checkObject(staff))
        {
            ShowCursor(false);
            system("cls");
            SetConsoleTitle(TEXT("Menu quản lí thông tin staff"));
            int selectOption = 1;

            while (true)
            {
                showMenu("SEENSTAFF", selectOption);

                Gotoxy(1, 1);
                int space = (30 - staff.getName().length()) / 2;
                for (int i = 1; i <= space; i++)
                    cout << " ";
                cout << staff.getName() << endl;

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
        Gotoxy(0, 8);
        cout << "Thêm thực phẩm thành công" << endl;
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
        if (checkObject(dish))
        {
            ShowCursor(false);
            system("cls");
            SetConsoleTitle(TEXT("Menu thay đổi thông tin món ăn"));
            int selectOption = 1;

            /*        ╔════════════════════════════════════╗
                      ║           Thông tin                ║
                      ╠════════════════════════════════════╣
                ❯❯❯❯  ║ Tên: pepsi            ID: D001     ║────────────────────┐"
                ❯❯❯❯  ║ Giá: 10000 (VND)      Đơn vị: lon  ║ Giá: 10000,1200... │"
                      ║ Số lượng: 50                       ║ Số lưong: 50,100...│".
                      ╚════════════════════════════════════╝────────────────────┘"*/

            while (true)
            {
                showMenu("CHANGEDISH", selectOption);

                Gotoxy(34, 0);

                cout << "      ╔═══════════════════════════════════╗";
                Gotoxy(34, 1);
                cout << "      ║            Thông tin              ║";
                Gotoxy(34, 2);
                cout << "      ╠═══════════════════════════════════╣";
                Gotoxy(34, 3);
                cout << "❯❯❯❯  ║ Tên: " << dish.getName() << "          ID: " << dish.getId() << "      ║────────────────────┐";
                Gotoxy(34, 4);
                cout << "❯❯❯❯  ║ Giá: " << setw(6) << left << dish.getPrice() << "(VND)";
                (dish.getPrice().length() > 6) ? printSpace(10 - dish.getPrice().length()) : printSpace(4);
                cout << "Đơn vị: " << setw(5) << left << dish.getUnit() << " ║ Giá: 10000,1200... │";
                Gotoxy(34, 5);
                cout << "      ║ Số lượng: " << setw(24) << left << dish.getResidual() << "║ Số lưong: 50,100...│";
                Gotoxy(34, 6);
                cout << "      ╚═══════════════════════════════════╝────────────────────┘";

                Gotoxy(1, 1);
                int space = (30 - dish.getName().length()) / 2;
                for (int i = 0; i < space; i++)
                    cout << " ";
                cout << dish.getName() << endl;

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
                        changeCost(admin, dish);
                        break;
                    case 2:
                        addQuanlity(admin, dish);
                        break;
                    case 3:
                        deleteDish(admin, dish);
                        return;
                    case 4:
                        system("cls");
                        return;
                    }
                    break;
                }
            }
        }
        ShowCursor(true);
        return;
    }
    system("cls");
    cout << "(Nhập sai quá 3 lần tự động thoát: " << count << " lần)" << endl;
    cout << "Không tìm thấy tên món ăn!" << endl;

    system("cls");
    ShowCursor(false);
}

void in4Dish(Admin admin, Dish dish)
{
    admin.seenDish(dish);
    pressEnter();
}

void changeCost(Admin admin, Dish &dish)
{
    admin.changeCost(dish);
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

void addQuanlity(Admin admin, Dish &dish)
{

    admin.addQuanlity(dish);
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

/*------------------------------------Other------------------------------------*/
bool dataOfEmptyId(fstream &file, int &count)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;
    stringstream ss(line);
    ss >> count;
    return true;
}

// Staff
void updateStaffToFile(Staff staff)
{
    fstream file1("./account/listStaff.txt", ios::in);
    fstream temp1("./account/temp1.txt", ios::out);
    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    Staff tempStaff;
    while (getObjectFromFile(file1, tempStaff))
    {
        if (tempStaff.getAname() == staff.getAname())
        {
            tempStaff = staff;
        }
        temp1 << tempStaff.getId() << "|" << tempStaff.getAname() << "|" << tempStaff.getPass() << "|" << tempStaff.getRole() << "|" << tempStaff.getStatus() << "|" << tempStaff.getName() << "|" << tempStaff.getSdt() << endl;
    }
    file1.close();
    temp1.close();
    system("del .\\account\\listStaff.txt");
    system("ren .\\account\\temp1.txt listStaff.txt");

    fstream file2("./account/listAccount.txt", ios::in);
    fstream temp2("./account/temp2.txt", ios::out);
    if (!file2.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp2.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    Account tempAccount;
    while (getObjectFromFile(file2, tempAccount))
    {
        if (tempAccount.getAname() == staff.getAname())
        {
            tempAccount.setPass(staff.getPass());
            tempAccount.setRole(staff.getRole());
            tempAccount.setStatus(staff.getStatus());
        }
        temp2 << tempAccount.getAname() << "|" << tempAccount.getPass() << "|" << tempAccount.getRole() << "|" << tempAccount.getStatus() << endl;
    }
    file2.close();
    temp2.close();
    system("del .\\account\\listAccount.txt");
    system("ren .\\account\\temp2.txt listAccount.txt");
}

// Dish
void updateDishToFile(Dish dish)
{
    fstream file1("./dish/listDish.txt", ios::in);
    fstream temp1("./dish/temp1.txt", ios::out);
    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    Dish tempDish;
    while (getObjectFromFile(file1, tempDish))
    {
        if (tempDish.getName() == dish.getName())
        {
            tempDish = dish;
        }
        temp1 << tempDish.getId() << "|" << tempDish.getName() << "|" << tempDish.getPrice() << "|" << tempDish.getUnit() << "|" << tempDish.getResidual() << endl;
    }
    file1.close();
    temp1.close();
    system("del .\\dish\\listDish.txt");
    system("ren .\\dish\\temp1.txt listDish.txt");
}

// Customer
void updateCustomerToFile(Customer customer)
{
    fstream file1("./customer/listCustomer.txt", ios::in);
    fstream temp1("./customer/temp1.txt", ios::out);
    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    Customer tempCustomer;
    while (getObjectFromFile(file1, tempCustomer))
    {
        if (tempCustomer.getName() == customer.getName())
        {
            tempCustomer = customer;
        }
        temp1 << tempCustomer.getId() << "|" << tempCustomer.getName() << "|" << tempCustomer.getSdt() << "|" << tempCustomer.getEmail() << "|" << tempCustomer.getContribute() << endl;
    }
    file1.close();
    temp1.close();
    system("del .\\customer\\listCustomer.txt");
    system("ren .\\customer\\temp1.txt listCustomer.txt");
}

// Computer

void updateComputerToFile(Computer computer)
{

    fstream file1("./computer/listComputer.txt", ios::in);
    fstream temp("./computer/temp.txt", ios::out);

    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }

    Computer tempComputer;
    while (getObjectFromFile(file1, tempComputer))
    {
        if (tempComputer.getName() == computer.getName())
        {
            tempComputer = computer;
        }
        temp << tempComputer.getName() << "|" << tempComputer.getCost() << "|" << tempComputer.getStatus() << "|" << tempComputer.getType() << "|" << tempComputer.getTotaltime() << endl;
    }

    file1.close();
    temp.close();
    deleteAndRenameFile("./computer/listComputer.txt", "./computer/temp.txt");
}

// gộp lại
void deleteAndRenameFile(string oldPath, string newPath)
{
    // oldpath: ./account/emptyID.txt";  => newOldPath: account\\emptyID.txt
    //      newpath: ./account/temp.txt  => newNewPath: account\\temp.txt

    std::string newOldPath = oldPath.substr(2);                    // Bỏ qua "./"
    std::replace(newOldPath.begin(), newOldPath.end(), '/', '\\'); // Thay thế '/' bằng '\'

    std::string newNewPath = newPath.substr(2);                    // Bỏ qua "./"
    std::replace(newNewPath.begin(), newNewPath.end(), '/', '\\'); // Thay thế '/' bằng '\'

    system(("del " + newOldPath).c_str());

    // newOldPath: account\\EmptyID.txt => newNewPath: emptyID.txt
    newOldPath = newOldPath.substr(newOldPath.find_first_of("\\") + 1);

    system(("ren " + newNewPath + " " + newOldPath).c_str());
}

int numberFromEmptyId(string path)
{
    int count = -1;
    // vd: path: ./account/EmptyID.txt";
    //     tempath: ./account/temp.txt

    fstream file(path, ios::in);

    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }

    if (dataOfEmptyId(file, count))
    {
        int ans = count;
        string tempPath = path.substr(0, path.find_last_of("/")) + "/temp.txt"; // "\\" không cần thiết
        fstream temp(tempPath, ios::out);
        if (!temp.is_open())
        {
            cout << "Không thể mở file" << endl;
            return count;
        }

        while (dataOfEmptyId(file, count))
        {
            temp << count << endl;
        }
        file.close();
        temp.close();
        deleteAndRenameFile(path, tempPath);
        temp.close();
        return ans;
    }
    file.close();

    return count;
}

int getNumber(string path)
{
    int count = -1;
    fstream file(path, ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    else
        file >> count;
    file.close();
    return count;
}

void updateNumber(string path, int count)
{
    fstream file(path, ios::out);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    file << count;
    file.close();
}

// gộp hàm bạn
template <class T>
bool getObjectFromFile(fstream &file, T &object)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;

    stringstream ss(line);

    if constexpr (is_same_v<T, Customer>)
    {
        string temp;
        getline(ss, temp, '|');
        object.setId(temp);
        getline(ss, temp, '|');
        object.setName(temp);
        getline(ss, temp, '|');
        object.setSdt(temp);
        getline(ss, temp, '|');
        object.setEmail(temp);
        getline(ss, temp);
        object.setContribute(temp);
    }
    else if constexpr (is_same_v<T, Computer>)
    {
        string temp;
        getline(ss, temp, '|');
        object.setName(temp);
        getline(ss, temp, '|');
        object.setCost(temp);
        getline(ss, temp, '|');
        object.setStatus(temp);
        getline(ss, temp, '|');
        object.setType(temp);
        getline(ss, temp);
        object.setTotaltime(temp);
    }
    else if constexpr (is_same_v<T, Dish>)
    {
        string temp;
        getline(ss, temp, '|');
        object.setId(temp);
        getline(ss, temp, '|');
        object.setName(temp);
        getline(ss, temp, '|');
        object.setPrice(temp);
        getline(ss, temp, '|');
        object.setUnit(temp);
        getline(ss, temp);
        object.setResidual(temp);
    }
    else if constexpr (is_same_v<T, Staff>)
    {
        string temp;
        getline(ss, temp, '|');
        object.setId(temp);
        getline(ss, temp, '|');
        object.setAname(temp);
        getline(ss, temp, '|');
        object.setPass(temp);
        getline(ss, temp, '|');
        object.setRole(temp);
        getline(ss, temp, '|');
        object.setStatus(temp);
        getline(ss, temp, '|');
        object.setName(temp);
        getline(ss, temp);
        object.setSdt(temp);
    }
    else if constexpr (is_same_v<T, Account>)
    {
        string temp;
        getline(ss, temp, '|');
        object.setAname(temp);
        getline(ss, temp, '|');
        object.setPass(temp);
        getline(ss, temp, '|');
        object.setRole(temp);
        getline(ss, temp);
        object.setStatus(temp);
    }

    return true;
}

// Explicit instantiation
template bool getObjectFromFile<Customer>(fstream &file, Customer &object);
template bool getObjectFromFile<Computer>(fstream &file, Computer &object);
template bool getObjectFromFile<Dish>(fstream &file, Dish &object);
template bool getObjectFromFile<Staff>(fstream &file, Staff &object);
template bool getObjectFromFile<Account>(fstream &file, Account &object);

template <class T>
bool checkObject(T &object)
{
    string filename;
    if constexpr (is_same_v<T, Staff>)
    {
        filename = "./account/listStaff.txt";
    }
    else if constexpr (is_same_v<T, Dish>)
    {
        filename = "./dish/listDish.txt";
    }
    else if constexpr (is_same_v<T, Customer>)
    {
        filename = "./customer/listCustomer.txt";
    }
    else if constexpr (is_same_v<T, Computer>)
    {
        filename = "./computer/listComputer.txt";
    }
    else
    {
        cout << "Không tìm thấy file" << endl;
        return false;
    }

    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }

    T temp;
    while (getObjectFromFile(file, temp))
    {
        if (temp.getName() == object.getName())
        {
            object = temp;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Explicit instantiation
template bool checkObject<Customer>(Customer &object);
template bool checkObject<Computer>(Computer &object);
template bool checkObject<Dish>(Dish &object);
template bool checkObject<Staff>(Staff &object);
