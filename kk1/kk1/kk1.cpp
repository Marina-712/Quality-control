#include "TVSet.h"
#include "Constants.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    TVSet tv;
    string line;

    while (getline(cin, line))
    {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "TurnOn")
        {
            tv.TurnOn();
        }
        else if (command == "TurnOff")
        {
            tv.TurnOff();
        }
        else if (command == "SelectChannel")
        {
            int ch;
            if (iss >> ch)
            {
                tv.SelectChannel(ch);
            }
            else
            {
                cout << ERROR_MESSAGE << endl;
            }
        }
        else if (command == "Info")
        {
            tv.Info();
        }
        else
        {
            cout << ERROR_MESSAGE << endl;
        }
    }

    return 0;
}