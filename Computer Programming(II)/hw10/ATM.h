#ifndef ATM_H
#define ATM_H

#include <string>
#include <iomanip>
using namespace std;

class ATM
{
public:
	ATM();
	~ATM();
	void set_value(string accountP, string pinP, double availP, double totalP)
	{
		account = accountP;
		PIN = pinP;
		avail = availP;
		total = totalP;
	}
	bool conform(string inputAcc, string inputPIN)
	{
		return((account == inputAcc) && (PIN == inputPIN));
	}
	void get_balance()
	{
		cout << "Balance Information:" << endl
			<< " - Available balance: $"
			<< fixed << setprecision(2) << avail << endl
			<< " - Total balance:     $"
			<< fixed << setprecision(2) << total << endl << endl;
	}
	bool withdraw(double sub)
	{
		if (sub < avail)
		{
			avail -= sub;
			total -= sub;
			return true;
		}
		else
			return false;
	}
	void deposit(double inc)
	{
		total += inc;
	}
private:
	string account;
	string PIN;
	double avail;
	double total;
};

ATM::ATM()
	:account(),
	PIN(),
	avail(),
	total()
{
}

ATM::~ATM()
{
}


#endif // !1

