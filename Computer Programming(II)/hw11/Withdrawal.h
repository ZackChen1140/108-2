// Withdrawal.h
// Withdrawal class definition. Represents a withdrawal transaction.
#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include <vector> // class uses vector to store Account objects
using namespace std;
#include "Account.h" // Account class definition

class Withdrawal
{
public:
   Withdrawal( int userAccountNumber, vector< Account > &atmAccounts, int &atmRemainingBills );
   void execute(); // perform the withdrawal transaction
private:
   int accountNumber; // indicates account involved
   vector< Account > &accounts; // reference to the vector of the bank's Accounts
   int amount; // amount to withdraw
   int &remainingBills; // number of $20 bills remaining 

   // get pointer to Account object in "accounts" whose account number is equal to "accountNumber"
   Account * getAccount( int accountNumber, vector< Account > &accounts );

   // display a menu of withdrawal amounts and the option to cancel;
   // return the chosen amount or 0 if the user chooses to cancel
   int displayMenuOfAmounts() const;
}; // end class Withdrawal

Withdrawal::Withdrawal(int userAccountNumber, vector< Account >& atmAccounts, int& atmRemainingBills)
    :accountNumber(userAccountNumber),
    accounts(atmAccounts),
    remainingBills(atmRemainingBills)
{
}

void Withdrawal::execute()
{
	if (!(amount = displayMenuOfAmounts()))
		return;
	auto user = getAccount(accountNumber, accounts);
	if (amount > user->getAvailableBalance())
	{
		cout << "Insufficient balance." << endl << endl;
		Withdrawal::displayMenuOfAmounts();
	}
	else
		user->debit(amount);
}

Account* Withdrawal::getAccount(int accountNumber, vector< Account >& accounts)
{
    for (unsigned int i = 0; i < accountNumber; ++i)
        if (accounts[i].getAccountNumber() == accountNumber)
            return &accounts[i];
    return NULL;
}

int Withdrawal::displayMenuOfAmounts() const
{
	cout << "Withdrawal options:" << endl
		<< "1 - $20" << endl
		<< "2 - $40" << endl
		<< "3 - $60" << endl
		<< "4 - $100" << endl
		<< "5 - $200" << endl
		<< "6 - Cancel transaction" << endl << endl
		<< "Choose a withdrawal option (1-6): ";
	int choiceII;
	cin >> choiceII;
	cout << endl;
	if (choiceII == 1)
		return 20;
	else if (choiceII == 2)
		return 40;
	else if (choiceII == 3)
		return 60;
	else if (choiceII == 4)
		return 100;
	else if (choiceII == 5)
		return 200;
	else if (choiceII == 6)
		return 0;
	else
		Withdrawal::displayMenuOfAmounts();
}
#endif // WITHDRAWAL_H