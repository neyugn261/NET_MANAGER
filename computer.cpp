#include "function.h"
#include "computer.h"

Computer::~Computer() {}
string Computer::getName() { return name; }
string Computer::getCost() { return cost; }
string Computer::getStatus() { return status; }
string Computer::getType() { return type; }
string Computer::getTotaltime() { return totaltime; }

void Computer::setName(string name) { this->name = name; }
void Computer::setCost(string cost) { this->cost = cost; }
void Computer::setStatus(string status) { this->status = status; }
void Computer::setType(string type) { this->type = type; }
void Computer::setTotaltime(string totaltime) { this->totaltime = totaltime; }

/*------------------------------------Friend------------------------------------*/

bool operator>>(istream &in, Computer &computer)
{
    cout << "Nhập giá: ";
    in >> computer.cost;

    cout << "Nhập loại: ";
    in >> computer.type;

    int id = numberFromEmptyId("./computer/emptyID.txt");
    if (id == -1)
    {
        id = getNumber("./computer/computerID.txt");
        id++;
        updateNumber("./computer/computerID.txt", id);
    }
    stringstream ss;
    ss << setw(3) << setfill('0') << id;
    computer.name = "PC" + ss.str();
    computer.status = "OFFLINE";
    computer.totaltime = "0";

    return true;
}

/*------------------------------------Other------------------------------------*/
