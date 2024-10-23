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
    cout << "(Nhấn ENTER để thoát)";
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

void EnterNumber(string &x, int max, int min)
{
    char ch;
    x.clear(); // Xóa chuỗi để nhập mới

    while (true)
    {
        ch = _getch(); // Lấy phím người dùng nhập vào mà không hiển th
        if (ch == 13)
        {
            if (x.length() < min)
            {
            }
            else
            {
                break;
            }
        }
        else if (ch == 8)
        { // Phím Backspace
            if (!x.empty())
            {
                x.pop_back();
                cout << "\b \b"; // Xóa ký tự cuối cùng
            }
        }
        else if (x.length() < max && isdigit(ch))
        {
            x += ch;
            cout << ch;
        }
    }
}

void EnterNumber(string &x, int n)
{
    char ch;
    x.clear(); // Xóa chuỗi để nhập mới

    while (true)
    {
        ch = _getch(); // Lấy phím người dùng nhập vào mà không hiển thị lên màn hình

        if (ch == 13)
        { // Phím Enter
            if (x.empty())
            {
                //
            }
            else
            {
                break;
            }
        }
        else if (ch == 8)
        { // Phím Backspace
            if (!x.empty())
            {
                x.pop_back();
                cout << "\b \b"; // Xóa ký tự cuối cùng khỏi màn hình
            }
        }
        else if (x.length() < n && isdigit(ch))
        { // Chỉ cho phép nhập số và giới hạn ký tự
            x += ch;
            cout << ch;
        }
    }
}

void EnterString(string &x, int n)
{
    char ch;
    x.clear(); // Xóa chuỗi để nhập mới

    while (true)
    {
        ch = _getch(); // Lấy phím người dùng nhập vào mà không hiển thị lên m
        if (ch == 13)
        { // Phím Enter
            if (x.empty())
            {
                //
            }
            else
            {
                break;
            }
        }
        else if (ch == 8)
        { // Phím Backspace
            if (!x.empty())
            {
                x.pop_back();
                cout << "\b \b"; // Xóa ký tự cuối cùng
            }
        }
        else if (x.length() < n)
        {
            x += ch;
            cout << ch;
        }
    }
}

void EnterLetter(string &x, int n)
{
    char ch;
    x.clear(); // Xóa chuỗi để nhập mới

    while (true)
    {
        ch = _getch(); // Lấy phím người dùng nhập vào mà không hiển th
        if (ch == 13)
        {
            if (x.empty())
            {
                //
            }
            else
            {
                break;
            }
        }
        else if (ch == 8)
        { // Phím Backspace
            if (!x.empty())
            {
                x.pop_back();
                cout << "\b \b"; // Xóa ký tự cuối cùng
            }
        }
        else if (x.length() < n && isalpha(ch))
        {
            x += ch;
            cout << ch;
        }
    }
}

