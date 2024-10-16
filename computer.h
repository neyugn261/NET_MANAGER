#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;
//Id, Cost, Status, type ,totaltime
class Computer
{
private:
    string id;   
    string cost;
    string status;
    string type;
    string totaltime;
public:   
    ~Computer();
    string getId();    
    string getCost();
    string getStatus();
    string getType();
    string getTotaltime();

    void setId(string);  
    void setCost(string);
    void setStatus(string);
    void setType(string);
    void setTotaltime(string);

    friend bool operator>>(istream &in, Computer &computer);   
    friend bool getComputerFromFile(fstream &file, Computer &computer);  
    friend bool checkComputer(Computer &computer);
};
/*------------------------------------Friend------------------------------------*/
bool operator>>(istream &in, Computer &computer);
bool getComputerFromFile(fstream &file, Computer &computer);
bool checkComputer(Computer &computer);
/*------------------------------------Other------------------------------------*/
bool dataOfEmptyIdComputer(fstream &file, int &count);
int numberFromEmptyId();
int getNumberOfComputer();
void updateNumberOfComputer(int count);
void updateComputerToFile(Computer computer);

#endif