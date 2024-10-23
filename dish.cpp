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
    ClearLine(50, 3, 20);
    Gotoxy(50, 3);    
    EnterString(dish.name, 20);
    toName(dish.name);
    if (checkNameObject(dish))
    {   
        Sleep(200);
        ShowCursor(false);
        Gotoxy(26, 8);               
        cout << "Thực phẩm đã tồn tại" << endl;
        Sleep(700);
        ClearLine(26, 8, 20);        
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

        ClearLine(40, 4, 7);
        Gotoxy(40, 4);
        EnterNumber(dish.price, 7,4);
        ClearLine(43, 5, 5);
        Gotoxy(43, 5);        
        EnterString(dish.unit, 5);
        ClearLine(45, 6, 5);
        Gotoxy(45, 6);
        EnterNumber(dish.residual, 5);
    }
    return true;
}

/*------------------------------------Other------------------------------------*/
