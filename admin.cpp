#include "function.h"
#include "admin.h"

void Admin::addStaff(Staff staff)
{
    // thay đổi trên listStaff.txt
    fstream file("./account/listStaff.txt", ios::app);
    if (file.is_open())
    { // id|aname|pass|role|status|name|sdt|revenue
        file << staff.getId() << "|" << staff.getAname() << "|" << staff.getPass() << "|" << staff.getRole() << "|" << staff.getStatus() << "|" << staff.getName() << "|" << staff.getSdt() << "|" << staff.getRevenue() << endl;
        file.close();
    }
    else
    {
        cout << "Không thể mở file" << endl;
    }

    // thay đổi trên listAccount.txt
    fstream file1("./account/listAccount.txt", ios::app);
    if (file1.is_open())
    { // aname|pass|role|status
        file1 << staff.getAname() << "|" << staff.getPass() << "|" << staff.getRole() << "|" << staff.getStatus() << endl;
        file1.close();
    }
    else
    {
        cout << "Không thể mở file" << endl;
    }
}

void Admin::deleteStaff(Staff staff)
{
    fstream file("./account/listStaff.txt", ios::in);
    fstream temp("./account/temp.txt", ios::out);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }

    Staff tempStaff;
    while (getObjectFromFile(file, tempStaff))
    {
        if (tempStaff.getStatus() == "ONLINE")
        {
            cout << "Nhân viên đang online không thể xóa!" << endl;
            file.close();
            temp.close();
            system("del .\\account\\temp.txt");
            return;
        }
        else
        {
            if (tempStaff.getId() != staff.getId())
            {
                temp << tempStaff.getId() << "|" << tempStaff.getAname() << "|" << tempStaff.getPass() << "|" << tempStaff.getRole() << "|" << tempStaff.getStatus() << "|" << tempStaff.getName() << "|" << tempStaff.getSdt() << endl;
            }
            else
            {
                string temp = tempStaff.getId();
                string numberPart = temp.substr(2);
                size_t pos = numberPart.find_first_not_of('0');
                temp = (pos != string::npos) ? numberPart.substr(pos) : "0";
                fstream file2("./account/EmptyID.txt", ios::app);
                if (!file2.is_open())
                {
                    cout << "Không thể mở file" << endl;
                    return;
                }
                file2 << temp << endl;
                file2.close();
            }
        }
    }

    file.close();
    temp.close();
    system("del .\\account\\listStaff.txt");
    system("ren .\\account\\temp.txt listStaff.txt");

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
        if (tempAccount.getAname() != staff.getAname())
        {
            temp1 << tempAccount.getAname() << "|" << tempAccount.getPass() << "|" << tempAccount.getRole() << "|" << tempAccount.getStatus() << endl;
        }
    }

    file1.close();
    temp1.close();
    system("del .\\account\\listAccount.txt");
    system("ren .\\account\\temp1.txt listAccount.txt");
}

void Admin::changeSPassword(Staff &staff)
{
    string pass;
    ClearLine(54, 6, staff.getPass().length());

    Gotoxy(54, 6);
    ShowCursor(true);

    EnterString(pass, 20);

    ShowCursor(false);
    staff.setPass(pass);
    Sleep(200);
    Gotoxy(40, 10); //
    cout << "Đổi mật khẩu thành công";
    Sleep(700);
    ClearLine(40, 10, 23);
    updateStaffToFile(staff);
    checkIdObject(staff);
}

