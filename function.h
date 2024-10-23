#ifndef FUNCTION_H
#define FUNCTION_H 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <algorithm>
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
void ClearLine(SHORT posX, SHORT posY, int length);
void printSpace(int length);
void EnterNumber(string &x, int max, int min);
void EnterNumber(string &x, int n);
void EnterString(string &x, int n);
void EnterLetter(string &x, int n);

void toName(string &str);
void trim(string &str);
void toLower(string &str);

/*------------------------------------MENU------------------------------------*/
void optionMenu(string typeMenu, int option);
void printMenuOption(string typeMenu, int option, bool isSelected);
int getMenuOptionCount(const string &typeMenu);
void showMenu(string typeMenu, int selectOption, int x, int y);
void menuMain(int count, int x, int y);
void menuAdd(int x, int y);
/*------------------------------------MenusAdmin------------------------------------*/
void menuAdmin(Admin admin); 

void manageComputer(Admin admin);        
/**/ void menuAddComputer(Admin admin);  
/**/ /**/ void addComputer(Admin admin); 
/**/ void findComputer(Admin admin);
/**/ /**/ void changeComputer(Admin admin, Computer &computer);
/**/ /**/ /**/ //admin.changeCost(computer);
/**/ /**/ /**/ //admin.deleteComputer(computer);
/**/ //admin.seenListComputer();

void manageStaff(Admin admin);        
/**/ void menuAddStaff(Admin admin);  
/**/ /**/ void addStaff(Admin admin); 
/**/ void findStaff(Admin admin);
/**/ /**/ void changeStaff(Admin admin, Staff &staff);
/**/ /**/ /**/ //admin.changeSPassword(staff);
/**/ /**/ /**/ //admin.deleteStaff(staff);
/**/ //admin.seenListStaff();

void manageCustomer(Admin admin);                                   
/**/ void menuAddCustomer(Admin admin);                             
/**/ /**/ void addCustomer(Admin admin);                            
/**/ void findCustomer(Admin admin);                                
/**/ /**/ void changeCustomer(Admin admin, Customer &customer);     
/**/ /**/ /**/ //admin.deleteCustomer(customer);                    
/**/ //admin.seenListCustomer();


void manageDish(Admin admin);                             
/**/ void menuAddDish(Admin admin);                       
/**/ /**/ void addDish(Admin admin);                      
/**/ void findDish(Admin admin);                          
/**/ /**/ void changeDish(Admin admin, Dish &dish);       
/**/ /**/ /**/ //admin.changeCost(dish);                  
/**/ /**/ /**/ //admin.addQuanlity(dish);                 
/**/ /**/ /**/  //admin.deleteDish(dish);                 
/**/ //admin.seenListDish();

void historyA(Admin admin); // cl

/*------------------------------------Menustaff------------------------------------*/
void menuStaff(Staff staff);

void openComputer(Staff staff);   // cl
void statusComputer(Staff staff); // cl
void historyS(Staff staff);       // cl
void seenCustomer(Staff staff);   // cl

/*------------------------------------Other------------------------------------*/
bool dataOfEmptyId(fstream &file, int &count);

void updateAdminToFile(Admin admin);
void updateStaffToFile(Staff staff);
void updateDishToFile(Dish dish);
void updateCustomerToFile(Customer customer);
void updateComputerToFile(Computer computer);

void deleteAndRenameFile(string oldPath, string newPath);
int numberFromEmptyId(string path);
int getNumber(string path);
void updateNumber(string path, int count);

template <class T>
bool getObjectFromFile(fstream &file, T &object);

template <class T>
bool checkIdObject(T &object);

template <class T>
bool checkNameObject(T &object);

bool checkAname(string aname);
bool checkAnameStaff(Staff &staff);

#endif