void toName(string &str)
{
    trim(str);
    toLower(str);
    for (int i = 0; i < str.size(); i++)
    {
        if ((i == 0 || (i > 0 && str[i - 1] == ' ')) && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

void trim(string &str)
{
    while (str[0] == ' ')
        str.erase(0, 1); // Xóa 1 ký tự từ vị trí 0
    while (str[str.size() - 1] == ' ')
        str.erase(str.size() - 1, 1);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(i, 1);
            i--;
        }
    }
}

void toLower(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

/*------------------------------------MENU------------------------------------*/

// Hiển thị các tùy chọn của menu dựa trên loại và tùy chọn được chọn
void optionMenu(string typeMenu, int option)
{
    if (typeMenu == "MENUADMIN")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Quản lí máy tính          ";
            break;
        case 2:
            cout << " 2. Quản lí nhân viên         ";
            break;
        case 3:
            cout << " 3. Quản lí khách hàng        ";
            break;
        case 4:
            cout << " 4. Quản lí món ăn            ";
            break;
        case 5:
            cout << " 5. Xem lịch sử               ";
            break;
        case 6:
            cout << " 6. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "STAFF")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Quản lí máy tính          ";
            break;
        case 2:
            cout << " 2. Quản lí khách hàng        ";
            break;
        case 3:
            cout << " 3. Xem lịch sử               ";
            break;
        case 4:
            cout << " 4. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "MANAGECOMPUTER")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Thêm máy tính             ";
            break;
        case 2:
            cout << " 2. Xem thông tin máy         ";
            break;
        case 3:
            cout << " 3. Xem danh sách máy         ";
            break;
        case 4:
            cout << " 4. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "MANAGESTAFF")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Thêm nhân viên            ";
            break;
        case 2:
            cout << " 2. Xem thông tin nhân viên   ";
            break;
        case 3:
            cout << " 3. Xem danh sách nhân viên   ";
            break;
        case 4:
            cout << " 4. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "MANAGECUSTOMER")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Thêm khách hàng           ";
            break;
        case 2:
            cout << " 2. Xem thông tin khách hàng  ";
            break;
        case 3:
            cout << " 3. Xem danh sách khách hàng  ";
            break;
        case 4:
            cout << " 4. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "MANAGEDISH")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Thêm thực phẩm            ";
            break;
        case 2:
            cout << " 2. Xem thông tin thực phẩm   ";
            break;
        case 3:
            cout << " 3. Xem danh sách thực phẩm   ";
            break;
        case 4:
            cout << " 4. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "CHANGEDISH")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Thay đổi giá              ";
            break;
        case 2:
            cout << " 2. Thay đổi số lượng         ";
            break;
        case 3:
            cout << " 3. Xóa thực phẩm             ";
            break;
        case 4:
            cout << " 4. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "ENTERID")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Nhập ID      ";
            break;
        case 2:
            cout << " 2. Thoát        ";
            break;
        }
    }
    else if (typeMenu == "ADD")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Nhập        ";
            break;
        case 2:
            cout << " 2. Thoát       ";
            break;
        }
    }
    else if (typeMenu == "CHANGECUSTOMER")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Xóa khách hàng            ";
            break;
        case 2:
            cout << " 2. Thoát                    ";
            break;
        }
    }
    else if (typeMenu == "CHANGESTAFF")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Thay đổi mật khẩu         ";
            break;
        case 2:
            cout << " 2. Xóa nhân viên             ";
            break;
        case 3:
            cout << " 3. Thoát                    ";
            break;
        }
    }
    else if (typeMenu == "TYPECOMPUTER")
    {
        switch (option)
        {
        case 1:
            cout << "Binh thuong";
            break;
        case 2:
            cout << "Cao cap    ";
            break;
        case 3:
            cout << "Cap doi    ";
            break;
        case 4:
            cout << "Thi dau    ";
            break;
        case 5:
            cout << "Stream     ";
            break;
        }
    }
    else if (typeMenu == "CHANGECOMPUTER")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Thay đổi giá tiền         ";
            break;
        case 2:
            cout << " 2. Xóa máy                   ";
            break;
        case 3:
            cout << " 3. Thoát                     ";
            break;
        }
    }
    else if (typeMenu == "TYPESORT")
    {
        switch (option)
        {
        case 1:
            cout << " Tăng dần ";
            break;
        case 2:
            cout << " Giảm dần ";
            break;
        }
    }
    else if (typeMenu =="SORTDISH")
    {
        switch (option)
        {
        case 1:
            cout << " 1. Sắp xếp theo ID           ";
            break;
        case 2:
            cout << " 2. Sắp xếp theo giá          ";
            break;
        case 3:
            cout << " 3. Sắp xếp theo số lượng     ";
            break;
        case 4:
            cout << " 4. Thoát                     ";
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
    if (typeMenu == "MENUADMIN")
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
    if (typeMenu == "ENTERID")
        return 2;
    if (typeMenu == "ADD")
        return 2;
    if (typeMenu == "CHANGECUSTOMER")
        return 2;
    if (typeMenu == "CHANGESTAFF")
        return 3;
    if (typeMenu == "TYPECOMPUTER")
        return 5;
    if (typeMenu == "CHANGECOMPUTER")
        return 3;
    if (typeMenu == "TYPESORT")
        return 2;
    if (typeMenu == "SORTDISH")
        return 4;

    // Các loại menu khác...

    // Mặc định nếu không tìm thấy menu
    return 0;
}

void showMenu(string typeMenu, int selectOption, int x, int y)
{
    int optionCount = getMenuOptionCount(typeMenu);
    if (optionCount > 0)
    {
        Gotoxy(x, y);
        for (int i = 1; i <= optionCount; ++i)
        {
            printMenuOption(typeMenu, i, i == selectOption);
            Gotoxy(x, y + i);
        }
    }
}

void menuMain(int n, int x, int y)
{
    Gotoxy(x, y);
    cout << "╔══════════════════════════════╗";
    Gotoxy(x, y + 1);
    cout << "║                              ║";
    Gotoxy(x, y + 2);
    cout << "╠══════════════════════════════╣";   
    for (int i = 0; i < n; i++)
    {   
        Gotoxy(x, y + 3 + i);
        cout << "║                              ║" ;
    }
    Gotoxy(x, y + 3 + n);
    cout << "╚══════════════════════════════╝" ;
}

void menuAdd(int x, int y)
{
    Gotoxy(x, y);
    cout << "╔════════════════╗" << endl;
    Gotoxy(x, y + 1);
    cout << "║ Nhập thông tin ║" << endl;
    Gotoxy(x, y + 2);
    cout << "╠════════════════╣" << endl;
    Gotoxy(x, y + 3);
    cout << "║                ║" << endl;
    Gotoxy(x, y + 4);
    cout << "║                ║" << endl;
    Gotoxy(x, y + 5);
    cout << "╚════════════════╝" << endl;
}

void menuSelectTypeSort(int x, int y)
{
    Gotoxy(x, y);
    cout << "   ┌──────────┐";
    Gotoxy(x, y + 1);
    cout << "❯❯ │          │";
    Gotoxy(x, y + 2);
    cout << "❯❯ │          │";
    Gotoxy(x, y + 3);
    cout << "   └──────────┘";
}
/*------------------------------------MenusAdmin------------------------------------*/

// Menu chính dành cho admin
void menuAdmin(Admin admin)
{

    ShowCursor(false);
    system("cls");
    int selectOption = 1;

    while (true)
    {
        menuMain(getMenuOptionCount("MENUADMIN"), 0, 0);
        showMenu("MENUADMIN", selectOption, 1, 3);
        Gotoxy(11, 1);
        cout << "Menu Admin";
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
                admin.setStatus("OFFLINE");
                updateAdminToFile(admin);
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
    int selectOption = 1;

    while (true)
    {
        menuMain(getMenuOptionCount("MANAGECOMPUTER"), 0, 0);
        showMenu("MANAGECOMPUTER", selectOption, 1, 3);
        Gotoxy(8, 1);
        cout << "Quản lí máy tính";
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
                menuAddComputer(admin);
                break;
            case 2:
                findComputer(admin);
                break;
            case 3:
                admin.seenListComputer();
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void menuAddComputer(Admin admin)
{
    system("cls");
    ShowCursor(false);

    menuAdd(0, 0);

    Gotoxy(20, 0);
    cout << "      ╔══════════════════════════╗─────────────────┐";
    Gotoxy(20, 1);
    cout << "      ║       Thêm máy tính      ║ Bảng giá cơ bản │";
    Gotoxy(20, 2);
    cout << "      ╠══════════════════════════╣─────────────────┤";
    Gotoxy(20, 3);
    cout << "❯❯❯❯  ║ 1. Giá:        (VND/h)   ║ Binh thuong: 10k│";
    Gotoxy(20, 4);
    cout << "      ║ 2. Loại:                 ║ Cao cap:     20k│";
    Gotoxy(20, 5);
    cout << "      ╚══════════════════════════╝ Cap doi:     30k│";
    Gotoxy(20, 6);
    cout << "                                 │ Thi dau:     30k│";
    Gotoxy(20, 7);
    cout << "                                 │ Stream:      50k│";
    Gotoxy(20, 8);
    cout << "                                 └─────────────────┘";

    int selectOption = 1;
    while (true)
    {
        showMenu("ADD", selectOption, 1, 3);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 2 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 2) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                addComputer(admin);
                break;
            case 2:
                system("cls");
                return;
            }
            break;
        }
    }
    ShowCursor(true);
}

void addComputer(Admin admin)
{
    ShowCursor(true);
    Computer computer;

    if (cin >> computer)
    {
        admin.addComputer(computer);
        ShowCursor(false);
        Gotoxy(26, 6);
        Sleep(200);
        cout << "Thêm máy thành công";
        Sleep(700);
        ClearLine(26, 6, 19);
    }
}

void findComputer(Admin admin)
{
    system("cls");
    int selectOption = 1;
    while (true)
    {
        Computer computer;

        Gotoxy(0, 0);
        cout << "╔════════════════════════════╗" << endl;
        cout << "║ Danh sách máy tính hiện có ║" << endl;
        cout << "╠═════════════════════╦══════╣" << endl;
        cout << "║    Loại máy tính    ║  ID  ║" << endl;
        cout << "╠═════════════════════╬══════╣" << endl;

        fstream file("./computer/listComputer.txt", ios::in);
        Computer temp;
        int i = 0;
        while (getObjectFromFile(file, temp))
        {
            cout << "║ " << ++i << ". " << setw(17) << left << temp.getType() << "║ " << temp.getId() << " ║" << endl;
            cout << "╠═════════════════════╬══════╣" << endl;
        }
        Gotoxy(0, 4 + i * 2);
        cout << "╚═════════════════════╩══════╝" << endl;
        file.close();

        Gotoxy(35, 0);
        cout << "╔════════════════════════╗";
        Gotoxy(35, 1);
        cout << "║   Tìm kiếm máy tính    ║";
        Gotoxy(35, 2);
        cout << "╠═════════════════╦══════╣";
        Gotoxy(35, 3);
        cout << "║                 ║  ID  ║";
        Gotoxy(35, 4);
        cout << "║                 ║ .... ║";
        Gotoxy(35, 5);
        cout << "╚═════════════════╩══════╝";
        showMenu("ENTERID", selectOption, 36, 3);

        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 2 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 2) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                changeComputer(admin, computer);
                break;
            case 2:
                system("cls");
                return;
            }
            break;
        }
    }
}

