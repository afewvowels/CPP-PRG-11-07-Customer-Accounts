//
//  main.cpp
//  CPP-PRG-11-07-Customer-Accounts
//
//  Created by Keith Smith on 11/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that uses a structure to store the following data about a customer
//  account:
//
//      Name
//      Address
//      City, State, and ZIP
//      Telephone Number
//      Account Balance
//      Date of Last Payment
//
//  The program should use an array of at least 10 structures. It should let the user enter
//  data into the array, change the contents of any element, and display all the data stored
//  in the array. The program should have a menu-driven user interface.
//
//  Input Validation: When the data for a new account is entered, be sure the user enters
//  data for all the fields No negative account balances should be entered.

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

const int INT_CUSTOMERS = 10;

struct StructCustomer
{
    string strName;
    string strAddress;
    string strCity;
    string strState;
    string strZipcode;
    string strTelephoneNumber;
    double dblAccountBalance;
    int intLastPaymentMonth;
    int intLastPaymentDay;
    int intLastPaymentYear;
};

int *displayMenu();
int *selectCustomerNumber();
StructCustomer *getCustomerInfo();
bool *validateState(string *);
bool *validateZipcode(string *);
bool *validatePhoneNumber(string *);
void displayCustomerInfo(StructCustomer *, int *);

int main()
{
    StructCustomer *scCustomers = nullptr;
    scCustomers = new StructCustomer[INT_CUSTOMERS];
    
    int *intMenuSelection = nullptr;
    intMenuSelection = new int;
    
    int *intCustomerNumber = nullptr;
    intCustomerNumber = new int;
    
    while(*intMenuSelection != 4)
    {
        intMenuSelection = displayMenu();
        if(*intMenuSelection == 1)
        {
            intCustomerNumber = selectCustomerNumber();
            cout << "\nPlease enter information for customer # " << *intCustomerNumber << ":\n";
            scCustomers[*intCustomerNumber] = *getCustomerInfo();
        }
        else if(*intMenuSelection == 2)
        {
            intCustomerNumber = selectCustomerNumber();
            displayCustomerInfo(&scCustomers[*intCustomerNumber], intCustomerNumber);
        }
    }
    
    cout << "\nYou have exited the program.\n\n";
    
    return 0;
}

int *displayMenu()
{
    int *intSelection = nullptr;
    intSelection = new int;
    
    cout << "\nPlease select from the following menu options:\n\n";
    cout << "\t1. Add customer data.\n";
    cout << "\t2. View customer data.\n";
    cout << "\t3. Display all customer data.\n";
    cout << "\t4. Exit.\n\n";
    cout << "Make your selection: ";
    
//    cin.clear();
//    cin.ignore();
    
    cin >> *intSelection;
    while(!cin || *intSelection < 1 || *intSelection > 4)
    {
        cout << "Please select from the available menu options: ";
        cin.clear();
        cin.ignore();
        cin >> *intSelection;
    }
    
    return intSelection;
}

int *selectCustomerNumber()
{
    int *intCustomerNumber = nullptr;
    intCustomerNumber = new int;
    
    cout << "Please select a customer number: ";
    cin >> *intCustomerNumber;
    while(!cin || *intCustomerNumber < 1 || *intCustomerNumber > INT_CUSTOMERS)
    {
        cout << "Please enter a number between 1 and " << INT_CUSTOMERS << ": ";
        cin.clear();
        cin.ignore();
        cin >> *intCustomerNumber;
    }
    
    return intCustomerNumber;
}

StructCustomer *getCustomerInfo()
{
    StructCustomer *scCustomer = nullptr;
    scCustomer = new StructCustomer;
    
    cout << "Please enter the customer's name: ";
    cin.clear();
    cin.ignore();
    getline(cin, scCustomer->strName);

    cout << "Please enter the customer's street address: ";
    cin.clear();
    cin.ignore();
    getline(cin, scCustomer->strAddress);

    cout << "Please enter the customer's city: ";
    cin.clear();
    cin.ignore();
    getline(cin, scCustomer->strCity);
    
    cout << "Please enter the customer's state: ";
    cin.clear();
    cin.ignore();
    getline(cin, scCustomer->strState);
    while(scCustomer->strState.length() != 2 || *validateState(&scCustomer->strState) == false)
    {
        cout << "Please enter a valid 2 letter abbreviation: ";
//        cin.clear();
//        cin.ignore();
        getline(cin, scCustomer->strState);
    }
    
    cout << "Please enter the customer's zip code: ";
    cin.clear();
    cin.ignore();
    getline(cin, scCustomer->strZipcode);
    while(scCustomer->strZipcode.length() != 5 || *validateZipcode(&scCustomer->strZipcode) == false)
    {
        cout << "Please a valid zip code: ";
//        cin.clear();
//        cin.ignore();
        getline(cin, scCustomer->strZipcode);
    }
    
    cout << "Please enter the customer's phone number: ";
    cin.clear();
    cin.ignore();
    getline(cin, scCustomer->strTelephoneNumber);
    while(scCustomer->strTelephoneNumber.length() != 12 || *validatePhoneNumber(&scCustomer->strTelephoneNumber) == false)
    {
        cout << "Please enter a valid telephone number: ";
//        cin.clear();
//        cin.ignore();
        getline(cin, scCustomer->strTelephoneNumber);
    }
    
    cout << "Please enter the user's account balance: $";
    cin.clear();
    cin.ignore();
    cin >> scCustomer->dblAccountBalance;
    while(!cin || scCustomer->dblAccountBalance < 0)
    {
        cout << "Please enter a positive value: $";
        cin.clear();
        cin.ignore();
        cin >> scCustomer->dblAccountBalance;
    }
    
    cout << "Enter the month of the customer's last payment: ";
    cin.clear();
    cin.ignore();
    cin >> scCustomer->intLastPaymentMonth;
    while(!cin || scCustomer->intLastPaymentMonth < 1 || scCustomer->intLastPaymentMonth > 12)
    {
        cout << "Please enter an integer value between 1 and 12: ";
        cin.clear();
        cin.ignore();
        cin >> scCustomer->intLastPaymentMonth;
    }
    
    cout << "Enter the day of the customer's last payment: ";
    cin.clear();
    cin.ignore();
    cin >> scCustomer->intLastPaymentDay;
    while(!cin || scCustomer->intLastPaymentDay < 1 || scCustomer->intLastPaymentDay > 31)
    {
        cout << "Please enter an integer value between 1 and 31: ";
        cin.clear();
        cin.ignore();
        cin >> scCustomer->intLastPaymentDay;
    }
    
    cout << "Enter the year of the customer's last payment: ";
    cin.clear();
    cin.ignore();
    cin >> scCustomer->intLastPaymentYear;
    while(!cin || scCustomer->intLastPaymentYear < 1999 || scCustomer->intLastPaymentYear > 2017)
    {
        cout << "Please enter an integer value between 1999 and 2017: ";
        cin.clear();
        cin.ignore();
        cin >> scCustomer->intLastPaymentYear;
    }
    
    return scCustomer;
}

