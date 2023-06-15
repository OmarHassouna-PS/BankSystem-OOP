#include "TransactionsScreen.h"

void TransactionsScreen::_ShowTransactionsMenu() {
    system("cls");
    Screen::_ShowScreenHeader("\tMain");
    cout << "=======================================\n";
    cout << "\tTransactions Menu Screen\n";
    cout << "=======================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] TotalBalances.\n";
    cout << "\t[4] MainMenu.\n";
    cout << "=======================================\n";
}

void TransactionsScreen::Transactions () {

    system("cls");

    _ShowTransactionsMenu();
    system("pause");
}
    
/*         switch ( Vailadton::GetNumber ("Choose what do you to do? [1 To 4]? ", 1, 4 ))
    {
    case eTransactions::eDeposit :
        system("cls");
        ShowBar("Deposit Screen");
        Deposit(vClients);
        system("pause");
        return Transactions();
    case eTransactions::eWithdraw :
        system("cls");
        ShowBar("Withdraw Screen");
        Withdraw(vClients);
        system("pause");
        return Transactions();
    case eTransactions::eTotalBalances :
        system("cls");
        ShowBalance();
        system("pause");
        return Transactions();
    case eTransactions::etMainMenu :
        system("cls");
        break;
    } */
