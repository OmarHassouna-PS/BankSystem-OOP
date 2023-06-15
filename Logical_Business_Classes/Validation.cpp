#include "Validation.h"


int Validation::GetNumber (string Message, int Min, int Max) {

    int Number = 0;
    cout << Message;
    cin >> Number;
    
    while (Number < Min || Number > Max || cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << Message;
        cin >> Number;
    } 
    
    return Number;
}

string Validation::GetString (string Message) {

    string STR = "\0"; 
    cout << Message;
    getline(cin >> ws, STR);

    return STR;
}

char Validation::GetChar (string Message) {

    char Char = 'Y'; 
    cout << Message;
    cin >> Char;
    return Char;
}

string Validation::NumberToText(int Number) { 

    if (Number == 0) {
        return"";     
    } 

    if (Number >= 1 && Number <= 19) {
        string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" }; 
        return  arr[Number] + " ";     
    } 
    if (Number >= 20 && Number <= 99) { 
        string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return  arr[Number / 10] + " " + NumberToText(Number % 10);     
    } 
    if (Number >= 100 && Number <= 199) {
        return"One Hundred " + NumberToText(Number % 100);     
    } 
    if (Number >= 200 && Number <= 999) { 
        return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    } 
    if (Number >= 1000 && Number <= 1999) {
        return"One Thousand " + NumberToText(Number % 1000);    
    } 
    if (Number >= 2000 && Number <= 999999) { 
        return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000); 
    } 
    if (Number >= 1000000 && Number <= 1999999) {
        return"One Million " + NumberToText(Number % 1000000);     
    } 
    if (Number >= 2000000 && Number <= 999999999) { 
        return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    } 
    if (Number >= 1000000000 && Number <= 1999999999) {
        return"One Billion " + NumberToText(Number % 1000000000);
    } 
    else { 
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }
} 

void Validation::ErrorMessage (string Message) {
    cout << "---------------------------------\n";
    cout << "\t⚠" << Message << "\t⚠" << endl;
    cout << "---------------------------------\n";
}

string Validation::GetAccountNumberNotExists () {

    string AccountNumber = Validation::GetString("Please Enter Account Number Client? ");

    if (AccountNumber == "exit") return "NULL";

    while (!FindClient::IsFound(AccountNumber)) {

        cout << "\nClient with (" << AccountNumber << ") already exists, \nEnter \"exit\" to return to the Main Menu Or Again\n";
        AccountNumber = Validation::GetString("Please Enter A Valid Account Number Client? ");

        if (AccountNumber == "exit") return "NULL";
    }
    return AccountNumber;
}

string Validation::GetValidAccountNumber () {

    string AccountNumber = "\0";
    AccountNumber = Validation::GetString("Please Enter Account Number Client? ");

    if (AccountNumber == "exit") return "NULL";
    
    while ( FindClient::IsFound( AccountNumber ) ) {   

        cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\nEnter \"exit\" to return to the Main Menu Or Again\n";
        AccountNumber = Validation::GetString("Please Enter A Valid Account Number Client? ");

        if (AccountNumber == "exit") return "NULL";
    }
    return AccountNumber;
}

Clients Validation::GetNewClient (string AccountNumber) {

    short IDWillCreateAuto = 0, NoTransaction = 0;
        
    string PinCode = Validation::GetString("Enter PinCode ? ");
    string Name = Validation::GetString("Enter Name ? ");
    string Email = Validation::GetString("Enter Email ? ");
    string Phone = Validation::GetString("Enter Phone ? ");
    double AccountBalance = Validation::GetNumber("Enter Account Balance ? ");

    Clients Client(IDWillCreateAuto, AccountNumber, PinCode, Name, Email, Phone, AccountBalance, NoTransaction);
    return Client;
}

Clients Validation::UpdateClientInfo (Clients OldData) {

    short IDWillCreateAuto = 0, NoTransaction = 0;
        
    string PinCode = Validation::GetString("Enter PinCode ? ");
    string Name = Validation::GetString("Enter Name ? ");
    string Email = Validation::GetString("Enter Email ? ");
    string Phone = Validation::GetString("Enter Phone ? ");
    double AccountBalance = Validation::GetNumber("Enter Account Balance ? ");

    Clients Client(OldData.GetID(), OldData.GetAccountNumber(), PinCode, Name, Email, Phone, AccountBalance, OldData.GetOperationsNumber());
    return Client;
}



