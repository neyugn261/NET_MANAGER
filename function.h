#ifndef FUNCTION_H
#define FUNCTION_H 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include "admin.h"
#include "dish.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define KEY_BACKSPACE 8

class Dish;
class Computer;

/*------------------------------------CONSOLE------------------------------------*/
void ShowCursor(bool CursorVisibility);
void Gotoxy(SHORT posX, SHORT posY);
void pressEnter();
/*------------------------------------MENU------------------------------------*/
void optionMenu(string typeMenu, int option);
void printMenuOption(string typeMenu, int option, bool isSelected);
int getMenuOptionCount(const string &typeMenu);
void showMenu(string typeMenu, int selectOption);

/*------------------------------------MenusAdmin------------------------------------*/
void menuAdmin(Admin admin);

void manageComputer(Admin admin);
/**/ void addComputer(Admin admin);      // cl
/**/ void deleteComputer(Admin admin);   // cl
/**/ void changeCost(Admin admin);       // cl
/**/ void seenListComputer(Admin admin); // cl

void manageCustomer(Admin admin);
/**/ void addCustomer(Admin admin);      // cl
/**/ void deleteCustomer(Admin admin);   // cl
/**/ void seenListCustomer(Admin admin); // cl

void manageStaff(Admin admin);
/**/ void addStaff(Admin admin);
/**/ void seenstaff(Admin admin);
/**/ /**/ void in4Staff(Admin admin, Staff staff); // còn xấu
/**/ /**/ void deleteStaff(Admin admin, Staff staff);
/**/ /**/ void changeSPassword(Admin admin, Staff staff);
/**/ void seenListStaff(Admin admin); // còn xấu

void manageDish(Admin admin);
/**/ void addDish(Admin admin); 
/**/ void changeDish(Admin admin);
/**/ /**/ void in4Dish(Admin admin, Dish dish); // còn xấu
/**/ /**/ void changeCost(Admin admin, Dish dish);  
/**/ /**/ void addQuanlity(Admin admin, Dish dish); 
/**/ /**/ void deleteDish(Admin admin,Dish dish);
/**/ void seenListDish(Admin admin);                

void historyA(Admin admin); // cl

/*------------------------------------Menustaff------------------------------------*/
void menuStaff(Staff staff);

void openComputer(Staff staff);  // cl
void statusComuter(Staff staff); // cl
void historyS(Staff staff);      // cl
void seenCustomer(Staff staff);  // cl

#endif