void changeComputer(Admin admin, Computer &computer)
{
    ShowCursor(true);
    ClearLine(55, 4, 4);
    Gotoxy(55, 4);
    string id;
    EnterString(id, 4);
    computer.setId(id);
    ShowCursor(false);

    if (checkIdObject(computer))
    {
        system("cls");
        Gotoxy(34, 0);
        cout << "      ╔═══════════════════════════════════════╗";
        Gotoxy(34, 1);
        cout << "      ║               Thông tin               ║";
        Gotoxy(34, 2);
        cout << "      ╠═══════════════════════════════════════╣";
        Gotoxy(34, 3);
        cout << "❯❯❯❯  ║        Giá:                  ID:      ║";
        Gotoxy(34, 4);
        cout << "      ║       Loại:                           ║";
        Gotoxy(34, 5);
        cout << "      ║  Thời gian:                           ║";
        Gotoxy(34, 6);
        cout << "      ║ Trạng thái:                           ║";
        Gotoxy(34, 7);
        cout << "      ╚═══════════════════════════════════════╝";

        menuMain(getMenuOptionCount("CHANGECOMPUTER"), 0, 0);
        Gotoxy((32 - computer.getId().length()) / 2, 1);
        cout << computer.getId();
        Gotoxy(75, 3);
        cout << computer.getId();
        Gotoxy(54, 4);
        cout << computer.getType();
        Gotoxy(54, 5);
        cout << computer.getTotaltime();
        Gotoxy(54, 6);
        cout << computer.getStatus();

        int selectOption = 1;
        while (true)
        {
            Gotoxy(54, 3);
            cout << computer.getCost() << " (VND/h)";

            showMenu("CHANGECOMPUTER", selectOption, 1, 3);
            int key = _getch();
            switch (key)
            {
            case KEY_UP:
                selectOption = (selectOption == 1) ? 3 : selectOption - 1;
                break;
            case KEY_DOWN:
                selectOption = (selectOption == 3) ? 1 : selectOption + 1;
                break;
            case KEY_ENTER:
                switch (selectOption)
                {
                case 1:
                    admin.changeCost(computer);
                    break;
                case 2:
                    admin.deleteComputer(computer);
                    Sleep(200);
                    system("cls");
                    cout << "Xóa máy thành công";
                    Sleep(1200);
                    system("cls");
                    return;

                case 3:
                    system("cls");
                    return;
                }
                break;
            }
        }
    }
    else
    {
        Gotoxy(35, 6);
        cout << "Không tìm thấy ID máy";
        Sleep(1000);
        ClearLine(35, 6, 21);
    }
}

