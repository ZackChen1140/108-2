#include <iostream>
#include <vector>
#include "ATM.h"
#include <iomanip>

using namespace std;

void main_menu()
{
	cout<< "Main menu:" << endl
		<< "1 - View my balance" << endl
		<< "2 - Withdraw cash" << endl
		<< "3 - Deposit funds" << endl
		<< "4 - Exit" << endl
		<< "Enter a choice: ";
}

int main()
{
	
	string inputAccount;
	string inputPIN;
	while (1)
	{

		vector< ATM > account(2);

		account[0].set_value("12345", "54321", 1000.0, 1200.0);
		account[1].set_value("98765", "56789", 200.0, 200.0);

		cout << "Welcome!" << endl << endl << "Please enter your account number: ";
		cin >> inputAccount;
		cout << endl << "Enter your PIN: ";
		cin >> inputPIN;
		cout  << endl;
		for (unsigned int i = 0; i < account.size(); ++i)
		{
			if (account[i].conform(inputAccount, inputPIN))
			{
				while (1)
				{
					int choice;
					main_menu();
					cin >> choice;
					cout << endl;
					if (choice == 4)
					{
						cout << "Exiting the system..." << endl << endl
							<< "Thank you! Goodbye!" << endl << endl;
						break;
					}
					else if (choice == 1)
						account[i].get_balance();
					else if (choice == 2)
					{
						while (1)
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
							{
								if (account[i].withdraw(20))
								{
									cout << "Please take your cash from the cash dispenser." << endl << endl;
									break;
								}
								else
									cout << "Insufficient balance." << endl << endl;
								
							}
							else if (choiceII == 2)
							{
								if (account[i].withdraw(40))
								{
									cout << "Please take your cash from the cash dispenser." << endl << endl;
									break;
								}
								else
									cout << "Insufficient balance." << endl << endl;
							}
							else if (choiceII == 3)
							{
								if (account[i].withdraw(60))
								{
									cout << "Please take your cash from the cash dispenser." << endl << endl;
									break;
								}
								else
									cout << "Insufficient balance." << endl << endl;
							}
							else if (choiceII == 4)
							{
								if (account[i].withdraw(100))
								{
									cout << "Please take your cash from the cash dispenser." << endl << endl;
									break;
								}
								else
									cout << "Insufficient balance." << endl << endl;
							}
							else if (choiceII == 5)
							{
								if (account[i].withdraw(200))
								{
									cout << "Please take your cash from the cash dispenser." << endl << endl;
									break;
								}
								else
									cout << "Insufficient balance." << endl << endl;
							}
							else if (choiceII == 6)
								break;
						}
					}
					else if (choice == 3)
					{
						cout << "Please enter a deposit amount in CENTS (or 0 to cancel): ";
						double deposit;
						cin >> deposit;
						deposit /= 100;
						cout << endl;
						cout << "Please insert a deposit envelope containing $" << fixed << setprecision(2) << deposit << " in the deposit slot."<<endl<<endl;
						account[i].deposit(deposit);
						cout << "Your envelope has been received." << endl
							<< "NOTE: The money deposited will not be available until we" << endl
							<< "verify the amount of any enclosed cash, and any enclosed checks clear." << endl << endl;
							
					}
				}
			}
		}

		
	}

}

