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
            cout << " 1.Xem thông tin món ăn       ";
            break;
        case 2:
            cout << " 2.Thay đổi giá               ";
            break;
        case 3:
            cout << " 3.Thay đổi số lượng          ";
            break;
        case 4:
            cout << " 4.Xóa món ăn                 ";
            break;
        case 5:
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
        return 5;
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

        computer.setId(id);
        if (checkComputer(computer))
        {
            ShowCursor(false);
            system("cls");
            SetConsoleTitle(TEXT("Menu quản lí thông tin máy"));            
            int selectOption = 1;

            while (true)
            {             
                showMenu("SEENCOMPUTER", selectOption);

                Gotoxy(1,1);
                int space = (30 - computer.getId().length()) / 2;
                for(int i = 0; i < space; i++)
                    cout << " ";
                cout << computer.getId() << endl;

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
        if (checkCustomer(customer))
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
                showMenu("SEENSTAFF", selectOption);

                Gotoxy(1, 1);
                int space = (30- staff.getName().length())/2;        
                for(int i=1; i<=space; i++)
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
        if (checkDish(dish))
        {
            ShowCursor(false);
            system("cls");
            SetConsoleTitle(TEXT("Menu thay đổi thông tin món ăn"));
            int selectOption = 1;

            while (true)
            {               
                showMenu("CHANGEDISH", selectOption);

                Gotoxy(1,1);
                int space = (30 - dish.getName().length()) / 2;
                for(int i = 0; i < space; i++)
                    cout << " ";
                cout << dish.getName() << endl;                

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