void manageCustomer(Admin admin)
{
    system("cls");
    int selectOption = 1;

    while (true)
    {
        menuMain(getMenuOptionCount("MANAGECUSTOMER"), 0, 0);
        showMenu("MANAGECUSTOMER", selectOption, 1, 3);
        Gotoxy(7, 1);
        cout << "Quản lí khách hàng";
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
                menuAddCustomer(admin);
                break;
            case 2:
                findCustomer(admin);
                break;
            case 3:
                admin.seenListCustomer();
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void menuAddCustomer(Admin admin)
{
    system("cls");
    ShowCursor(false);

    menuAdd(0, 0);

    Gotoxy(20, 0);
    cout << "      ╔══════════════════════════════════════════════╗";
    Gotoxy(20, 1);
    cout << "      ║               Thêm khách hàng                ║";
    Gotoxy(20, 2);
    cout << "      ╠══════════════════════════════════════════════╣";
    Gotoxy(20, 3);
    cout << "❯❯❯❯  ║ 1. Họ và tên:                                ║";
    Gotoxy(20, 4);
    cout << "      ║ 2. Số điện thoại:                            ║";
    Gotoxy(20, 5);
    cout << "      ║ 3. Email:                                    ║";
    Gotoxy(20, 6);
    cout << "      ╚══════════════════════════════════════════════╝";

    int selectOption = 1;
    while (true)
    {
        showMenu("ADD", selectOption, 1, 3);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 2 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 2) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                addCustomer(admin);
                break;
            case 2:
                system("cls");
                return;
            }
        }
    }
    ShowCursor(true);
}
void addCustomer(Admin admin)
{
    ShowCursor(true);
    Customer customer;

    if (cin >> customer)
    {
        admin.addCustomer(customer);
        ShowCursor(false);
        Gotoxy(26, 7);
        Sleep(200);
        cout << "Thêm khách hàng thành công" << endl;
        Sleep(700);
        ClearLine(26, 7, 35);
    }
}
void findCustomer(Admin admin)
{
    int selectOption = 1;
    while (true)
    {
        Customer customer;

        Gotoxy(0, 0);
        cout << "╔══════════════════════════════════════════╗" << endl;
        cout << "║       Danh sách khách hàng hiện có       ║" << endl;
        cout << "╠═══════════════════════════════════╦══════╣" << endl;
        cout << "║          Tên khách hàng           ║  ID  ║" << endl;
        cout << "╠═══════════════════════════════════╬══════╣" << endl;

        fstream file("./customer/listCustomer.txt", ios::in);
        Customer temp;
        int i = 0;
        while (getObjectFromFile(file, temp))
        {
            cout << "║ " << ++i << ". " << setw(31) << left << temp.getName() << "║ " << temp.getId() << " ║" << endl;
            cout << "╠═══════════════════════════════════╬══════╣" << endl;
        }
        Gotoxy(0, 4 + i * 2);
        cout << "╚═══════════════════════════════════╩══════╝" << endl;
        file.close();

        Gotoxy(49, 0);
        cout << "╔════════════════════════╗";
        Gotoxy(49, 1);
        cout << "║  Tìm kiếm khách hàng   ║";
        Gotoxy(49, 2);
        cout << "╠═════════════════╦══════╣";
        Gotoxy(49, 3);
        cout << "║                 ║  ID  ║";
        Gotoxy(49, 4);
        cout << "║                 ║ .... ║";
        Gotoxy(49, 5);
        cout << "╚═════════════════╩══════╝";
        showMenu("ENTERID", selectOption, 50, 3);

        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 2 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 2) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                changeCustomer(admin, customer);
                break;
            case 2:
                system("cls");
                return;
            }
        }
    }
}

