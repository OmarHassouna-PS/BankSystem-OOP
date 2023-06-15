#include "HeaderScreen.h"


using std::cout;using std::endl;using std::cin;using std::left;using std::swap;using std::string;


void Screen::_ShowScreenHeader (string MessageBar) {
    system("cls");
    cout << "\t\t\t\t  ---------------------------------------\n";
    cout << "\t\t\t\t  " << MessageBar << endl;
    cout << "\t\t\t\t  ---------------------------------------\n";
}

