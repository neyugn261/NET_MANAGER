#include "function.h"
#include "dish.h"

Dish::~Dish() {}
string Dish::getName() { return name; }
string Dish::getId() { return id; }
string Dish::getPrice() { return price; }
string Dish::getUnit() { return unit; }
string Dish::getResidual() { return residual; }
void Dish::setName(string name) { this->name = name; }
void Dish::setId(string id) { this->id = id; }
void Dish::setPrice(string price) { this->price = price; }
void Dish::setUnit(string unit) { this->unit = unit; }
void Dish::setResidual(string residual) { this->residual = residual; }
// ┌┐┬─└┘│├┤
// ┌──────────────────────────────┐
// │                              │
// ├──────────────────────────────┤
// │                              │
// └──────────────────────────────┘
/*------------------------------------Friend------------------------------------*/
bool operator>>(istream &in, Dish &dish)
{
    cout << "┌───────────────────────────────────┐" << endl
         << "│                                   │" << endl
         << "├───────────────────────────────────┤────────────────────┐" << endl
         << "│ 1.Nhập tên món ăn:                │ vd: mitom,pepsi... │" << endl
         << "│ 2.Nhập giá:                       │ vd: 10000,1200...  │" << endl
         << "│ 3.Nhập đơn vị:                    │ vd: lon,to,chai... │" << endl
         << "│ 4.Nhập số lượng:                  │ vd: 50,100...      │" << endl
         << "└───────────────────────────────────┘────────────────────┘" << endl;
    Gotoxy((35 - 14) / 2, 1);
    cout << "Thêm thực phẩm";

    Gotoxy(21, 3);
    in >> dish.name;
    if (checkDish(dish))
    {
        Gotoxy(0, 8);
        cout << "Thực phẩm đã tồn tại" << endl;
        return false;
    }
    else
    {
        int id = numberFromEmptyIdDish();
        if (id == -1)
        {
            id = getNumberOfDish();
            id++;
            updateNumberOfDish(id);
        }
        stringstream ss;
        ss << setw(3) << setfill('0') << id;
        dish.id = "D" + ss.str();

        Gotoxy(14, 4);
        in >> dish.price;
        Gotoxy(17, 5);
        in >> dish.unit;
        Gotoxy(19, 6);
        in >> dish.residual;
    }
    return true;
}
bool getDishFromFile(fstream &file, Dish &dish)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;

    stringstream ss(line);
    getline(ss, dish.id, '|');
    getline(ss, dish.name, '|');
    getline(ss, dish.price, '|');
    getline(ss, dish.unit, '|');
    getline(ss, dish.residual);
    return true;
}
bool checkDish(Dish &dish)
{
    string filename = "./dish/listDish.txt";
    fstream file(filename, ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }

    Dish temp;
    while (getDishFromFile(file, temp))
    {
        if (temp.name == dish.name)
        {
            dish = temp;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
/*------------------------------------Other------------------------------------*/
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
    while (getDishFromFile(file1, tempDish))
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
bool dataOfEmptyIdDish(fstream &file, int &count)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;
    stringstream ss(line);
    ss >> count;
    return true;
}
int numberFromEmptyIdDish()
{
    int count = -1;
    string path1 = "./dish/EmptyID.txt";
    string tempPath1 = "./dish/temp1.txt";
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
    if (dataOfEmptyIdDish(file1, count))
    {
        int ans = count;
        while (dataOfEmptyIdDish(file1, count))
        {
            temp1 << count << endl;
        }
        file1.close();
        temp1.close();
        system("del .\\dish\\EmptyID.txt");
        system("ren .\\dish\\temp1.txt emptyID.txt");
        return ans;
    }
    file1.close();
    temp1.close();
    system("del .\\dish\\temp1.txt");
    return count;
}
int getNumberOfDish()
{
    int count = -1;
    fstream file("./dish/dishID.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    else
        file >> count;
    return count;
}
void updateNumberOfDish(int count)
{
    fstream file("./dish/dishID.txt", ios::out);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    file << count;
    file.close();
}
