#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include "User_Interface_Classes/TransactionsScreen.h"

using namespace std;

SQLite* SQL_Main = SQL_Main->CreateDatabase();

void CreatTables ();
void InsertData ();

class Users : public Persons {
  
  private:
    string _UserName , _Password;
    int _Permissions, _ID;

  public:
    Users (int ID, string UserName, string Password, string Name, string Emile, string Phone, int Permissions) :  
     Persons(Name, Emile, Phone), _UserName(UserName), _Password(Password), _Permissions(Permissions), _ID(ID) {}

    static Users ConvertQueryToObject (vector<string> Query) {
        return (Query[0] != "NULL") ? Users(stoi(Query[0]), Query[1], Query[2], Query[3], Query[4], Query[5], stoi(Query[6])) : 
        Users(0, "", "", "", "", "", 0);
    }

    void SetUserName    (string UserName) { _UserName = UserName; }
    void SetPassword    (string Password) { _Password = Password; }
    void SetPermissions (int Permissions) { _Permissions = Permissions; }

    int GetID          () { return _ID; }
    string GetUserName () { return _UserName ; }
    string GetPassword () { return _Password ; }
    int GetPermissions () { return _Permissions ; }

    void PrintInfo () {
    cout << "Information: ";
    cout << "\n --------------------\n";
    cout << "\n Name  : "    << GetName();
    cout << "\n Emile : "    << GetEmile();
    cout << "\n Phone : "    << GetPhone();
    cout << "\n UserName : " << _UserName;
    cout << "\n Password : " << _Password;
    cout << "\n --------------------\n";
  }
};

class Transaction {

  private:     
    string _Date, _Time, _MovementType;

  public:
    Transaction (string Date, string Time, string MovementType) : 
     _Date(Date), _Time(Time), _MovementType(MovementType) {}
    
    void SetDate          (string Date)          { _Date = Date; }
    void SetTime          (string Time)          { _Time = Time; }
    void SetMovementType  (int MovementType)     { _MovementType = MovementType; }
    

    string GetDate          () { return _Date ; }
    string GetTime          () { return _Time ; }
    string GetMovementType  () { return _MovementType ; }
    
};

class TransactionClients : public Transaction {
  
  private:
    string _AccountNumber;
    int _ID, _Amount, _ClientID;
    double _Balance;

  public:
    TransactionClients (int ID, string AccountNumber, string MovementType, int Amount, double Balance, string Date, string Time, int ClientID) : 
    Transaction (Date, Time, MovementType), _ID(ID) , _AccountNumber(AccountNumber), _Amount(Amount) , _ClientID(ClientID) , _Balance(Balance) {}

    static TransactionClients ConvertQueryToObject (vector<string> Query) {
      return (Query[0] != "NULL") ? TransactionClients(stoi(Query[0]), Query[1], Query[2], stoi(Query[3]), stod(Query[4]), Query[5], Query[6], stoi(Query[7])) : 
      TransactionClients(0, "", "", 0, 0, "", "", 0);
    }

    void SetAmount  (int Amount)  { _Amount = Amount; }
    void SetBalance (int Balance) { _Balance = Balance; }
    void SetAccountNumber (string AccountNumber) { _AccountNumber = AccountNumber; }

    int    GetID            () { return _ID ; }
    int    GetClientID      () { return _ClientID ; }
    int    GetAmount        () { return _Amount ; }
    double GetBalance       () { return _ClientID ; }
    string GetAccountNumber () { return _AccountNumber ; }
};

class TransactionUsers  : public Transaction {
  
  private:
    string _UserName, _Details;
    int _ID, _UserID;

  public:
    TransactionUsers (int ID, string UserName, string MovementType, string Details, string Date, string Time, int UserID) : 
    Transaction (Date, Time, MovementType), _ID(ID) , _UserName(UserName) , _UserID(UserID) , _Details(Details) {}

    static TransactionUsers ConvertQueryToObject (vector<string> Query) {
      return (Query[0] != "NULL") ? TransactionUsers(stoi(Query[0]), Query[1], Query[2], Query[3], Query[4], Query[5], stoi(Query[6])) : 
      TransactionUsers(0, "", "", "", "", "", 0);
    }
    void SetUserName (string UserName) { _UserName = UserName; }
    void SetDetails  (string Details)  { _Details = Details; }

    int    GetID         () { return _ID ; }
    int    GetUserID     () { return _UserID ; }
    string GetUserName   () { return _UserName ; }
    string GetDetails    () { return _Details ; }
};



void ShowTotalBalances ()
{
  vector<Clients> vClients = GetAllClients::GetAll();

  if (vClients.size() == 0)
      cout << "\t\tNo Clients Available!\n";

  cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n" << endl;

  cout << "| " << left << setw(15) << "Account Number";
  cout << "| " << left << setw(40) << "Client Name";
  cout << "| " << left << setw(12) << "Balance";
  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n" << endl;

  double TotalBalances = 0;

  for (Clients Client : vClients)
  {
    cout << "| " << setw(15) << left << Client.GetAccountNumber();
    cout << "| " << setw(40) << left << Client.GetName();
    cout << "| " << setw(12) << left << Client.GetAccountBalance();
    cout << endl;
    TotalBalances += Client.GetAccountBalance();
  }

  cout << "\n_______________________________________________________";
  cout << "_________________________________________\n" << endl;
  cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
  cout << "\t\t\t\t\t   ( " << Validation::NumberToText(TotalBalances) << ")";
}

/* 
int main(int argc, char** argv) {


  if (argc != 2) {
    cout << "You must enter the path of the database, if any,\n" \
    "or enter the name and path of the database to create it automatically\n";
    return 0;
  }
  CreatTables (); 
*/