void Admin::seenListStaff()
{
    system("cls");
    Staff staff;
    fstream file("./account/listStaff.txt", ios::in);

    int maxLengthName = 0;
    int maxLengthSdt = 0;
    int maxLengthStatus = 0;
    int maxLengthRevenue = 0;
    int maxLengthAname = 0;
    int maxLengthPass = 0;
    int count = 0;

    while (getObjectFromFile(file, staff))
    {
        if (staff.getName().length() > maxLengthName)
        {
            maxLengthName = staff.getName().length();
        }
        if (staff.getSdt().length() > maxLengthSdt)
        {
            maxLengthSdt = staff.getSdt().length();
        }
        if (staff.getStatus().length() > maxLengthStatus)
        {
            maxLengthStatus = staff.getStatus().length();
        }
        if (staff.getRevenue().length() > maxLengthRevenue)
        {
            maxLengthRevenue = staff.getRevenue().length();
        }
        if (staff.getAname().length() > maxLengthAname)
        {
            maxLengthAname = staff.getAname().length();
        }
        if (staff.getPass().length() > maxLengthPass)
        {
            maxLengthPass = staff.getPass().length();
        }
        count++;
    }

    file.close();

    if (maxLengthName < 6)
    {
        maxLengthName = 6;
    }
    if (maxLengthSdt < 3)
    {
        maxLengthSdt = 3;
    }
    if (maxLengthStatus < 10)
    {
        maxLengthStatus = 10;
    }
    if (maxLengthRevenue < 9)
    {
        maxLengthRevenue = 9;
    }
    if (maxLengthAname < 9)
    {
        maxLengthAname = 9;
    }
    if (maxLengthPass < 8)
    {
        maxLengthPass = 8;
    }

    int max = maxLengthName + maxLengthSdt + maxLengthStatus + maxLengthRevenue + maxLengthAname + maxLengthPass + 26;

    Gotoxy(0, 0);
    cout << "╔";
    for (int i = 0; i < max - 2; i++)
        cout << "═";
    cout << "╗" << endl;
    cout << "║";
    for (int i = 0; i < max - 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╦";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthRevenue + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthAname + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthPass + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    cout << "║  STT ║";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthRevenue + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthAname + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthPass + 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╬";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthRevenue + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthAname + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthPass + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "║      ║";
        for (int i = 0; i < maxLengthName + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthSdt + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthStatus + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthRevenue + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthAname + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthPass + 2; i++)
            cout << " ";
        cout << "║" << endl;
    }
    cout << "╚══════╩";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthRevenue + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthAname + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthPass + 2; i++)
        cout << "═";
    cout << "╝" << endl;
    Gotoxy((max - 19 + 1) / 2, 1);
    cout << "Danh sách nhân viên";
    Gotoxy((7 * 2 + maxLengthName + 3 - 6 + 1) / 2, 3);
    cout << "Họ tên";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt + 3 * 3 - 3 + 1) / 2, 3);
    cout << "Sđt";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt * 2 + maxLengthStatus + 3 * 5 - 10 + 1) / 2, 3);
    cout << "Trạng thái";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt * 2 + maxLengthStatus * 2 + maxLengthRevenue + 3 * 7 - 10 + 1) / 2, 3);
    cout << "Doanh thu";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt * 2 + maxLengthStatus * 2 + maxLengthRevenue * 2 + maxLengthAname + 3 * 9 - 9 + 1) / 2, 3);
    cout << "Tài khoản";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt * 2 + maxLengthStatus * 2 + maxLengthRevenue * 2 + maxLengthAname * 2 + maxLengthPass + 3 * 11 - 8 + 1) / 2, 3);
    cout << "Mật khẩu";

    fstream file1("./account/listStaff.txt", ios::in);

    int y = 5;
    while (getObjectFromFile(file1, staff))
    {
        Gotoxy(2, y);
        cout << staff.getId();
        Gotoxy(7 + 2, y);
        cout << staff.getName();
        Gotoxy(7 + 3 + maxLengthName + 2, y);
        cout << staff.getSdt();
        Gotoxy(7 + 3 * 2 + maxLengthName + maxLengthSdt + 2, y);
        cout << staff.getStatus();
        Gotoxy(7 + 3 * 3 + maxLengthName + maxLengthSdt + maxLengthStatus + 2, y);
        cout << staff.getRevenue();
        Gotoxy(7 + 3 * 4 + maxLengthName + maxLengthSdt + maxLengthStatus + maxLengthRevenue + 2, y);
        cout << staff.getAname();
        Gotoxy(7 + 3 * 5 + maxLengthName + maxLengthSdt + maxLengthStatus + maxLengthRevenue + maxLengthAname + 2, y);
        cout << staff.getPass();
        y++;
    }

    file1.close();
    Gotoxy(0, y + 1);
    pressEnter();
}

