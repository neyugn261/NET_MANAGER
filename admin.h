#ifndef ADMIN_H
#define ADMIN_H

#include "staff.h"
#include "dish.h"
#include <iomanip>

class Admin :  public Staff{
public:
    void addStaff(Staff staff);
    void deleteStaff(Staff staff);
    void seenStaff(Staff staff);
    void changeSPassword(Staff staff);
    void seenListStaff();

    void addDish(Dish dish);
    void seenDish(Dish dish);
    void changeCost(Dish dish);
    void addQuanlity(Dish dish);
    void deleteDish(Dish dish);
    void seenListDish();
};
/*------------------------------------Other------------------------------------*/




#endif