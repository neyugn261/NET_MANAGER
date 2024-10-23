#ifndef ADMIN_H
#define ADMIN_H

#include "staff.h"
#include "dish.h"
#include "customer.h"
#include "computer.h"

class Admin : public Staff
{
public:
    void addStaff(Staff staff);
    void deleteStaff(Staff staff);    
    void changeSPassword(Staff &staff);
    void seenListStaff();

    void addDish(Dish dish);   
    void changeCost(Dish &dish);
    void addQuanlity(Dish &dish);
    void deleteDish(Dish dish);
    void seenListDish();

    void addCustomer(Customer customer);
    void deleteCustomer(Customer customer);
    void seenListCustomer();

    void addComputer(Computer computer);    
    void changeCost(Computer &computer);
    void deleteComputer(Computer computer);
    void seenListComputer();
};
/*------------------------------------Other------------------------------------*/
void writeListDish(vector<Dish>& listDish, int maxLengthName, int maxLengthPrice, int maxLengthUnit, int maxLengthResidual);
void sortDishId(vector<Dish>& listDish, int x);
#endif