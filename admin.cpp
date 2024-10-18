#include "function.h"
#include "admin.h"

void Admin::addStaff(Staff staff)
{
    // thay đổi trên listStaff.txt
    fstream file("./account/listStaff.txt", ios::app);
    if (file.is_open())
    { // id|aname|pass|role|status|name|sdt
        file << staff.getId() << "|" << staff.getAname() << "|" << staff.getPass() << "|" << staff.getRole() << "|" << staff.getStatus() << "|" << staff.getName() << "|" << staff.getSdt() << endl;
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

    cout << "Thêm nhân viên thành công với ID là: " << staff.getId() << endl;
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

    cout << "Xóa nhân viên thành công" << endl;
}

void Admin::seenStaff(Staff staff)
{
    cout << "ID: " << staff.getId() << endl;
    cout << "Tên tài khoản: " << staff.getAname() << endl;
    cout << "Mật khẩu: " << staff.getPass() << endl;
    cout << "Tên: " << staff.getName() << endl;
    cout << "Số điện thoại: " << staff.getSdt() << endl;
    cout << "Trạng thái: " << staff.getStatus() << endl;
}

void Admin::changeSPassword(Staff staff)
{
    string pass;
    cout << "Nhập mật khẩu mới: ";
    cin >> pass;
    staff.setPass(pass);
    updateStaffToFile(staff);
    cout << "Đổi mật khẩu thành công" << endl;
}

void Admin::seenListStaff()
{
    Staff staff;
    fstream file("./account/listStaff.txt", ios::in);
    cout << "┌───────────────────────────────────────────────────────────────────────────────────────────────┐" << endl
         << "│                                        Danh sách nhân viên                                    │" << endl
         << "├────────┬─────────────────────┬───────────────┬────────────┬────────────────────┬──────────────┤" << endl
         << "│   ID   │     Họ và tên       │ Số điện thoại │ Trạng thái │      Tài khoản     │   Mật khẩu   │" << endl
         << "├────────┼─────────────────────┼───────────────┼────────────┼────────────────────┼──────────────┤" << endl;

    while (getObjectFromFile(file, staff))
    {
        cout << "│ " << setw(7) << left << staff.getId() << "│ ";
        cout << setw(20) << left << staff.getName() << "│ ";
        cout << setw(14) << left << staff.getSdt() << "│ ";
        cout << setw(11) << left << staff.getStatus() << "│ ";
        cout << setw(19) << left << staff.getAname() << "│ ";
        cout << setw(13) << left << staff.getPass() << "│" << endl;
    }
    cout << "└────────┴─────────────────────┴───────────────┴────────────┴────────────────────┴──────────────┘" << endl;
    file.close();
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

void Admin::seenDish(Dish dish)
{
    cout << "ID: " << dish.getId() << endl;
    cout << "Tên món ăn: " << dish.getName() << endl;
    cout << "Giá: " << dish.getPrice() << endl;
    cout << "Đơn vị: " << dish.getUnit() << endl;
    cout << "Tồn dư: " << dish.getResidual() << endl;
}

void Admin::changeCost(Dish &dish)
{
    string price;
    ClearLine(47, 4, dish.getPrice().length());

    Gotoxy(47, 4);
    ShowCursor(true);
    cin >> price;
    ShowCursor(false);
    dish.setPrice(price);
    Sleep(200);
    Gotoxy(42, 7);
    cout << "Đổi giá thành công";
    Sleep(700);
    ClearLine(42, 7, 23);
    updateDishToFile(dish);
    checkObject(dish);
}

void Admin::addQuanlity(Dish &dish)
{
    string quanlity;
    ClearLine(52,5,dish.getResidual().length());
    
    Gotoxy(52, 5);
    ShowCursor(true);
    cin >> quanlity;
    ShowCursor(false);    
    dish.setResidual(quanlity);
    Sleep(200);
    Gotoxy(42, 7);
    cout << "Đổi số lượng thành công";
    Sleep(700);
    ClearLine(42, 7, 23);
    updateDishToFile(dish);
    checkObject(dish);
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

    cout << "Xóa món ăn thành công" << endl;
}

void Admin::seenListDish()
{
    Dish dish;
    fstream file("./dish/listDish.txt", ios::in);
    cout << "┌──────────────────────────────────────────────────┐" << endl
         << "│                 Danh sách món ăn                 │" << endl
         << "├──────┬─────────────┬────────┬──────────┬─────────┤" << endl
         << "│  ID  │ Tên món ăn  │  Giá   │  Đơn vị  │Số lượng │" << endl
         << "├──────┼─────────────┼────────┼──────────┼─────────┤" << endl;

    while (getObjectFromFile(file, dish))
    {
        // tôi muốn canh lề trái
        cout << "│ " << setw(5) << left << dish.getId() << "│ ";
        cout << setw(12) << left << dish.getName() << "│ ";
        cout << setw(7) << left << dish.getPrice() << "│ ";
        cout << setw(9) << left << dish.getUnit() << "│ ";
        cout << setw(8) << left << dish.getResidual() << "│" << endl;
    }
    cout << "└──────┴─────────────┴────────┴──────────┴─────────┘" << endl;
    file.close();
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
    cout << "Thêm khách hàng thành công với ID là: " << customer.getId() << endl;
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

    cout << "Xóa khách hàng thành công" << endl;
}

void Admin::seenListCustomer()
{

    Customer customer;
    fstream file("./customer/listCustomer.txt", ios::in);
    cout << "┌────────────────────────────────────────────────────────────────────────────┐" << endl
         << "│                           Danh sách khách hàng                             │" << endl
         << "├────────┬──────────────────┬─────────────────┬───────────────────┬──────────┤" << endl
         << "│   ID   │  Tên khách hàng  │  Số điện thoại  │       Email       │ Đóng góp │" << endl
         << "├────────┼──────────────────┼─────────────────┼───────────────────┼──────────┤" << endl;

    while (getObjectFromFile(file, customer))
    {
        cout << "│ " << setw(7) << left << customer.getId() << "│ ";
        cout << setw(17) << left << customer.getName() << "│ ";
        cout << setw(16) << left << customer.getSdt() << "│ ";
        cout << setw(18) << left << customer.getEmail() << "│ ";
        cout << setw(9) << left << customer.getContribute() << "│" << endl;
    }
    cout << "└────────┴──────────────────┴─────────────────┴───────────────────┴──────────┘" << endl;
    file.close();
}

void Admin::addComputer(Computer computer)
{
    fstream file("./computer/listComputer.txt", ios::app);
    if (file.is_open())
    { // id|name|cost|status|type|totaltime
        file << computer.getName() << "|" << computer.getCost() << "|" << computer.getStatus() << "|" << computer.getType() << "|" << computer.getTotaltime() << endl;
        file.close();
    }
    else
    {
        cout << "Không thể mở file" << endl;
    }
    cout << "Thêm máy thành công với ID là: " << computer.getName() << endl;
}

void Admin::seenComputer(Computer computer)
{
    cout << "ID: " << computer.getName() << endl;
    cout << "Giá: " << computer.getCost() << endl;
    cout << "Trạng thái: " << computer.getStatus() << endl;
    cout << "Loại: " << computer.getType() << endl;
    cout << "Thời gian sử dụng: " << computer.getTotaltime() << endl;
}

void Admin::changeCost(Computer computer)
{
    string cost;
    cout << "Nhập giá mới: ";
    cin >> cost;
    computer.setCost(cost);
    updateComputerToFile(computer);
    cout << "Đổi giá thành công" << endl;
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
        if (tempComputer.getName() != computer.getName())
        {
            temp << tempComputer.getName() << "|" << tempComputer.getCost() << "|" << tempComputer.getStatus() << "|" << tempComputer.getType() << "|" << tempComputer.getTotaltime() << endl;
        }
        else
        {
            string temp = tempComputer.getName();
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

    cout << "Xóa máy thành công" << endl;
}

void Admin::seenListComputer()
{
    cout << "┌─────────────────────────────────────────────────────────────────┐" << endl
         << "│                      Danh sách máy tính                         │" << endl
         << "├────────┬──────────┬────────────┬────────────┬───────────────────┤" << endl
         << "│   ID   |   Giá    | Trạng thái |    Loại    | Thời gian sử dụng |" << endl
         << "├────────┼──────────┼────────────┼────────────┼───────────────────┤" << endl;
    Computer computer;
    fstream file("./computer/listComputer.txt", ios::in);
    while (getObjectFromFile(file, computer))
    {
        cout << "│ " << setw(7) << left << computer.getName() << "| ";
        cout << setw(9) << left << computer.getCost() << "| ";
        cout << setw(11) << left << computer.getStatus() << "| ";
        cout << setw(11) << left << computer.getType() << "| ";
        cout << setw(18) << left << computer.getTotaltime() << "|" << endl;
    }
    cout << "└────────┴──────────┴────────────┴────────────┴───────────────────┘" << endl;
    file.close();
}

/*------------------------------------Other------------------------------------*/
