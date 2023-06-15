#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>
#include "Persons.h"
#include "SQLite.h"
using std::string;using std::vector;using std::to_string;using std::stoi;using std::stod;


class Clients : public Persons {
  
  private:
    string _AccountNumber, _PinCode;
    double _AccountBalance;
    int _OperationsNumber, _ID;

  protected:
      static Clients _ConvertQueryToObjectClient (vector<string> Query, bool status);

  public:

    Clients (
      int ID, string AccountNumber, string PinCode, string Name, string Emile, string Phone,
      double AccountBalance, int NumberRecentTransactions );

    void SetAccountNumber    (string AccountNumber);    
    void SetPinCode          (string PinCode);              
    void SetAccountBalance   (double AccountBalance);       
    void SetOperationsNumber (int OperationsNumber);         

    int    GetID               (); 
    string GetAccountNumber    (); 
    string GetPinCode          ();
    double GetAccountBalance   (); 
    int    GetOperationsNumber ();

    void PrintInfo ();
};

class FindClient : private Clients {

    public:
    static Clients Find ( string AccountNumber );

    static Clients Find ( string AccountNumber, string PinCode );

    static bool IsFound ( string AccountNumber );
};

class UpdateClient {
  public:
  static bool Update (Clients Client);
};

class DeleteClient {
  public:
  static bool Delete (string AccountNumber);
};

class AddClient {

  public:
  static bool Add (Clients Client);
};

class GetAllClients : private Clients  {

  public:
  static vector<Clients> GetAll ();
};