void changeCustomer(Admin admin, Customer &customer)
{
    ShowCursor(true);
    ClearLine(69, 4, 4);
    Gotoxy(69, 4);
    string id;
    EnterString(id, 4);
    customer.setId(id);
    ShowCursor(false);

    if (checkIdObject(customer))
    {
        system("cls");
        Gotoxy(34, 0);
        cout << "      ╔══════════════════════════════════════════════╗";
        Gotoxy(34, 1);
        cout << "      ║                  Thông tin                   ║";
        Gotoxy(34, 2);
        cout << "      ╠══════════════════════════════════════════════╣";
        Gotoxy(34, 3);
        cout << "❯❯❯❯  ║   Họ Tên:                           ID:      ║";
        Gotoxy(34, 4);
        cout << "      ║      Sđt:                                    ║";
        Gotoxy(34, 5);
        cout << "      ║    Email:                                    ║";
        Gotoxy(34, 6);
        cout << "      ║ Đóng góp:                                    ║";
        Gotoxy(34, 7);
        cout << "      ╚══════════════════════════════════════════════╝";

        menuMain(getMenuOptionCount("CHANGECUSTOMER"), 0, 0);
        Gotoxy((32 - customer.getName().length()) / 2, 1);
        cout << customer.getName();

        Gotoxy(82, 3);
        cout << customer.getId();
        Gotoxy(52, 3);
        cout << customer.getName();
        Gotoxy(52, 4);
        cout << customer.getSdt();
        Gotoxy(52, 5); //
        cout << customer.getEmail();
        Gotoxy(52, 6);
        cout << customer.getContribute() << " (VND)";

        int selectOption = 1;
        while (true)
        {
            showMenu("CHANGECUSTOMER", selectOption, 1, 3);
            int key = _getch();
            switch (key)
            {
            case KEY_UP:
                selectOption = (selectOption == 1) ? 2 : selectOption - 1;
                break;
            case KEY_DOWN:
                selectOption = (selectOption == 2) ? 1 : selectOption + 1;
                break;
            case KEY_ENTER:
                switch (selectOption)
                {
                case 1:
                    admin.deleteCustomer(customer);
                    Sleep(200);
                    system("cls");
                    cout << "Xóa khách hàng thành công" << endl;
                    Sleep(1200);
                    system("cls");
                    return;
                case 2:
                    system("cls");
                    return;
                }
            }
        }
    }
    else
    {
        Sleep(200);
        Gotoxy(49, 6);
        cout << "Không tìm thấy ID khách hàng";
        Sleep(700);
        ClearLine(49, 6, 28);
    }
}

void manageStaff(Admin admin)
{
    system("cls");
    int selectOption = 1;

    while (true)
    {
        menuMain(getMenuOptionCount("MANAGESTAFF"), 0, 0);
        showMenu("MANAGESTAFF", selectOption, 1, 3);
        Gotoxy(7, 1);
        cout << "Quản lí nhân viên";
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
                menuAddStaff(admin);
                break;
            case 2:
                findStaff(admin);
                break;
            case 3:
                admin.seenListStaff();
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void menuAddStaff(Admin admin)
{
    system("cls");
    ShowCursor(false);

    menuAdd(0, 0);

    Gotoxy(20, 0);
    cout << "      ╔═══════════════════════════════════════════════════════╗";
    Gotoxy(20, 1);
    cout << "      ║                    Thêm nhân viên                     ║";
    Gotoxy(20, 2);
    cout << "      ╠═══════════════════════════════════════════════════════╣";
    Gotoxy(20, 3);
    cout << "❯❯❯❯  ║ 1. Nhập tên nhân viên:                                ║";
    Gotoxy(20, 4);
    cout << "      ║ 2. Nhập số điện thoại:                                ║";
    Gotoxy(20, 5);
    cout << "      ║ 3. Nhập tài khoản:                                    ║";
    Gotoxy(20, 6);
    cout << "      ║ 4. Nhập mật khẩu:                                     ║";
    Gotoxy(20, 7);
    cout << "      ╚═══════════════════════════════════════════════════════╝";

    int selectOption = 1;
    while (true)
    {
        showMenu("ADD", selectOption, 1, 3);
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
                addStaff(admin);
                break;
            case 2:
                system("cls");
                return;
            }
        }
    }
    ShowCursor(true);
}

void addStaff(Admin admin)
{
    ShowCursor(true);
    Staff staff;

    if (cin >> staff)
    {
        admin.addStaff(staff);
        ShowCursor(false);
        Gotoxy(26, 8);
        Sleep(200);
        cout << "Thêm nhân viên thành công" << endl;
        Sleep(700);
        ClearLine(26, 8, 25);
    }
}

