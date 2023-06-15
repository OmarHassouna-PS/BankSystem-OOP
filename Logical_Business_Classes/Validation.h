#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include "Clients.h"

using namespace std;

class Validation {
    public:
    static int GetNumber (string Message, int Min = 0, int Max = 10000);

    static string GetString (string Message);

    static char GetChar (string Message);
    
    static string NumberToText(int Number);

    static void ErrorMessage (string Message);

    static string GetAccountNumberNotExists ();

    static string GetValidAccountNumber ();

    static Clients GetNewClient (string AccountNumber);

    static Clients UpdateClientInfo (Clients OldData);
};