void Admin::addDish(Dish dish)
{
    fstream file("./dish/listDish.txt", ios::app);
    if (file.is_open())
    { // id|name|price|unit|residual
        file << dish.getId() << "|" << dish.getName() << "|" << dish.getPrice() << "|" << dish.getUnit() << "|" << dish.getResidual() << endl;
        file.close();
    }
    else
    {
        cout << "Không thể mở file" << endl;
    }
}

void Admin::changeCost(Dish &dish)
{
    string price;
    ClearLine(47, 4, dish.getPrice().length());

    Gotoxy(47, 4);
    ShowCursor(true);

    EnterNumber(price, 7, 4);

    ShowCursor(false);
    dish.setPrice(price);
    Sleep(200);
    Gotoxy(40, 7);
    cout << "Đổi giá thành công";
    Sleep(700);
    ClearLine(40, 7, 23);
    updateDishToFile(dish);
    checkIdObject(dish);
}

void Admin::addQuanlity(Dish &dish)
{
    string quanlity;
    ClearLine(52, 5, dish.getResidual().length());

    Gotoxy(52, 5);
    ShowCursor(true);

    EnterNumber(quanlity, 5);

    ShowCursor(false);
    dish.setResidual(quanlity);
    Sleep(200);
    Gotoxy(40, 7);
    cout << "Đổi số lượng thành công";
    Sleep(700);
    ClearLine(40, 7, 23);
    updateDishToFile(dish);
    checkIdObject(dish);
}

void Admin::deleteDish(Dish dish)
{
    fstream file("./dish/listDish.txt", ios::in);
    fstream temp("./dish/temp.txt", ios::out);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }

    Dish tempDish;
    while (getObjectFromFile(file, tempDish))
    {
        if (tempDish.getName() != dish.getName())
        {
            temp << tempDish.getId() << "|" << tempDish.getName() << "|" << tempDish.getPrice() << "|" << tempDish.getUnit() << "|" << tempDish.getResidual() << endl;
        }
        else
        {
            string temp = tempDish.getId();
            string numberPart = temp.substr(1);
            size_t pos = numberPart.find_first_not_of('0');
            temp = (pos != string::npos) ? numberPart.substr(pos) : "0";
            fstream file2("./dish/emptyID.txt", ios::app);
            if (!file2.is_open())
            {
                cout << "Không thể mở file" << endl;
                return;
            }
            file2 << temp << endl;
            file2.close();
        }
    }

    file.close();
    temp.close();
    system("del .\\dish\\listDish.txt");
    system("ren .\\dish\\temp.txt listDish.txt");
}

