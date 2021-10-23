// Deposit.h
// Deposit class definition. Represents a deposit transaction.
#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <vector> // class uses vector to store Account objects
using namespace std;
#include "Account.h" // Account class definition

class Deposit
{
public:
   Deposit( int userAccountNumber, vector< Account > &atmAccounts );
   void execute(); // perform the deposit transaction
private:
   int accountNumber; // indicates account involved
   vector< Account > &accounts; // reference to the vector of the bank's Accounts
   double amount; // amount to deposit

   // get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
   Account * getAccount( int accountNumber, vector< Account > &accounts ); 
   double promptForDepositAmount() const; // prompt user to enter a deposit amount in cents 
}; // end class Deposit

Deposit::Deposit(int userAccountNumber, vector< Account >& atmAccounts)
:accountNumber(userAccountNumber),
accounts(atmAccounts)
{
}

void Deposit::execute()
{
    auto user = getAccount(accountNumber, accounts);
	cout << "Please enter a deposit amount in CENTS (or 0 to cancel): ";
	double deposit=promptForDepositAmount();
	cout << endl;
	cout << "Please insert a deposit envelope containing $" << fixed << setprecision(2) << deposit << " in the deposit slot." << endl << endl;
	user->credit(deposit);
	cout << "Your envelope has been received." << endl
		<< "NOTE: The money deposited will not be available until we" << endl
		<< "verify the amount of any enclosed cash, and any enclosed checks clear." << endl << endl;
}

Account* Deposit::getAccount(int accountNumber, vector< Account >& accounts)
{
    for (unsigned int i = 0; i < accountNumber; ++i)
        if (accounts[i].getAccountNumber() == accountNumber)
            return &accounts[i];
    return NULL;
}

double Deposit::promptForDepositAmount() const
{
    double deposit;
    cin >> deposit;
    deposit /= 100;
    return deposit;
}
#endif // DEPOSIT_H