void findStaff(Admin admin)
{
    int selectOption = 1;
    while (true)
    {
        Staff staff;
        int count = 0;

        Gotoxy(0, 0);
        cout << "╔══════════════════════════════════════════╗" << endl
             << "║       Danh sách nhân viên hiện có        ║" << endl
             << "╠═══════════════════════════════════╦══════╣" << endl
             << "║          Tên nhân viên            ║  ID  ║" << endl
             << "╠═══════════════════════════════════╬══════╣" << endl;

        fstream file("./account/listStaff.txt", ios::in);
        Staff temp;
        int i = 0;
        while (getObjectFromFile(file, temp))
        {
            cout << "║ " << ++i << ". " << setw(31) << left << temp.getName() << "║ " << temp.getId() << " ║" << endl;
            cout << "╠═══════════════════════════════════╬══════╣" << endl;
        }
        Gotoxy(0, 4 + i * 2);
        cout << "╚═══════════════════════════════════╩══════╝" << endl;
        file.close();

        Gotoxy(49, 0);
        cout << "╔════════════════════════╗";
        Gotoxy(49, 1);
        cout << "║   Tìm kiếm nhân viên   ║";
        Gotoxy(49, 2);
        cout << "╠═════════════════╦══════╣";
        Gotoxy(49, 3);
        cout << "║                 ║  ID  ║";
        Gotoxy(49, 4);
        cout << "║                 ║ .... ║";
        Gotoxy(49, 5);
        cout << "╚═════════════════╩══════╝";
        showMenu("ENTERID", selectOption, 50, 3);

        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 2 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 2) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                changeStaff(admin, staff);
                break;
            case 2:
                system("cls");
                return;
            }
        }
    }
}
void changeStaff(Admin admin, Staff &staff)
{
    ShowCursor(true);
    ClearLine(69, 4, 4);
    Gotoxy(69, 4);
    string id;
    EnterString(id, 4);
    staff.setId(id);
    ShowCursor(false);

    if (checkIdObject(staff))
    {
        system("cls");
        Gotoxy(34, 0);
        cout << "      ╔═════════════════════════════════════════════════════╗";
        Gotoxy(34, 1);
        cout << "      ║                       Thông tin                     ║";
        Gotoxy(34, 2);
        cout << "      ╠═════════════════════════════════════════════════════╣";
        Gotoxy(34, 3);
        cout << "❯❯❯❯  ║     Họ Tên:                                ID:      ║";
        Gotoxy(34, 4);
        cout << "      ║        Sđt:                                         ║";
        Gotoxy(34, 5);
        cout << "      ║  Tài khoản:                                         ║";
        Gotoxy(34, 6);
        cout << "      ║   Mật khẩu:                                         ║";
        Gotoxy(34, 7);
        cout << "      ║  Doanh thu:                                         ║";
        Gotoxy(34, 8);
        cout << "      ║ Trạng thái:                                         ║";
        Gotoxy(34, 9);
        cout << "      ╚═════════════════════════════════════════════════════╝";

        menuMain(getMenuOptionCount("CHANGESTAFF"), 0, 0);

        Gotoxy((32 - staff.getName().length()) / 2, 1);
        cout << staff.getName();
        Gotoxy(54, 3);
        cout << staff.getName();
        Gotoxy(89, 3);
        cout << staff.getId();
        Gotoxy(54, 4);
        cout << staff.getSdt();
        Gotoxy(54, 7);
        cout << staff.getRevenue() << " (VND)";
        Gotoxy(54, 5);
        cout << staff.getAname();
        Gotoxy(54, 8);
        cout << staff.getStatus();

        int selectOption = 1;
        while (true)
        {
            Gotoxy(54, 6);
            cout << staff.getPass();

            showMenu("CHANGESTAFF", selectOption, 1, 3);
            int key = _getch();
            switch (key)
            {
            case KEY_UP:
                selectOption = (selectOption == 1) ? 3 : selectOption - 1;
                break;
            case KEY_DOWN:
                selectOption = (selectOption == 3) ? 1 : selectOption + 1;
                break;
            case KEY_ENTER:
                switch (selectOption)
                {
                case 1:
                    admin.changeSPassword(staff);
                    break;
                case 2:
                    admin.deleteStaff(staff);
                    Sleep(200);
                    system("cls");
                    cout << "Xóa nhân viên thành công" << endl;
                    Sleep(1200);
                    system("cls");
                    return;
                case 3:
                    system("cls");
                    return;
                }
            }
        }
    }
    else
    {
        Sleep(200);
        Gotoxy(49, 6);
        cout << "Không tìm thấy ID nhân viên";
        Sleep(700);
        ClearLine(49, 6, 27);
    }
}

void manageDish(Admin admin)
{
    system("cls");
    int selectOption = 1;

    while (true)
    {

        menuMain(getMenuOptionCount("MANAGEDISH"), 0, 0);
        showMenu("MANAGEDISH", selectOption, 1, 3);
        Gotoxy(7, 1);
        cout << "Quản lí thực phẩm";
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
                menuAddDish(admin);
                break;
            case 2:
                findDish(admin);
                break;
            case 3:
                admin.seenListDish();
                break;
            case 4:
                system("cls");
                return;
            }
            break;
        }
    }
}

