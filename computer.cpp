#include "function.h"
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
    ClearLine(36, 3, 6);
    Gotoxy(36, 3);
    EnterNumber(computer.cost, 6,4);

    ShowCursor(false);

    ClearLine(37, 4, 11);

    int selectOption = 1;
    while (true)
    {
        Gotoxy(37, 3);
        cout << "┌───────────┐";
        Gotoxy(37, 4);
        cout << "│           │";
        Gotoxy(37, 5);
        cout << "│           │";
        Gotoxy(37, 6);
        cout << "│           │";
        Gotoxy(37, 7);
        cout << "│           │";
        Gotoxy(37, 8);
        cout << "│           │";
        Gotoxy(37, 9);
        cout << "└───────────┘";

        showMenu("TYPECOMPUTER", selectOption, 38, 4);
        int key = _getch();
        switch (key)
        {
        case KEY_UP:
            selectOption = (selectOption == 1) ? 5 : selectOption - 1;
            break;
        case KEY_DOWN:
            selectOption = (selectOption == 5) ? 1 : selectOption + 1;
            break;
        case KEY_ENTER:
            switch (selectOption)
            {
            case 1:
                computer.type = "Binh thuong";
                break;
            case 2:
                computer.type = "Cao cap";
                break;
            case 3:
                computer.type = "Cap doi";
                break;
            case 4:
                computer.type = "Thi dau";
                break;
            case 5:
                computer.type = "Stream";
                break;
            }
            break;
        }
        if (key == KEY_ENTER)
        {
            break;
        }
    }
    ClearLine(37, 3, 13);
    Gotoxy(36, 3);
    cout << computer.cost;
    Gotoxy(43,3);
    cout << "(VND/h)";
    ClearLine(37, 4, 13);
    Gotoxy(37, 5);
    cout << "═════════════";
    ClearLine(37, 6, 13);
    ClearLine(37, 7, 13);
    ClearLine(37, 8, 13);
    ClearLine(37, 9, 13);
    Gotoxy (37, 4);
    cout << computer.type;


    int id = numberFromEmptyId("./computer/emptyID.txt");
    if (id == -1)
    {
        id = getNumber("./computer/computerID.txt");
        id++;
        updateNumber("./computer/computerID.txt", id);
    }
    stringstream ss;
    ss << setw(3) << setfill('0') << id;
    computer.id = "M" + ss.str();

    computer.status = "OFFLINE";
    computer.totaltime = "0";

    return true;
}

/*------------------------------------Other------------------------------------*/
