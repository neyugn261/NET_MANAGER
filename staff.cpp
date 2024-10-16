#include "staff.h"

Staff::~Staff() {};
string Staff::getId() { return id; }
string Staff::getSdt() { return sdt; }
string Staff::getName() { return name; }
void Staff::setId(string id) { this->id = id; }
void Staff::setSdt(string sdt) { this->sdt = sdt; }
void Staff::setName(string name) { this->name = name; }

/*------------------------------------Friend------------------------------------*/
bool getStaffFromFile(fstream &file, Staff &staff)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;
    stringstream ss(line);
    getline(ss, staff.id, '|');
    getline(ss, staff.aname, '|');
    getline(ss, staff.password, '|');
    getline(ss, staff.role, '|');
    getline(ss, staff.status, '|');
    getline(ss, staff.name, '|');
    getline(ss, staff.sdt);
    return true;
}

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
    while(getStaffFromFile(file1,tempStaff)){
        if(tempStaff.getAname() == staff.getAname()){
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
    while (getAccountFromFile(file2, tempAccount))
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
/*------------------------------------Other------------------------------------*/
bool dataOfEmptyId(fstream &file, int &count)
{
    string line;
    getline(file, line);
    if (line.empty())
        return false;
    else
    {
        count = stoi(line);
        return true;
    }
}

int numberFromEmptyIdSt()
{
    int count = -1;
    string path1 = "./account/EmptyID.txt";
    string tempPath1 = "./account/temp1.txt";
    fstream file1(path1, ios::in);
    fstream temp1(tempPath1, ios::out);
    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    if (!temp1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    if (dataOfEmptyId(file1, count))
    {
        int ans = count;
        while (dataOfEmptyId(file1, count))
        {
            temp1 << count << endl;
        }
        file1.close();
        temp1.close();
        system("del .\\account\\EmptyID.txt");
        system("ren .\\account\\temp1.txt emptyID.txt");
        return ans;
    }
    file1.close();
    temp1.close();
    system("del .\\account\\temp1.txt");
    return count;
}

int getNumberOfStaff()
{
    int count = -1;
    fstream file("./account/staffID.txt", ios::in);
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

void updateNumberOfStaff(int count)
{
    fstream file("./account/staffID.txt", ios::out);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    file << count;
    file.close();
}

bool checkStaff(Staff &staff)
{
    string filename = "./account/listStaff.txt";
    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }
    Staff temp;
    while (getStaffFromFile(file, temp))
    {
        if (temp.getName() == staff.getName())
        {
            staff = temp;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
