#include "Clients.h"

SQLite* SQL_Clients = SQL_Clients->CreateDatabase();

// Clients Class

Clients::Clients (
    int ID, string AccountNumber, string PinCode, string Name, string Emile, string Phone,
    double AccountBalance, int NumberRecentTransactions ) :  
Persons(Name, Emile, Phone), _AccountNumber(AccountNumber), _PinCode(PinCode),
    _AccountBalance(AccountBalance), _OperationsNumber(NumberRecentTransactions), _ID(ID) {}

Clients Clients::_ConvertQueryToObjectClient (vector<string> Query, bool status) {
    return (!status) ? Clients(stoi(Query[0]), Query[1], Query[2], Query[3], Query[4], Query[5], stod(Query[6]), stoi(Query[7]))
    : Clients(0, "", "", "", "", "", 0, 0);
}

void Clients::SetAccountNumber    (string AccountNumber)  { _AccountNumber = AccountNumber; }
void Clients::SetAccountBalance   (double AccountBalance) { _AccountBalance = AccountBalance; }
void Clients::SetOperationsNumber (int OperationsNumber)  { _OperationsNumber = OperationsNumber; }
void Clients::SetPinCode          (string PinCode)        { _PinCode = PinCode; }

int    Clients::GetID               () { return _ID; }
string Clients::GetPinCode          () { return _PinCode ; }
string Clients::GetAccountNumber    () { return _AccountNumber ; }
double Clients::GetAccountBalance   () { return _AccountBalance ; }
int    Clients::GetOperationsNumber () { return _OperationsNumber ; }

void Clients::PrintInfo () {
    cout << "\n --------------------\n";
    cout << "\tInformation: ";
    cout << "\n --------------------\n";
    cout << "\n ID  : "             << GetID();
    cout << "\n Name  : "           << GetName();
    cout << "\n Emile : "           << GetEmile();
    cout << "\n Phone : "           << GetPhone();
    cout << "\n Account Number : "  <<  _AccountNumber;
    cout << "\n PinCode : "         << _PinCode;
    cout << "\n Account Balance : " << _AccountBalance;
    cout << "\n Number Recent Transactions : " << _OperationsNumber;
    cout << "\n --------------------\n";
}

// FindClient Class
Clients FindClient::Find ( string AccountNumber ) {
    
    string Query = "SELECT * from Clients where AccountNumber = '" + AccountNumber + "';";
    vector<string> Info;

    SQL_Clients->OpenDatabase();
    bool status = SQL_Clients->ExecuteQuery(Query, Info);
    SQL_Clients->CloseDatabase();

    return _ConvertQueryToObjectClient(Info, status);
}

Clients FindClient::Find ( string AccountNumber, string PinCode ) {

    string Query = "SELECT * FROM Clients WHERE AccountNumber = '" + AccountNumber 
    + "' AND PinCode = '" + PinCode + "';";
    vector<string> Info;

    SQL_Clients->OpenDatabase();
    bool status = SQL_Clients->ExecuteQuery(Query, Info);
    SQL_Clients->CloseDatabase();

    return _ConvertQueryToObjectClient(Info, status);
}

bool FindClient::IsFound ( string AccountNumber ) {

    string Query = "SELECT * from Clients where AccountNumber = '" + AccountNumber + "';";
    vector<string> Info = {"0"};

    SQL_Clients->OpenDatabase();
    bool Result = SQL_Clients->ExecuteQuery(Query, Info);
    SQL_Clients->CloseDatabase();
    
    if (Info[0] == "0")
        return true;
    return false;
}

// UpdateClient Class 
bool UpdateClient::Update (Clients Client) {
    string Query = "UPDATE Clients SET " \
    "PinCode = '"                  + Client.GetPinCode() + "'," \
    "Name = '"                     + Client.GetName()+ "'," \
    "Emile = '"                    + Client.GetEmile() + "'," \
    "Phone = '"                    + Client.GetPhone()+ "'," \
    "AccountBalance = '"           + to_string(Client.GetAccountBalance()) + "'," \
    "NumberRecentTransactions = '" + to_string(Client.GetOperationsNumber())+ "' " \
    "WHERE AccountNumber = '"      + Client.GetAccountNumber()+ "';";
    SQL_Clients->OpenDatabase();
    return SQL_Clients->ExecuteQuery(Query);
    SQL_Clients->CloseDatabase();
}


// DeleteClient Class 

bool DeleteClient::Delete (string AccountNumber) {
    string Query = "DELETE FROM Clients WHERE AccountNumber = '" + AccountNumber + "';";

    SQL_Clients->OpenDatabase();
    bool Result = SQL_Clients->ExecuteQuery(Query);
    SQL_Clients->CloseDatabase();

    return Result;
}


// AddClient Class 

bool AddClient::Add (Clients Client) {
    string Query = "INSERT INTO Clients (AccountNumber, PinCode, Name, Emile, Phone, AccountBalance, NumberRecentTransactions) " \
        "VALUES ('"  + Client.GetAccountNumber()+
        "', '"     + Client.GetPinCode() +
            "', '"   + Client.GetName() +
            "', '"   + Client.GetEmile() +
            "', '" + Client.GetPhone() +
            "', "  + to_string(Client.GetAccountBalance()) +
                ", 0)";
    SQL_Clients->OpenDatabase();
    bool Result = SQL_Clients->ExecuteQuery(Query);
    SQL_Clients->CloseDatabase();
    return Result;
}

// GetAllClients Class 

vector<Clients> GetAllClients::GetAll () {
    string Query = "SELECT * from Clients;";

    vector<Clients> vClients;
    vector<string> Info;
    vector<string> temp;

    SQL_Clients->OpenDatabase();
    bool Result = SQL_Clients->ExecuteQuery(Query, Info);
    SQL_Clients->CloseDatabase();
    short Count = 0;
    
    for (size_t i = 0; i < Info.size(); i++) {
    temp.push_back(Info[i]);
    Count++;
    
    if (Count == 8) {
        vClients.push_back(_ConvertQueryToObjectClient(temp, Result));
        temp.clear();
        Count = 0;
    }
    } 
    return vClients;
}