void Admin::seenListDish()
{
    system("cls");
    Dish dish;
    fstream file("./dish/listDish.txt", ios::in);

    int maxLengthName = 0;
    int maxLengthPrice = 0;
    int maxLengthUnit = 0;
    int maxLengthResidual = 0;
    int count = 0;

    while (getObjectFromFile(file, dish))
    {
        if (dish.getName().length() > maxLengthName)
        {
            maxLengthName = dish.getName().length();
        }
        if (dish.getPrice().length() > maxLengthPrice)
        {
            maxLengthPrice = dish.getPrice().length();
        }
        if (dish.getUnit().length() > maxLengthUnit)
        {
            maxLengthUnit = dish.getUnit().length();
        }
        if (dish.getResidual().length() > maxLengthResidual)
        {
            maxLengthResidual = dish.getResidual().length();
        }
        count++;
    }

    file.close();

    if (maxLengthName < 12)
    {
        maxLengthName = 12;
    }
    if (maxLengthPrice < 3)
    {
        maxLengthPrice = 3;
    }
    if (maxLengthUnit < 6)
    {
        maxLengthUnit = 6;
    }
    if (maxLengthResidual < 8)
    {
        maxLengthResidual = 8;
    }

    int max = maxLengthName + maxLengthPrice + maxLengthUnit + maxLengthResidual + 20;

   
    Gotoxy(0, 0);
    cout << "╔";
    for (int i = 0; i < max - 2; i++)
        cout << "═";
    cout << "╗" << endl;
    cout << "║";
    for (int i = 0; i < max - 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╦";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthPrice + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthUnit + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthResidual + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    cout << "║  STT ║";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthPrice + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthUnit + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthResidual + 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╬";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthPrice + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthUnit + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthResidual + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "║      ║";
        for (int i = 0; i < maxLengthName + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthPrice + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthUnit + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthResidual + 2; i++)
            cout << " ";
        cout << "║" << endl;
    }
    cout << "╚══════╩";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthPrice + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthUnit + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthResidual + 2; i++)
        cout << "═";
    cout << "╝" << endl;
    Gotoxy((max - 19 + 1) / 2, 1);
    cout << "Danh sách thực phẩm";
    Gotoxy((7 * 2 + maxLengthName + 3 - 13 + 1) / 2, 3);
    cout << "Tên thực phẩm";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthPrice + 3 * 3 - 3 + 1) / 2, 3);
    cout << "Giá";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthPrice * 2 + maxLengthUnit + 3 * 5 - 6 + 1) / 2, 3);
    cout << "Đơn vị";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthPrice * 2 + maxLengthUnit * 2 + maxLengthResidual + 3 * 7 - 8 + 1) / 2, 3);
    cout << "Số lượng";

    file.close();

    fstream file1("./dish/listDish.txt", ios::in);

    vector<Dish> listDish;
    while (getObjectFromFile(file1, dish))
    {
        listDish.push_back(dish);
    }
    file1.close();

    writeListDish(listDish, maxLengthName, maxLengthPrice, maxLengthUnit, maxLengthResidual);

    int selectOption = 1;
    while (true)
    {
        menuMain(getMenuOptionCount("SORTDISH"), max + 3, 0);
        showMenu("SORTDISH", selectOption, max + 4, 3);
        Gotoxy((2 * max + 34 - 17 + 1) / 2, 1);
        cout << "Sắp xếp thực phẩm";
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? getMenuOptionCount("SORTDISH") : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == getMenuOptionCount("SORTDISH")) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                sortDishId(listDish, max + 36);
                break;
            case 2:
               // sortDishCost(listDish);
                break;
            case 3:
               // sortDishQuanlity(listDish);
                break;
            case 4:
                return;
            }
        }
        writeListDish(listDish, maxLengthName, maxLengthPrice, maxLengthUnit, maxLengthResidual);
    }

    
}

void sortDishId(vector<Dish> &listDish, int x)
{
    menuSelectTypeSort(x, 2);
    int selectOption = 1;
    while (true)
    {
        showMenu("TYPESORT", selectOption, x + 4, 3);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? getMenuOptionCount("TYPESORT") : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == getMenuOptionCount("TYPESORT")) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                quickSortDish(listDish, 0, listDish.size() - 1, compareByDishAsc, "ID");
                ClearLine(x, 2, 16);
                ClearLine(x, 3, 16);
                ClearLine(x, 4, 16);
                ClearLine(x, 5, 16);
                return;
            case 2:
                quickSortDish(listDish, 0, listDish.size() - 1, compareByDishDesc, "ID");
                ClearLine(x, 2, 16);
                ClearLine(x, 3, 16);
                ClearLine(x, 4, 16);
                ClearLine(x, 5, 16);                
                return;            
            }
        }
    }
}

void writeListDish(vector<Dish> &listDish, int maxLengthName, int maxLengthPrice, int maxLengthUnit, int maxLengthResidual)
{
    int y = 5;
    for (auto &dish : listDish)
    {   
        ClearLine(2, y, 4);
        Gotoxy(2, y);
        cout << dish.getId();
        ClearLine(7 + 2, y, maxLengthName);
        Gotoxy(7 + 2, y);
        cout << dish.getName();
        ClearLine(7 + 3 + maxLengthName + 2, y, maxLengthPrice);
        Gotoxy(7 + 3 + maxLengthName + 2, y);
        cout << dish.getPrice();
        ClearLine(7 + 3 * 2 + maxLengthName + maxLengthPrice + 2, y, maxLengthUnit);
        Gotoxy(7 + 3 * 2 + maxLengthName + maxLengthPrice + 2, y);
        cout << dish.getUnit();
        ClearLine(7 + 3 * 3 + maxLengthName + maxLengthPrice + maxLengthUnit + 2, y, maxLengthResidual);
        Gotoxy(7 + 3 * 3 + maxLengthName + maxLengthPrice + maxLengthUnit + 2, y);
        cout << dish.getResidual();
        y++;
    }
}

