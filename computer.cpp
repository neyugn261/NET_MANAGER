#include "computer.h"

Computer::~Computer() {}
string Computer::getId() { return id; }
string Computer::getCost() { return cost; }
string Computer::getStatus() { return status; }
string Computer::getType() { return type; }
string Computer::getTotaltime() { return totaltime; }

void Computer::setId(string id) { this->id = id; }
void Computer::setCost(string cost) { this->cost = cost; }
void Computer::setStatus(string status) { this->status = status; }
void Computer::setType(string type) { this->type = type; }
void Computer::setTotaltime(string totaltime) { this->totaltime = totaltime; }

/*------------------------------------Friend------------------------------------*/

bool operator>>(istream &in, Computer &computer)
{
    int id = numberFromEmptyId();
    if (id == -1)
    {
        id = getNumberOfComputer();
        id++;
        updateNumberOfComputer(id);
    }
    stringstream ss;
    ss << setw(3) << setfill('0') << id;
    computer.id = "PC" + ss.str();
    computer.status = "OFFLINE";
    computer.totaltime = "0";
    
    cout << "Nhập giá: ";
    in >> computer.cost;   

    cout << "Nhập loại: ";
    in >> computer.type;
   
    return true;
}

bool getComputerFromFile(fstream &file, Computer &computer)
{
    string line;
    if (!getline(file, line) || line.empty())
        return false;
    stringstream ss(line);
    getline(ss, computer.id, '|');
    getline(ss, computer.cost, '|');
    getline(ss, computer.status, '|');
    getline(ss, computer.type, '|');
    getline(ss, computer.totaltime);
    return true;
}


bool checkComputer(Computer &computer)
{
    string filename = "./computer/listComputer.txt";
    fstream file
    (filename, ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return false;
    }
    
    Computer temp;
    while (getComputerFromFile(file, temp))
    {
        if (temp.getId() == computer.getId())
        {
            computer = temp;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

/*------------------------------------Other------------------------------------*/

bool dataOfEmptyIdComputer(fstream &file, int &count)
{
    string line;
    getline(file, line);
    if (line.empty())
        return false;
    else
    {
        count = stoi(line);
        return true;
    }
}

int numberFromEmptyId()
{
    int count = -1;
    string path1 = "./computer/emptyID.txt";
    string tempPath1 = "./computer/temp1.txt";
    fstream file1(path1, ios::in);
    fstream temp1(tempPath1, ios::out);
    if (!file1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    if (!temp1.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    if (dataOfEmptyIdComputer(file1, count))
    {
        int ans = count;
        while (dataOfEmptyIdComputer(file1, count))
        {
            temp1 << count << endl;
        }
        file1.close();
        temp1.close();
        system("del .\\computer\\emptyID.txt");
        system("ren .\\computer\\temp1.txt emptyID.txt");
        return ans;
    }
    file1.close();
    temp1.close();
    system("del .\\computer\\temp1.txt");
    return count;
}

int getNumberOfComputer()
{
    int count = -1;
    fstream file("./computer/computerID.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return count;
    }
    else
        file >> count;
    file.close();
    return count;
}

void updateNumberOfComputer(int count)
{
    fstream file("./computer/computerID.txt", ios::out);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    file << count;
    file.close();
}

void updateComputerToFile(Computer computer)
{
    fstream file("./computer/listComputer.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Không thể mở file" << endl;
        return;
    }
    file << computer.getId() << "|" << computer.getCost() << "|" << computer.getStatus() << "|" << computer.getType() << "|" << computer.getTotaltime() << endl;
    file.close();
}

// #endif

