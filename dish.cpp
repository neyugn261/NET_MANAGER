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
        int id = numberFromEmptyId("./dish/emptyID.txt");
        if (id == -1)
        {
            id = getNumber("./dish/dishID.txt");
            id++;
            updateNumber("./dish/dishID.txt", id);
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
    while (getObjectFromFile(file, temp))
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