void Admin::addCustomer(Customer customer)
{
    fstream file("./customer/listCustomer.txt", ios::app);
    if (file.is_open())
    { // id|name|sdt|email|contribute
        file << customer.getId() << "|" << customer.getName() << "|" << customer.getSdt() << "|" << customer.getEmail() << "|" << customer.getContribute() << endl;
        file.close();
    }
    else
    {
        cout << "Không thể mở file" << endl;
    }
}

void Admin::deleteCustomer(Customer customer)
{
    fstream file("./customer/listCustomer.txt", ios::in);
    fstream temp("./customer/temp.txt", ios::out);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    if (!temp.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }

    Customer tempCustomer;
    while (getObjectFromFile(file, tempCustomer))
    {
        if (tempCustomer.getName() != customer.getName())
        {
            temp << tempCustomer.getId() << "|" << tempCustomer.getName() << "|" << tempCustomer.getSdt() << "|" << tempCustomer.getEmail() << "|" << tempCustomer.getContribute() << endl;
        }
        else
        {
            string temp = tempCustomer.getId();
            string numberPart = temp.substr(1);
            size_t pos = numberPart.find_first_not_of('0');
            temp = (pos != string::npos) ? numberPart.substr(pos) : "0";
            fstream file2("./customer/emptyID.txt", ios::app);
            if (!file2.is_open())
            {
                cout << "Không thể mở file" << endl;
                return;
            }
            file2 << temp << endl;
            file2.close();
        }
    }

    file.close();
    temp.close();
    system("del .\\customer\\listCustomer.txt");
    system("ren .\\customer\\temp.txt listCustomer.txt");
}

void Admin::seenListCustomer()
{
    system("cls");
    Customer customer;
    fstream file("./customer/listCustomer.txt", ios::in);

    int maxLengthName = 0;
    int maxLengthSdt = 0;
    int maxLengthEmail = 0;
    int maxLengthContribute = 0;
    int count = 0;

    while (getObjectFromFile(file, customer))
    {
        if (customer.getName().length() > maxLengthName)
        {
            maxLengthName = customer.getName().length();
        }
        if (customer.getSdt().length() > maxLengthSdt)
        {
            maxLengthSdt = customer.getSdt().length();
        }
        if (customer.getEmail().length() > maxLengthEmail)
        {
            maxLengthEmail = customer.getEmail().length();
        }
        if (customer.getContribute().length() > maxLengthContribute)
        {
            maxLengthContribute = customer.getContribute().length();
        }
        count++;
    }

    file.close();

    if (maxLengthName < 6)
    {
        maxLengthName = 6;
    }
    if (maxLengthSdt < 3)
    {
        maxLengthSdt = 3;
    }
    if (maxLengthEmail < 5)
    {
        maxLengthEmail = 5;
    }
    if (maxLengthContribute < 8)
    {
        maxLengthContribute = 8;
    }

    int max = maxLengthName + maxLengthSdt + maxLengthEmail + maxLengthContribute + 20;

    Gotoxy(0, 0);
    cout << "╔";
    for (int i = 0; i < max - 2; i++)
        cout << "═";
    cout << "╗" << endl;
    cout << "║";
    for (int i = 0; i < max - 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╦";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthEmail + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthContribute + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    cout << "║  STT ║";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthEmail + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthContribute + 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╬";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthEmail + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthContribute + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "║      ║";
        for (int i = 0; i < maxLengthName + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthSdt + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthEmail + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthContribute + 2; i++)
            cout << " ";
        cout << "║" << endl;
    }
    cout << "╚══════╩";
    for (int i = 0; i < maxLengthName + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthSdt + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthEmail + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthContribute + 2; i++)
        cout << "═";
    cout << "╝" << endl;
    Gotoxy((max - 20 + 1) / 2, 1);
    cout << "Danh sách khách hàng";
    Gotoxy((7 * 2 + maxLengthName + 3 - 6 + 1) / 2, 3);
    cout << "Họ tên";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt + 3 * 3 - 3 + 1) / 2, 3);
    cout << "Sđt";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt * 2 + maxLengthEmail + 3 * 5 - 5 + 1) / 2, 3);
    cout << "Email";
    Gotoxy((7 * 2 + maxLengthName * 2 + maxLengthSdt * 2 + maxLengthEmail * 2 + maxLengthContribute + 3 * 7 - 8 + 1) / 2, 3);
    cout << "Đóng góp";

    fstream file1("./customer/listCustomer.txt", ios::in);

    int y = 5;
    while (getObjectFromFile(file1, customer))
    {
        Gotoxy(2, y);
        cout << customer.getId();
        Gotoxy(7 + 2, y);
        cout << customer.getName();
        Gotoxy(7 + 3 + maxLengthName + 2, y);
        cout << customer.getSdt();
        Gotoxy(7 + 3 * 2 + maxLengthName + maxLengthSdt + 2, y);
        cout << customer.getEmail();
        Gotoxy(7 + 3 * 3 + maxLengthName + maxLengthSdt + maxLengthEmail + 2, y);
        cout << customer.getContribute();
        y++;
    }

    file1.close();
    Gotoxy(0, y + 1);
    pressEnter();
}

