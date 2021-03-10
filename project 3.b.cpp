 #include <iostream>     // for basic I/O
#include <string>       //includes the string class
#include <cstdlib>      // for various library functions
#include <stdlib.h>
#include <iomanip>   // Output formatting
using namespace std;

// start prototypes
void transition();
void splashScreen();
void exitScreen();
void inputError();
void insufficentFunds();
void inputScreen(string startingBalance, string checkNumber, string date, string transactionAmmount,string transactionType);
void outputScreen(float balance, string checkNumber, string date, float transaction,string transactionType);
void centerString(string str);
void mainMenuError();
void convertStrings(string, float&);
void conversionError(string);
// end prototypes
//this is a test

int main()
{

                            // Begin Data input strings
    string startingBalance = "XXX";
    string checkNumber = "XXX";
    string date = "XXX";
    string transactionAmmount = "XXX";
    string transactionType = "XXX";
    string resp = "XXX";

    int counter = 0;

                            // End data input strings

    splashScreen();
    //****************Start main menu**************
    do
  {
    system("cls");
    cout << endl;
    centerString("PERSONAL CHECKING REGISTER"); cout << endl;
    cout << endl;
    centerString("Main Menu"); cout << endl;
    cout << endl << endl;
    for(counter = 0; counter < 34; counter++)
        cout << " ";
    cout << "<I>nput Data" << endl;
    for(counter = 0; counter < 34; counter++)
        cout << " ";
    cout << "<E>xit" << endl;
    for(counter = 0; counter < 7; counter++)
        cout << endl;
    centerString("Enter I or E:  "); getline(cin, resp);

    switch(resp.at(0))
    {
    case 'I':
    case 'i':
         inputScreen(startingBalance, checkNumber, date, transactionAmmount, transactionType);
         break;

    case 'E':
    case'e':
        exitScreen();
        break;

    default:
        mainMenuError();

    }// End of switch(resp.at(0))
     }while((resp.at(0) != 'E') && (resp.at(0) != 'e'));

    return 0;
}// End of int main()

void inputScreen(string startingBalance, string checkNumber, string date, string transactionAmmount,string transactionType) {
    system("cls");
    cout << endl;
    cout << "                        PERSONAL CHECKING REGISTER" << endl;
    cout << endl;
    cout << "                               Input Screen" << endl;
    cout << endl;
    cout <<"              please enter the requested data then press <ENTER>" << endl;
    cout << endl;

    cout <<"starting balance:  "; getline(cin, startingBalance);   // begin prompts for user data
    cout << endl;

    cout <<"check number:  "; getline(cin, checkNumber);
    cout << endl;


    cout <<"date in the format MM/DD/YYYY:  "; getline(cin, date);
    cout << endl;

    cout <<"transaction amount:  "; getline(cin, transactionAmmount);
    cout << endl;

    cout <<"deposit or withdrawal:  "; getline(cin, transactionType);  // end  prompts for user data
    cout << endl << endl << endl << endl << endl << endl <<  endl << endl;
    float transaction = 0;
    float balance = 0;

    convertStrings(startingBalance, balance);
    convertStrings(transactionAmmount, transaction);


    outputScreen(balance,checkNumber,date,transaction,transactionType);


} // end of void inputScreen(string startingBalance, string checkNumber, string date, string transactionAmmount,string transactionType) {

void outputScreen(float balance, string checkNumber, string date, float transaction,string transactionType) {
    system("cls");
    cout << endl;
    cout << "                        PERSONAL CHECKING REGISTER" << endl;
    cout << endl;
    cout << "                               Output Screen" << endl;
    cout << endl;

    cout << "Starting balance:  " << balance << endl << endl;

    cout << "check number:  " << checkNumber << endl << endl;

    cout << "date:   " << date << endl << endl;

    cout << "transaction amount:  " << transaction << endl << endl;

    cout << "transaction type:  " << transactionType << endl << endl;

    if (transactionType.at(0) == 'd' || transactionType.at(0) == 'D')                   // this checks if the transaction is a deposit
    {
        balance += transaction;
        cout << "your balance after depositing " << transaction << " is now " << balance << endl;

    }  // end of  if (transactionType.at(0) == 'd' || transactionType.at(0) == 'D')
    else if (transactionType.at(0) == 'w' || transactionType.at(0) == 'W')
    {
        if (transaction > balance)
        {
            insufficentFunds();
        } // end of if (transaction > balance)
        else
        {
        balance -= transaction;
        cout << "your balance after withdrawing " << transaction << " is now " << balance << endl;
        } // end of else

    }  // end of else if (transactionType.at(0) == 'w' || transactionType.at(0) == 'W')
   else
    {
        inputError();
    }

    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    transition();
} // end of void outputScreen(string startingBalance, string checkNumber, string date, string transactionAmmount,string transactionType)