void menuAddDish(Admin admin)
{
    system("cls");
    ShowCursor(false);

    menuAdd(0, 0);

    Gotoxy(20, 0);
    cout << "      ╔════════════════════════════════════════════╗";
    Gotoxy(20, 1);
    cout << "      ║              Thêm thực phẩm                ║";
    Gotoxy(20, 2);
    cout << "      ╠════════════════════════════════════════════╣──────────────────────┐";
    Gotoxy(20, 3);
    cout << "❯❯❯❯  ║ 1.Nhập tên thực phẩm:                      ║ Tên: Mi tom, Pepsi...│";
    Gotoxy(20, 4);
    cout << "      ║ 2.Nhập giá:        (VND)                   ║ Giá: 10000, 1200...  │";
    Gotoxy(20, 5);
    cout << "      ║ 3.Nhập đơn vị:                             ║ Đơn vị: lon, chai... │";
    Gotoxy(20, 6);
    cout << "      ║ 4.Nhập số lượng:                           ║ Số lượng: 50, 100... │";
    Gotoxy(20, 7);
    cout << "      ╚════════════════════════════════════════════╝──────────────────────┘";

    int selectOption = 1;
    while (true)
    {
        showMenu("ADD", selectOption, 1, 3);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 2 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 2) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                addDish(admin);
                break;
            case 2:
                system("cls");
                return;
            }
        }
    }
    ShowCursor(true);
}

void addDish(Admin admin)
{
    ShowCursor(true);
    Dish dish;

    if (cin >> dish)
    {
        admin.addDish(dish);
        ShowCursor(false);
        Gotoxy(26, 8);
        Sleep(200);
        cout << "Thêm thực phẩm thành công" << endl;
        Sleep(700);
        ClearLine(26, 8, 25);
    }
}

void findDish(Admin admin)
{
    int selectOption = 1;
    while (true)
    {
        Dish dish;
        int count = 0;

        Gotoxy(0, 0);
        cout << "╔═══════════════════════════════╗" << endl
             << "║  Danh sách thực phẩm hiện có  ║" << endl
             << "╠════════════════════════╦══════╣" << endl
             << "║     Tên thực phẩm      ║  ID  ║" << endl
             << "╠════════════════════════╬══════╣" << endl;

        fstream file("./dish/listDish.txt", ios::in);
        Dish temp;
        int i = 0;
        while (getObjectFromFile(file, temp))
        {
            cout << "║ " << ++i << ". " << setw(20) << left << temp.getName() << "║ " << temp.getId() << " ║" << endl;
            cout << "╠════════════════════════╬══════╣" << endl;
        }
        Gotoxy(0, 4 + i * 2);
        cout << "╚════════════════════════╩══════╝" << endl;
        file.close();

        Gotoxy(38, 0);
        cout << "╔════════════════════════╗";
        Gotoxy(38, 1);
        cout << "║   Tìm kiếm thực phẩm   ║ ";
        Gotoxy(38, 2);
        cout << "╠═════════════════╦══════╣";
        Gotoxy(38, 3);
        cout << "║                 ║  ID  ║";
        Gotoxy(38, 4);
        cout << "║                 ║ .... ║";
        Gotoxy(38, 5);
        cout << "╚═════════════════╩══════╝";
        showMenu("ENTERID", selectOption, 39, 3);

        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 2 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 2) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                changeDish(admin, dish);
                break;
            case 2:
                system("cls");
                return;
            }
        }
    }
}

void changeDish(Admin admin, Dish &dish)
{
    ShowCursor(true);
    ClearLine(58, 4, 4);
    Gotoxy(58, 4);
    string id;
    EnterString(id, 4);
    dish.setId(id);
    ShowCursor(false);

    if (checkIdObject(dish))
    {
        system("cls");
        Gotoxy(34, 0);
        cout << "      ╔═══════════════════════════════════════╗";
        Gotoxy(34, 1);
        cout << "      ║               Thông tin               ║";
        Gotoxy(34, 2);
        cout << "      ╠═══════════════════════════════════════╣";
        Gotoxy(34, 3);
        cout << "❯❯❯❯  ║ Tên:                     ID:          ║────────────────────┐";
        Gotoxy(34, 4);
        cout << "❯❯❯❯  ║ Giá:                     Đơn vị:      ║ Giá: 10000,1200... │";
        Gotoxy(34, 5);
        cout << "      ║ Số lượng:                             ║ Số lượng: 50,100...│";
        Gotoxy(34, 6);
        cout << "      ╚═══════════════════════════════════════╝────────────────────┘";

        menuMain(getMenuOptionCount("CHANGEDISH"), 0, 0);

        int selectOption = 1;
        while (true)
        {
            Gotoxy(47, 3);
            cout << dish.getName();
            Gotoxy(71, 3);
            cout << dish.getId();
            Gotoxy(47, 4);
            cout << dish.getPrice() << " (VND)";
            Gotoxy(75, 4);
            cout << dish.getUnit();
            Gotoxy(52, 5);
            cout << dish.getResidual();
            Gotoxy((32 - dish.getName().length()) / 2, 1);
            cout << dish.getName();

            showMenu("CHANGEDISH", selectOption, 1, 3);
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
                    admin.changeCost(dish);
                    break;
                case 2:
                    admin.addQuanlity(dish);
                    break;
                case 3:
                    admin.deleteDish(dish);
                    Sleep(200);
                    system("cls");
                    cout << "Xóa thực phẩm thành công" << endl;
                    Sleep(1200);
                    system("cls");
                    return;
                case 4:
                    system("cls");
                    return;
                }
                break;
            }
        }
    }
    else
    {
        Sleep(200);
        Gotoxy(38, 6);
        cout << "Không tìm thấy ID thực phẩm";
        Sleep(700);
        ClearLine(38, 6, 27);
    }
}

