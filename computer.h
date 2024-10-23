#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
using namespace std;
// Id, Cost, Status, type ,totaltime
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
};
/*------------------------------------Friend------------------------------------*/
bool operator>>(istream &in, Computer &computer);
/*------------------------------------Other------------------------------------*/

#endif