void Admin::addComputer(Computer computer)
{
    fstream file("./computer/listComputer.txt", ios::app);
    if (file.is_open())
    { // id|name|cost|status|type|totaltime
        file << computer.getId() << "|" << computer.getCost() << "|" << computer.getStatus() << "|" << computer.getType() << "|" << computer.getTotaltime() << endl;
        file.close();
    }
    else
    {
        cout << "Không thể mở file" << endl;
    }
}

void Admin::changeCost(Computer &computer)
{
    string cost;
    ClearLine(54, 3, computer.getCost().length());

    Gotoxy(54, 3);
    ShowCursor(true);

    EnterNumber(cost, 6, 4);

    ShowCursor(false);
    computer.setCost(cost);
    Sleep(200);
    Gotoxy(40, 8);
    cout << "Đổi giá thành công";
    Sleep(700);
    ClearLine(40, 8, 18);
    updateComputerToFile(computer);
    checkIdObject(computer);
}

void Admin::deleteComputer(Computer computer)
{
    fstream file("./computer/listComputer.txt", ios::in);
    fstream temp("./computer/temp.txt", ios::out);
    if (!file.is_open())
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
    while (getObjectFromFile(file, tempComputer))
    {
        if (tempComputer.getId() != computer.getId())
        {
            temp << tempComputer.getId() << "|" << tempComputer.getCost() << "|" << tempComputer.getStatus() << "|" << tempComputer.getType() << "|" << tempComputer.getTotaltime() << endl;
        }
        else
        {
            string temp = tempComputer.getId();
            string numberPart = temp.substr(2);
            size_t pos = numberPart.find_first_not_of('0');
            temp = (pos != string::npos) ? numberPart.substr(pos) : "0";
            fstream file2("./computer/emptyID.txt", ios::app);
            if (!file2.is_open())
            {
                cout << "Không thể mở file" << endl;
                return;
            }
            file2 << temp << endl;
            file2.close();
        }
    }

    file.close();
    temp.close();
    system("del .\\computer\\listComputer.txt");
    system("ren .\\computer\\temp.txt listComputer.txt");
}