int main() {
  
  SQL_Main->SetPathDatabaseFile("Bank.db");
  bool status = SQL_Main->OpenDatabase();
  //CreatTables ();
  //InsertData ();

  //Clients a(1, "A3", "1", "1", "1", "1", 1, 0);
  //AddClient::Add(a);

  //a.SettName("OMAR");
  //bool bo = UpdateClient::Update(a);

/*   Clients s = FindClient::Find("A1");
  Clients c = FindClient::Find("A3");

  s.PrintInfo();
  c.PrintInfo();

  cout << Validation::GetAccountNumberNotExists() << endl;  */

  //TransactionsScreen::Transactions();

  MainScreen::OperationCenter();


  SQL_Main->CloseDatabase();
  SQL_Main->DeletePointerDatabase();
  return 0;
}

void CreatTables () {

  //              SQL_Main statement
  //   Create the main tables for the project

  //SQL_Main->ExecuteQuery("PRAGMA foreing_keys = ON");

  // Client Table
  SQL_Main->ExecuteQuery(         
          "\nCREATE TABLE IF NOT EXISTS Clients (\n"    \
          "\t\t ID INTEGER PRIMARY KEY     NOT NULL,\n" \
          "\t\t AccountNumber  TEXT        NOT NULL      UNIQUE,\n" \
          "\t\t PinCode        TEXT        NOT NULL,\n" \
          "\t\t Name           CHAR(50)    NOT NULL,\n" \
          "\t\t Emile          CHAR(50)    NOT NULL,\n" \
          "\t\t Phone          CHAR(15)    NOT NULL,\n" \
          "\t\t AccountBalance REAL        NOT NULL,\n" \
          "\t\t NumberRecentTransactions SMALLINT \n\t\t);"
        );
  // Transaction_Clients Table
  SQL_Main->ExecuteQuery(         
          "\nCREATE TABLE IF NOT EXISTS TransactionClients (\n"  \
          "\t\t ID INTEGER PRIMARY KEY NOT NULL,\n" \
          "\t\t AccountNumber TEXT     NOT NULL,\n" \
          "\t\t MovementType  CHAR(15) NOT NULL,\n" \
          "\t\t Amount        INTEGER  NOT NULL,\n" \
          "\t\t Balance       REAL     NOT NULL,\n" \
          "\t\t Date          DATE     NOT NULL,\n" \
          "\t\t Time          DATETIME NOT NULL,\n" \
          "\t\t ClientID     INTEGER  NOT NULL,\n" \
          "\t\t FOREIGN KEY (ClientID) REFERENCES Client(ID) \n\t\t);"
        );
  // Users Table
  SQL_Main->ExecuteQuery(         
          "\nCREATE TABLE IF NOT EXISTS Users (\n"  \
          "\t\t ID INTEGER  PRIMARY KEY  NOT NULL,\n" \
          "\t\t UserName    TEXT  UNIQUE NOT NULL,\n" \
          "\t\t Password    TEXT         NOT NULL,\n" \
          "\t\t Name        CHAR(50)     NOT NULL,\n" \
          "\t\t Emile       CHAR(50)     NOT NULL,\n" \
          "\t\t Phone       CHAR(15)     NOT NULL,\n" \
          "\t\t Permissions SMALLINT     NOT NULL \n\t\t);"
        );
  // Transaction_Users Table
  SQL_Main->ExecuteQuery(         
          "\nCREATE TABLE IF NOT EXISTS TransactionUsers (\n"  \
          "\t\t ID INTEGER PRIMARY KEY  NOT NULL,\n" \
          "\t\t UserName       TEXT     NOT NULL,\n" \
          "\t\t MovementType   CHAR(15) NOT NULL,\n" \
          "\t\t Details        TEXT     NOT NULL,\n" \
          "\t\t Date           DATE     NOT NULL,\n" \
          "\t\t Time           DATETIME NOT NULL,\n" \
          "\t\t UserID         INTEGER  NOT NULL,\n" \
          "\t\t FOREIGN KEY (UserID) REFERENCES Users(ID) \n\t\t);"
        );
}

void InsertData () {

  SQL_Main->ExecuteQuery("INSERT INTO Clients (AccountNumber, PinCode, Name, Emile, Phone, AccountBalance, NumberRecentTransactions) " \
                    "VALUES ('A1', '1234', 'Omar', 'Omar@gmail.com', '0777777777', 1000.00, 0);");

  SQL_Main->ExecuteQuery("INSERT INTO Clients (AccountNumber, PinCode, Name, Emile, Phone, AccountBalance, NumberRecentTransactions) " \
                    "VALUES ('A2', '5678', 'Ahmad', 'Ahmad@gmail.com', '07888888888', 2000.00, 0);");

  SQL_Main->ExecuteQuery("INSERT INTO TransactionClients (AccountNumber, MovementType, Amount, Balance, Date, Time, ClientID) " \
                    "VALUES ('A1', 'Deposit', 100, 900, '2/8/2022', '4:30', 1);");
                    
  SQL_Main->ExecuteQuery("INSERT INTO Users (UserName, Password, Name, Emile, Phone, Permissions) " \
                    "VALUES ('Admin', '1234', 'Omar', 'Omar@gmail.com', '0777777777', -1);");

  SQL_Main->ExecuteQuery("INSERT INTO TransactionUsers (UserName, MovementType, Details, Date, Time, UserID) " \
                    "VALUES ('Admin', 'Delete', 'Delete client', '2/8/2022', '4:30', 1)");
}