#ifndef FUNCTION_H
#define FUNCTION_H 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <functional>
#include "admin.h"

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

/*------------------------------------MENUs------------------------------------*/
void menuAdmin(Admin admin); // cl
void menuStaff(Staff staff); // cl
/*------------------------------------MenusAdmin------------------------------------*/
void manageDish(Admin admin);                       // cl
/**/ void addDish(Admin admin);                     // cl
/**/ void deleteDish(Admin admin);                  // cl
/**/ void changeDish(Admin admin);                  // cl
/**/ /**/ void changeCost(Admin admin, Dish dish);  // cl
/**/ /**/ void addQuanlity(Admin admin, Dish dish); // cl
/**/ void seenListDish(Admin admin);                // cl

void manageComputer(Admin admin);        // cl
/**/ void addComputer(Admin admin);      // cl
/**/ void deleteComputer(Admin admin);   // cl
/**/ void changeCost(Admin admin);       // cl
/**/ void seenListComputer(Admin admin); // cl

void manageCustomer(Admin admin);        // cl
/**/ void addCustomer(Admin admin);      // cl
/**/ void deleteCustomer(Admin admin);   // cl
/**/ void seenListCustomer(Admin admin); // cl

void manageStaff(Admin admin);
/**/ void addStaff(Admin admin);       // cl
/**/ void deleteStaff(Admin admin);    // cl
/**/ void changePassword(Admin admin); // cl
/**/ void seenListStaff(Admin admin);  // cl
void historyA(Admin admin);            // cl
/*------------------------------------Menustaff------------------------------------*/
void openComputer(Staff staff);  // cl
void statusComuter(Staff staff); // cl
void historyS(Staff staff);      // cl
void seenCustomer(Staff staff);  // cl

#endif