void Admin::seenListComputer()
{
    system("cls");
    Computer computer;
    fstream file("./computer/listComputer.txt", ios::in);

    int maxLengthCost = 0;
    int maxLengthStatus = 0;
    int maxLengthType = 0;
    int maxLengthTotaltime = 0;
    int count = 0;

    while (getObjectFromFile(file, computer))
    {
        if (computer.getCost().length() > maxLengthCost)
        {
            maxLengthCost = computer.getCost().length();
        }
        if (computer.getStatus().length() > maxLengthStatus)
        {
            maxLengthStatus = computer.getStatus().length();
        }
        if (computer.getType().length() > maxLengthType)
        {
            maxLengthType = computer.getType().length();
        }
        if (computer.getTotaltime().length() > maxLengthTotaltime)
        {
            maxLengthTotaltime = computer.getTotaltime().length();
        }
        count++;
    }

    file.close();

    if (maxLengthCost < 3)
    {
        maxLengthCost = 3;
    }
    if (maxLengthStatus < 10)
    {
        maxLengthStatus = 10;
    }
    if (maxLengthType < 4)
    {
        maxLengthType = 4;
    }
    if (maxLengthTotaltime < 17)
    {
        maxLengthTotaltime = 17;
    }

    int max = maxLengthCost + maxLengthStatus + maxLengthType + maxLengthTotaltime + 20;

    Gotoxy(0, 0);
    cout << "╔";
    for (int i = 0; i < max - 2; i++)
        cout << "═";
    cout << "╗" << endl;
    cout << "║";
    for (int i = 0; i < max - 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╦";
    for (int i = 0; i < maxLengthCost + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthType + 2; i++)
        cout << "═";
    cout << "╦";
    for (int i = 0; i < maxLengthTotaltime + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    cout << "║  STT ║";
    for (int i = 0; i < maxLengthCost + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthType + 2; i++)
        cout << " ";
    cout << "║";
    for (int i = 0; i < maxLengthTotaltime + 2; i++)
        cout << " ";
    cout << "║" << endl;
    cout << "╠══════╬";
    for (int i = 0; i < maxLengthCost + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthType + 2; i++)
        cout << "═";
    cout << "╬";
    for (int i = 0; i < maxLengthTotaltime + 2; i++)
        cout << "═";
    cout << "╣" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "║      ║";
        for (int i = 0; i < maxLengthCost + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthStatus + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthType + 2; i++)
            cout << " ";
        cout << "║";
        for (int i = 0; i < maxLengthTotaltime + 2; i++)
            cout << " ";
        cout << "║" << endl;
    }
    cout << "╚══════╩";
    for (int i = 0; i < maxLengthCost + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthStatus + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthType + 2; i++)
        cout << "═";
    cout << "╩";
    for (int i = 0; i < maxLengthTotaltime + 2; i++)
        cout << "═";
    cout << "╝" << endl;

    Gotoxy((max - 18 + 1) / 2, 1);
    cout << "Danh sách máy tính";
    Gotoxy((7 * 2 + maxLengthCost + 3 - 3 + 1) / 2, 3);
    cout << "Giá";
    Gotoxy((7 * 2 + maxLengthCost * 2 + maxLengthStatus + 3 * 3 - 10 + 1) / 2, 3);
    cout << "Trạng thái";
    Gotoxy((7 * 2 + maxLengthCost * 2 + maxLengthStatus * 2 + maxLengthType + 3 * 5 - 4 + 1) / 2, 3);
    cout << "Loại";
    Gotoxy((7 * 2 + maxLengthCost * 2 + maxLengthStatus * 2 + maxLengthType * 2 + maxLengthTotaltime + 3 * 7 - 17 + 1) / 2, 3);
    cout << "Thời gian sử dụng";

    fstream file1("./computer/listComputer.txt", ios::in);

    int y = 5;
    while (getObjectFromFile(file1, computer))
    {
        Gotoxy(2, y);
        cout << computer.getId();
        Gotoxy(7 + 2, y);
        cout << computer.getCost();
        Gotoxy(7 + 3 + maxLengthCost + 2, y);
        cout << computer.getStatus();
        Gotoxy(7 + 3 * 2 + maxLengthCost + maxLengthStatus + 2, y);
        cout << computer.getType();
        Gotoxy(7 + 3 * 3 + maxLengthCost + maxLengthStatus + maxLengthType + 2, y);
        cout << computer.getTotaltime();
        y++;
    }

    file1.close();
    Gotoxy(0, y + 1);
    pressEnter();
}

/*------------------------------------Other------------------------------------*/