void transition()
{
    string resp = "XXX";

    cout << "                           Press <ENTER> to Continue"; getline(cin, resp);
    system("cls");
}       // End of void transition

void splashScreen()
{
    cout << endl;
    cout << endl;
    cout << "         ______________________________________________________________ " << endl;
    cout << "        | ____________________________________________________________ |" <<endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||   P E R S O N A L    C H E C K I N G   R E G I S T E R    | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                Programmer: Joshua Constine                | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                    revision: 03/03/2021                   | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        | ------------------------------------------------------------ |" << endl;
    cout << "         =========================|          | =========================" << endl;
    cout << "                                  |          |                          " << endl;
    cout << "                                  |          |                          " << endl;
    cout << "                                 ==============                         " << endl;
    cout << endl;
    transition();

}  // end of void splashScreen()

void exitScreen()
{
    system("cls");
    cout << endl;
    cout << endl;                                                                 // | 73
    cout << "         ______________________________________________________________ "    << endl;
    cout << "        | ____________________________________________________________ |" <<endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||   P E R S O N A L    C H E C K I N G   R E G I S T E R    | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                Programmer: Joshua Constine                | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||               thank you for using my program              | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        ||                                                           | |" << endl;
    cout << "        | ------------------------------------------------------------ |" << endl;
    cout << "         =========================|          | =========================" << endl;
    cout << "                                  |          |                         " << endl;
    cout << "                                  |          |                         " << endl;
    cout << "                                 ==============                        " << endl;
    cout << endl;
    transition();
} // end of void exitScreen()

void inputError()
{
    system("cls");
    cout << endl;
    cout << "                        PERSONAL CHECKING REGISTER" << endl;
    cout << endl;
    cout << "                                Error Screen" << endl << endl;
    cout << "There was an error with your input, check transaction type." << endl;
    cout << endl << endl << endl << endl << endl << endl <<  endl << endl << endl << endl << endl << endl;

} // end of void inputError()

void insufficentFunds() {
system("cls");
    cout << endl;
    cout << "                        PERSONAL CHECKING REGISTER" << endl;
    cout << endl;
    cout << "                                Error Screen" << endl << endl;
    cout << "your transaction amount is larger than your account balance." << endl;
    cout << endl << endl << endl << endl << endl << endl <<  endl << endl << endl << endl << endl << endl;
} // end of void insufficentFunds()

void centerString(string str) {
    int length = str.length();
    cout << setw(((80-length)/2)+(length)) << str;
} // end of void centerString(string str)

void mainMenuError() {
     system("cls");
    cout << endl;
    centerString("PERSONAL CHECKING REGISTER"); cout << endl;
    cout << endl;
    centerString("Main Menu Error"); cout << endl;
    cout << endl << endl;
    cout << "there was an error with your input, please enter (I)nput or (E)xit" << endl;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    transition();
}

void convertStrings(string str, float& converted) {

    while ((str.at(0) < '0') || (str.at(0) > '9')) {
        conversionError(str); getline(cin, str);
    }

        converted = atof(str.data());

}

void conversionError(string str) {
system("cls");
    cout << endl;
    cout << "                        PERSONAL CHECKING REGISTER" << endl;
    cout << endl;
    cout << "                                Error Screen" << endl << endl;
    cout << "There was an error with your input, you entered <" << str << "> input change and press <ENTER> to continue" << endl;
    cout << endl << endl << endl << endl << endl << endl <<  endl << endl << endl << endl << endl << endl;
}
