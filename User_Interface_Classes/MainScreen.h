#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "HeaderScreen.h"
#include "../Logical_Business_Classes/Validation.h"


using std::cout;using std::endl;using std::cin;using std::left;using std::setw;using std::string;

class MainScreen : protected Screen {

private:
    enum eAppOption { eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClientInfo = 4,
    eFindClient = 5, eTransactionsMenu = 6, eManageUsersMenu = 7, eShowClientsTransactions = 8, eTotalBalancesForAllClients = 9 ,eLogOut = 10};

    static void _CheckPermissions ( short UserSessionPermissions, short OperationNumber );

    static void _ShowBar ( string MessageBar );

    static void _ShowMainMenu();
public:

    static void OperationCenter();
};

class ShowAllDataScreen : public MainScreen {

public:
    static void UI_ShowALLClientsData ();
};

class AddClientScreen : public MainScreen { 

public:
    static void UI_AddNewClient ();
};

class DeleteClientScreen : public MainScreen { 

public:
    static void UI_DeleteClient();
};

class UpdateClientScreen : public MainScreen {

public:
    static void UI_UpdateClient();
};

class FindClientScreen : public MainScreen {

public:
    static void UI_FindClient();
};