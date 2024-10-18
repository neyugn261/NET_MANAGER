#ifndef DISH_H
#define DISH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <iomanip>


using namespace std;

class Dish
{
private:
    string name;
    string id;
    string price;
    string unit;     // đơn vị
    string residual; // tồn dư
public:
    ~Dish();
    string getName();
    string getId();
    string getPrice();
    string getUnit();
    string getResidual();

    void setName(string);
    void setId(string);
    void setPrice(string);
    void setUnit(string);
    void setResidual(string);

    friend bool operator>>(istream &in, Dish &dish);
  
    friend bool checkDish(Dish &dish);
};
/*------------------------------------Friend------------------------------------*/
bool operator>>(istream &in, Dish &dish);
bool checkDish(Dish &dish);
/*------------------------------------Other------------------------------------*/




#endif