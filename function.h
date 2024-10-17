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
void ClearLine(SHORT posY);

/*------------------------------------MENU------------------------------------*/
void optionMenu(string typeMenu, int option);
void printMenuOption(string typeMenu, int option, bool isSelected);
int getMenuOptionCount(const string &typeMenu);
void showMenu(string typeMenu, int selectOption);

/*------------------------------------MenusAdmin------------------------------------*/
void menuAdmin(Admin admin);

void manageComputer(Admin admin);
/**/ void addComputer(Admin admin);      
/**/ void seenComputer(Admin admin);    //xong
/**//**/ void in4Computer(Admin admin, Computer computer); 
/**//**/ void changeCost(Admin admin, Computer computer);       
/**//**/ void deleteComputer(Admin admin,Computer computer);   
/**/ void seenListComputer(Admin admin); 

void manageCustomer(Admin admin);
/**/ void addCustomer(Admin admin);      
/**/ void deleteCustomer(Admin admin);   
/**/ void seenListCustomer(Admin admin); 

void manageStaff(Admin admin);
/**/ void addStaff(Admin admin);
/**/ void seenstaff(Admin admin); //xong
/**/ /**/ void in4Staff(Admin admin, Staff staff); 
/**/ /**/ void deleteStaff(Admin admin, Staff staff);
/**/ /**/ void changeSPassword(Admin admin, Staff staff);
/**/ void seenListStaff(Admin admin); 

void manageDish(Admin admin);
/**/ void addDish(Admin admin); //xong
/**/ void changeDish(Admin admin); //xong
/**/ /**/ void in4Dish(Admin admin, Dish dish); 
/**/ /**/ void changeCost(Admin admin, Dish dish);  
/**/ /**/ void addQuanlity(Admin admin, Dish dish); 
/**/ /**/ void deleteDish(Admin admin,Dish dish);
/**/ void seenListDish(Admin admin); //nên thêm sắp xếp           

void historyA(Admin admin); // cl

/*------------------------------------Menustaff------------------------------------*/
void menuStaff(Staff staff);

void openComputer(Staff staff);  // cl
void statusComputer(Staff staff); // cl
void historyS(Staff staff);      // cl
void seenCustomer(Staff staff);  // cl

#endif