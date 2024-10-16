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
    while (getStaffFromFile(file, tempStaff))
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
    while (getAccountFromFile(file1, tempAccount))
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
    cout << "Danh sách nhân viên: " << endl;
    Staff staff;
    fstream file("./account/listStaff.txt", ios::in);
    while (getStaffFromFile(file, staff))
    {
        cout << staff.getId() << "|" << staff.getAname() << "|" << staff.getPass() << "|" << staff.getRole() << "|" << staff.getStatus() << "|" << staff.getName() << "|" << staff.getSdt() << endl;
    }
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
    cout << "Thêm món ăn thành công với ID là: " << dish.getId() << endl;
}

void Admin::seenDish(Dish dish)
{
    cout << "ID: " << dish.getId() << endl;
    cout << "Tên món ăn: " << dish.getName() << endl;
    cout << "Giá: " << dish.getPrice() << endl;
    cout << "Đơn vị: " << dish.getUnit() << endl;
    cout << "Tồn dư: " << dish.getResidual() << endl;
}

void Admin::changeCost(Dish dish)
{
    string price;
    cout << "Nhập giá mới: ";
    cin >> price;
    dish.setPrice(price);
    updateDishToFile(dish);
    cout << "Đổi giá thành công" << endl;
}

void Admin::addQuanlity(Dish dish)
{
    string quanlity;
    cout << "Nhập số lượng: ";
    cin >> quanlity;
    int temp = stoi(dish.getResidual()) + stoi(quanlity);
    dish.setResidual(to_string(temp));
    updateDishToFile(dish);
    cout << "Thêm số lượng thành công" << endl;
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
    while (getDishFromFile(file, tempDish))
    {
        if (tempDish.getName() != dish.getName())
        {
            temp << tempDish.getId() << "|" << tempDish.getName() << "|" << tempDish.getPrice() << "|" << tempDish.getUnit() << "|" << tempDish.getResidual() << endl;
        }
        else{
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
    cout << "Danh sách món ăn: " << endl;
    Dish dish;
    fstream file("./dish/listDish.txt", ios::in);
    while (getDishFromFile(file, dish))
    {
        cout << dish.getId() << "|" << dish.getName() << "|" << dish.getPrice() << "|" << dish.getUnit() << "|" << dish.getResidual() << endl;
    }
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
    while (getCustomerFromFile(file, tempCustomer))
    {
        if (tempCustomer.getName() != customer.getName())
        {
            temp << tempCustomer.getId() << "|" << tempCustomer.getName() << "|" << tempCustomer.getSdt() << "|" << tempCustomer.getEmail() << "|" << tempCustomer.getContribute() << endl;
        }
        else{
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

void Admin::seenListCustomer(){
    cout << "Danh sách khách hàng: " << endl;
    Customer customer;
    fstream file("./customer/listCustomer.txt", ios::in);
    while (getCustomerFromFile(file, customer))
    {
        cout << customer.getId() << "|" << customer.getName() << "|" << customer.getSdt() << "|" << customer.getEmail() << "|" << customer.getContribute() << endl;
    }
    file.close();
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
    cout << "Thêm máy thành công với ID là: " << computer.getId() << endl;
}

/*------------------------------------Other------------------------------------*/