/*------------------------------------Menustaff------------------------------------*/
void menuStaff(Staff staff)
{
    ShowCursor(false);
    system("cls");
    int selectOption = 1;
    while (true)
    {
        Gotoxy(11, 1);
        cout << "Menu Staff";
        menuMain(6, 0, 0);
        showMenu("STAFF", selectOption, 1, 3);
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
            case 4:
                system("cls");
                staff.setStatus("OFFLINE");
                updateStaffToFile(staff);
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

// Admin
void updateAdminToFile(Admin admin)
{
    fstream file1("./account/listAccount.txt", ios::in);
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
    Account tempAccount;
    while (getObjectFromFile(file1, tempAccount))
    {
        if (tempAccount.getAname() == admin.getAname())
        {
            tempAccount.setPass(admin.getPass());
            tempAccount.setRole(admin.getRole());
            tempAccount.setStatus(admin.getStatus());
        }
        temp1 << tempAccount.getAname() << "|" << tempAccount.getPass() << "|" << tempAccount.getRole() << "|" << tempAccount.getStatus() << endl;
    }

    file1.close();
    temp1.close();
    system("del .\\account\\listAccount.txt");
    system("ren .\\account\\temp1.txt listAccount.txt");
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
        temp1 << tempStaff.getId() << "|" << tempStaff.getAname() << "|" << tempStaff.getPass() << "|" << tempStaff.getRole() << "|" << tempStaff.getStatus() << "|" << tempStaff.getName() << "|" << tempStaff.getSdt() << "|" << tempStaff.getRevenue() << endl;
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
        if (tempComputer.getId() == computer.getId())
        {
            tempComputer = computer;
        }
        temp << tempComputer.getId() << "|" << tempComputer.getCost() << "|" << tempComputer.getStatus() << "|" << tempComputer.getType() << "|" << tempComputer.getTotaltime() << endl;
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
        object.setId(temp);
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
        getline(ss, temp, '|');
        object.setSdt(temp);
        getline(ss, temp);
        object.setRevenue(temp);
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
bool checkIdObject(T &object)
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
        if (temp.getId() == object.getId())
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
template bool checkIdObject<Customer>(Customer &object);
template bool checkIdObject<Computer>(Computer &object);
template bool checkIdObject<Dish>(Dish &object);
template bool checkIdObject<Staff>(Staff &object);

template <class T>
bool checkNameObject(T &object)
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
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Explicit instantiation
template bool checkNameObject<Customer>(Customer &object);
template bool checkNameObject<Dish>(Dish &object);
template bool checkNameObject<Staff>(Staff &object);

bool checkAname(string aname)
{
    fstream file("./account/listAccount.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }
    Account temp;
    while (getObjectFromFile(file, temp))
    {
        if (temp.getAname() == aname)
        {
            return true;
        }
    }
    file.close();
    return false;
}

bool checkAnameStaff(Staff &staff)
{
    fstream file("./account/listStaff.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }
    Staff temp;
    while (getObjectFromFile(file, temp))
    {
        if (temp.getAname() == staff.getAname())
        {
            staff = temp;
            return true;
        }
    }
    file.close();
    return false;
}

bool compareByDishAsc(Dish object1, Dish object2, string type)
{

    if (type == "PRICE")
    {
        return object1.getPrice() < object2.getPrice();
    }
    else if (type == "RESIDUAL")
    {
        return object1.getResidual() < object2.getResidual();
    }
    else
    {
        return object1.getId() < object2.getId();
    }
}
bool compareByDishDesc(Dish object1, Dish object2, string type)
{
    if (type == "PRICE")
    {
        return object1.getPrice() > object2.getPrice();
    }
    else if (type == "RESIDUAL")
    {
        return object1.getResidual() > object2.getResidual();
    }
    else
    {
        return object1.getId() > object2.getId();
    }
}

void swapDish(Dish &a, Dish &b)
{
    Dish temp = a;
    a = b;
    b = temp;
}

void quickSortDish(vector<Dish> &list, int left, int right, bool (*compare)(Dish , Dish , string), string type)
{
    if (left < right)
    {
        srand(time(NULL));
        int pivot = left + rand() % (right - left + 1);
        int i = left - 1;
        int j = right + 1;
        while (true)
        {
            do
            {
                i++;
            } while (compare(list[i], list[pivot], type));
            do
            {
                j--;
            } while (compare(list[pivot], list[j], type));
            if (i >= j)
                break;
            swapDish(list[i], list[j]);
        }
        quickSortDish(list, left, j, compare, type);
        quickSortDish(list, j + 1, right, compare, type);
    }
}


