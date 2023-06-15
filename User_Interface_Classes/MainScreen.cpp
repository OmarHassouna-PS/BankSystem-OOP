#include "MainScreen.h"
#include "TransactionsScreen.h"

// MainScreen Class

void MainScreen::_CheckPermissions ( short UserSessionPermissions, short OperationNumber ) {

    if ( UserSessionPermissions & OperationNumber )
        return;
    _ShowBar("Access Denied,\nYou dont have Permission to do this,\n    Please Contact Your Admin!");
    system("pause");
    return OperationCenter();
}

void MainScreen::_ShowBar ( string MessageBar ) {
    cout << "---------------------------------\n";
    cout << "\t" << MessageBar << endl;
    cout << "---------------------------------\n";
}

void MainScreen::_ShowMainMenu() {

    system("cls");
    Screen::_ShowScreenHeader("\t\tMain");
    cout << setw(37) << left << "" << "=================================\n";
    cout << setw(37) << left << "" << "\tMain Menu Screen\n";
    cout << setw(37) << left << "" << "=================================\n";
    cout << setw(37) << left << "" << "\t[1] show Client List.\n";
    cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
    cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
    cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
    cout << setw(37) << left << "" << "\t[5] Find Client.\n";
    cout << setw(37) << left << "" << "\t[6] Transactions.\n";
    cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
    cout << setw(37) << left << "" << "\t[8] Transaction Records Procedures.\n";
    cout << setw(37) << left << "" << "\t[9] Total Balances For All Clients.\n";
    cout << setw(37) << left << "" << "\t[10] Logout.\n";
    cout << setw(37) << left << "" << "=================================\n";
}

void MainScreen::OperationCenter() {

    _ShowMainMenu();
    short ChooseMin = 1, ChooseMax = 10;

    switch ( (eAppOption) Validation::GetNumber ("Choose what do you to do? [1 To 10]? ", ChooseMin, ChooseMax) ) {
        case eAppOption::eShowClientList :
            system("cls");
            _CheckPermissions(-1,1); 
            _ShowBar("Show Client List");
            ShowAllDataScreen::UI_ShowALLClientsData();
            system("pause");
            return MainScreen::OperationCenter();
        case eAppOption::eAddNewClient :
            system("cls");
            _CheckPermissions(-1,2);
            _ShowBar("Add New Client");
            AddClientScreen::UI_AddNewClient();
            system("pause");
            return MainScreen::OperationCenter();
        case eAppOption::eDeleteClient :
            system("cls");
            _CheckPermissions(-1,4);
            _ShowBar("Delete Client");
            DeleteClientScreen::UI_DeleteClient();
            system("pause");
            return MainScreen::OperationCenter();
        case eAppOption::eUpdateClientInfo :
            system("cls");
            _CheckPermissions(-1,8);
            _ShowBar("Update Client Info");
            UpdateClientScreen::UI_UpdateClient();
            system("pause");
            return MainScreen::OperationCenter();
        case eAppOption::eFindClient :
            system("cls");
            _CheckPermissions(-1,16);
            _ShowBar("Find Client");
            FindClientScreen::UI_FindClient();
            system("pause");
            return MainScreen::OperationCenter();
        case eAppOption::eTransactionsMenu :
            system("cls");
            _CheckPermissions(-1,32);
            TransactionsScreen::Transactions();
            return MainScreen::OperationCenter();
            case eAppOption::eManageUsersMenu :
            system("cls");
            _CheckPermissions(-1,64);
            /* ManageUsers(); */
            return MainScreen::OperationCenter();
            /*
        case eAppOption::eShowClientsTransactions :
            system("cls");
            _CheckPermissions(-1,128);
            TransactionRecordsProcedures();
            return OperationCenter();
        case eAppOption::eTotalBalancesForAllClients :
            system("cls");
            _CheckPermissions(-1,256);
            ShowTotalBalancesForAllClients();
            system("pause");
            return OperationCenter();
        case eAppOption::eLogOut :
            return Login(); */
    }
}

// ShowAllDataScreen Class

void ShowAllDataScreen::UI_ShowALLClientsData () {

    vector<Clients> vClients = GetAllClients::GetAll();
    if (vClients.size() == 0)
        cout << "\t\tNo Clients Available!\n";

    cout << "\t\t\t\tClient List (" << vClients.size() << ")" << " Client(s).";
    cout << "\n__________________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(5)  << "ID";
    cout << "| " << left << setw(15) << "AccountNumber";
    cout << "| " << left << setw(10) << "PinCode";
    cout << "| " << left << setw(10) << "Name";
    cout << "| " << left << setw(15) << "Emile";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(15) << "Account Balance";
    cout << "| " << left << setw(26) << "Operations Number";
    cout << "\n__________________________________________________________________________________________________________\n\n";

    for (Clients Client : vClients)
    {
        cout << "| " << left << setw(5)  << Client.GetID();
        cout << "| " << left << setw(15) << Client.GetAccountNumber();
        cout << "| " << left << setw(10) << Client.GetPinCode();
        cout << "| " << left << setw(10) << Client.GetName();
        cout << "| " << left << setw(15) << Client.GetEmile();
        cout << "| " << left << setw(12) << Client.GetPhone();
        cout << "| " << left << setw(15) << Client.GetAccountBalance();
        cout << "| " << left << setw(26) << Client.GetOperationsNumber();
        cout << "\n";
    }
    cout << "\n__________________________________________________________________________________________________________\n\n";
}

// AddClientScreen Class

void AddClientScreen::UI_AddNewClient () {
    do
    {
        string AccountNumber = Validation::GetAccountNumberNotExists();
        if (AccountNumber == "NULL") return;

        short IDWillCreateAuto = 0, NoTransaction = 0;

        Clients Client = Validation::GetNewClient(AccountNumber);

        if (AddClient::Add(Client)) {
            Validation::ErrorMessage("Something wrong With the Database, Please send The error Massage To Admin");
            return;
        }
        
    } while (toupper(Validation::GetChar("\nClient Added Successfully, do you want to add more clients? Y/N ? ")) == 'Y');
    cout << "\n\nClient Added Successfully.\n" << endl;
}

// DeleteClientScreen Class

void DeleteClientScreen::UI_DeleteClient() {

    string AccountNumber = Validation::GetValidAccountNumber();

    if ( AccountNumber == "NULL" ) return;

    if ( toupper(Validation::GetChar("\nAre you sure you delete this client Y/N ? ")) == 'Y' )
        DeleteClient::Delete(AccountNumber);
    else 
        cout << "\nOperation cancelled.\n";
}

// UpdateClientScreen Class

void UpdateClientScreen::UI_UpdateClient() {
    do
    {
        string AccountNumber = Validation::GetValidAccountNumber();

        if (AccountNumber == "NULL") return;

        Clients OldClientData = FindClient::Find(AccountNumber);

        OldClientData.PrintInfo();

        Clients NewClientData = Validation::UpdateClientInfo(OldClientData);

        if (UpdateClient::Update(NewClientData)) {
            Validation::ErrorMessage("Something wrong With the Database, Please send The error Massage To Admin");
            return;
        }
        
    } while (toupper(Validation::GetChar("\nClient Added Successfully, do you want to add more clients? Y/N ? ")) == 'Y');
    cout << "\n\nClient Updated Successfully.\n" << endl;
}

// FindClientScreen Class

void FindClientScreen::UI_FindClient() {

    string AccountNumber = Validation::GetValidAccountNumber();

    if (AccountNumber == "NULL") return;

    Clients Client = FindClient::Find(AccountNumber);

    Client.PrintInfo();
}