bool *validateState(string *strState)
{
    const int INT_US_ABBREV = 55;
    
    string strStates[INT_US_ABBREV] =
                { "AK",
                  "AL",
                  "AR",
                  "AS",
                  "AZ",
                  "CA",
                  "CO",
                  "CT",
                  "DC",
                  "DE",
                  "FL",
                  "GA",
                  "GU",
                  "HI",
                  "IA",
                  "ID",
                  "IL",
                  "IN",
                  "KS",
                  "KY",
                  "LA",
                  "MA",
                  "MD",
                  "ME",
                  "MI",
                  "MN",
                  "MO",
                  "MS",
                  "MT",
                  "NC",
                  "ND",
                  "NE",
                  "NH",
                  "NJ",
                  "NM",
                  "NV",
                  "NY",
                  "OH",
                  "OK",
                  "OR",
                  "PA",
                  "PR",
                  "RI",
                  "SC",
                  "SD",
                  "TN",
                  "TX",
                  "UT",
                  "VA",
                  "VI",
                  "VT",
                  "WA",
                  "WI",
                  "WV",
                  "WY"};
    
    bool *isValid = nullptr;
    isValid = new bool;
    *isValid = false;
    
    char *chrArr = nullptr;
    chrArr = new char[2];
    
    cout << *strState << endl;
    
    strcpy(chrArr, strState->c_str());
    
    for (int i = 0 ; i < 2 ; i++)
    {
        chrArr[i] = toupper(chrArr[i]);
    }
    
    strState->clear();
    strState->append(chrArr);
    
    for (int i = 0 ; i < INT_US_ABBREV ; i++)
    {
        if (*strState == strStates[i])
        {
            *isValid = true;
            break;
        }
    }
    
    cout << *isValid << endl;
    
    return isValid;
}

bool *validateZipcode(string *strZipcode)
{
    bool *isValid = nullptr;
    isValid = new bool;
    *isValid = false;
    
    char *chrArr = nullptr;
    chrArr = new char[5];
    
    strcpy(chrArr, strZipcode->c_str());
    
    for(int i = 0 ; i < 5 ; i++)
    {
        if (isdigit(chrArr[i]) == false)
        {
            *isValid = false;
            break;
        }
        else if (isdigit(chrArr[i]) == true)
        {
            *isValid = true;
        }
    }
    
    return isValid;
}

bool *validatePhoneNumber(string *strPhone)
{
    bool *isValid = nullptr;
    isValid = new bool;
    *isValid = false;
    
    char *chrArr = nullptr;
    chrArr = new char[10];
    
    strcpy(chrArr, strPhone->c_str());
    
    for (int i = 0 ; i < 12 ; i++)
    {
        if (i == 3 || i == 7)
        {
            if (chrArr[i] == '-')
            {
                *isValid = true;
            }
            else if (chrArr[i] != '-')
            {
                *isValid = false;
                break;
            }
        }
        else if (i != 3 || i != 7)
        {
            if (isdigit(chrArr[i]) == false)
            {
                *isValid = false;
                break;
            }
            else if (isdigit(chrArr[i]) == true)
            {
                *isValid = true;
            }
        }
    }
    
    return isValid;
}

void displayCustomerInfo(StructCustomer *scCustomer, int *intNumber)
{
    cout << fixed << showpoint << setprecision(2);
    
    cout << "\nInformation for customer #" << *intNumber << ":\n\n";
    cout << "\tName: " << scCustomer->strName << endl;
    cout << "\tAddress: " << scCustomer->strAddress << endl;
    cout << "\t\t\t" << scCustomer->strCity << ", " << scCustomer->strState << scCustomer->strZipcode << endl;
    cout << "\tTelephone Number: (" << scCustomer->strTelephoneNumber.substr(0, 3) << endl;
    cout << "\tAccount balance: $" << scCustomer->dblAccountBalance << endl;
    cout << "\tDate of last payment: " << scCustomer->intLastPaymentMonth << "/";
    cout << scCustomer->intLastPaymentDay << "/" << scCustomer->intLastPaymentYear << endl;
}
