#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Booking.h"
using namespace std;


struct TrainII
{
	char trainNumber[8];
	char departureTime[8];
	char arrivalTime[8];
};

Booking A;

bool re_enter()
{
	int c;
	cout << "1. Enter again\n2. End\n? ";
	cin >> c; cout << endl;
	if (c == 2)
		return false;
	else if (c == 1)
		return true;
	cout << "The choice is not exist\nPlease enter again.\n\n";
	re_enter();
}

void BookingMenu()
{
	int choiceOS;
	int choiceDS;
	int choiceCC;
	int choiceDT;
	TrainII choiceTrip;
	string departureDate;
	int AdultTicketsAmount;
	int concessionTicketsAmount;
	string trainNumber;
	string idNumber;
	string phoneNumber;
	while (true)
	{
		cout << "Origin Station\n";
		for (int i = 1; i < 13; ++i)
			cout << i << ". " << location[i] << endl;
		cout << "? ";
		cin >> choiceOS;
		cout << endl;
		if (choiceOS < 1 || choiceOS>12)
			cout << "The choice is not exist\nPlease reselect.\n\n";
		else
			break;
	}
	while (true)
	{
		cout << "Destination  Station\n";
		for (int i = 1; i < 13; ++i)
			cout << i << ". " << location[i] << endl;
		cout << "? ";
		cin >> choiceDS;
		cout << endl;
		if (choiceDS < 1 || choiceDS>12)
			cout << "The choice is not exist\nPlease reselect.\n\n";
		else if (choiceDS == choiceOS)
			cout << "The choices can't be the same.\nPlease reselect.\n\n";
		else
			break;
	}
	while (true)
	{
		cout << "Car Class\n1. Standard Car\n2. Business Car\n? ";
		cin >> choiceCC;
		cout << endl;
		if (choiceCC < 1 || choiceCC>2)
			cout << "The choice is not exist\nPlease reselect.\n\n";
		else
			break;
	}
	while (true)
	{
		cout << "Departure Date: ";
		cin >> departureDate;
		cout << endl;
		if (departureDate.length() > 4 || departureDate.length() < 3)
			cout << "The date is not exist\nPlease enter again.\n\n";
		else
			break;
	}
	
	while (true)
	{
		cout << "Departure Time" << endl;
		for (int i = 1; i < 37; ++i)
		{
			if (i < 10)
				cout << " " << i << ". ";
			else
				cout << i << ". ";
			cout << departureTimes[i] << endl;
		}
		cout << "? ";
		cin >> choiceDT;
		cout << endl;
		if (choiceCC < 1 || choiceCC>36)
			cout << "The choice is not exist\nPlease reselect.\n\n";
		else
			break;
	}
	while (true)
	{
		cout << "How many adult tickets? ";
		cin >> AdultTicketsAmount;
		if (AdultTicketsAmount > 10)
			cout << "You can only book up to ten tickets.\nPlease enter again.\n\n";
		else
			break;
	}
	while (true)
	{
		cout << "\nHow many concession tickets? ";
		cin >> concessionTicketsAmount;
		cout << endl;
		if (concessionTicketsAmount > 10)
			cout << "You can only book up to ten tickets.\nPlease enter again.\n\n";
		else
			break;
	}
	
	while (true)
	{
		int S_or_N;
		if (choiceOS - choiceDS < 0)
			S_or_N = 1;
		else
			S_or_N = 0;
		vector<TrainII> R;
		if(R.size()==0)
			for (int i = 0; i < A.get_vecTrainSize(S_or_N); ++i)
			{
				int a = choiceOS;
				int b = choiceDS;
				if (S_or_N == 0)
				{
					choiceOS = 13 - choiceOS;
					choiceDS = 13 - choiceDS;
				}
				
				int t = 0;
				if ((A.get_train(S_or_N, i).departureTimes[choiceOS][0] >= '0' && A.get_train(S_or_N, i).departureTimes[choiceOS][0] <= '2')&& (A.get_train(S_or_N, i).departureTimes[choiceDS][0] >= '0' && A.get_train(S_or_N, i).departureTimes[choiceDS][0] <= '2'))
				{
					if (A.get_train(S_or_N, i).departureTimes[choiceOS][0] > departureTimes[choiceDT][0])
						t = 1;
					else if (A.get_train(S_or_N, i).departureTimes[choiceOS][0] == departureTimes[choiceDT][0])
					{
						if (A.get_train(S_or_N, i).departureTimes[choiceOS][1] > departureTimes[choiceDT][1])
							t = 1;
						else if (A.get_train(S_or_N, i).departureTimes[choiceOS][1] == departureTimes[choiceDT][1])
						{
							if (A.get_train(S_or_N, i).departureTimes[choiceOS][3] > departureTimes[choiceDT][3])
								t = 1;
							else if (A.get_train(S_or_N, i).departureTimes[choiceOS][3] == departureTimes[choiceDT][3])
								if (A.get_train(S_or_N, i).departureTimes[choiceOS][4] >= departureTimes[choiceDT][4])
									t = 1;
						}
					}
				}
				int tII = 0;
				TrainII M;
				if (t)
				{
					for (int j = 0; j < 8; ++j)
					{
						M.trainNumber[j] = A.get_train(S_or_N, i).trainNumber[j];
						M.departureTime[j] = A.get_train(S_or_N, i).departureTimes[choiceOS][j];
						M.arrivalTime[j] = A.get_train(S_or_N, i).departureTimes[choiceDS][j];
					}
				}
				while (t)
				{
					if (R.size() == 0)
					{
						R.push_back(M); t = 0;
					}
					else
					{
						if (tII == R.size())
						{
							R.push_back(M); t = 0;
						}
						else if (A.get_train(S_or_N, i).departureTimes[choiceOS][0] < R[tII].departureTime[0])
						{
							/*R.insert(R.begin() + tII, M);*/R.push_back(M); t = 0;
						}
						else if (A.get_train(S_or_N, i).departureTimes[choiceOS][0] == R[tII].departureTime[0])
						{
							if (A.get_train(S_or_N, i).departureTimes[choiceOS][1] < R[tII].departureTime[1])
							{
								/*R.insert(R.begin() + tII, M);*/R.push_back(M); t = 0;
							}
							else if (A.get_train(S_or_N, i).departureTimes[choiceOS][1] == R[tII].departureTime[1])
							{
								if (A.get_train(S_or_N, i).departureTimes[choiceOS][3] < R[tII].departureTime[3])
								{
									/*R.insert(R.begin() + tII, M);*/R.push_back(M); t = 0;
								}
								else if (A.get_train(S_or_N, i).departureTimes[choiceOS][3] == R[tII].departureTime[3])
								{
									if (A.get_train(S_or_N, i).departureTimes[choiceOS][4] < R[tII].departureTime[4])
									{
										/*R.insert(R.begin() + tII, M);*/R.push_back(M); t = 0;
									}
								}
							}
						}
						++tII;
					}
					
				}
				if (S_or_N == 0)
				{
					choiceOS = a;
					choiceDS = b;
				}
			}
		while (R.size() > 10)
			R.pop_back();
		if (R.size() != 0)
		{
			cout << "Train No.  Departure  Arrival\n";
			for (int i = 0; i < R.size(); ++i)
			{
				if (R[i].trainNumber[3] == NULL)
					cout << "      " << R[i].trainNumber << "      " << R[i].departureTime << "    " << R[i].arrivalTime << endl;
				else
					cout << "     " << R[i].trainNumber << "      " << R[i].departureTime << "    " << R[i].arrivalTime << endl;
			}

			cout << "\nEnter Train Number: ";
			cin >> trainNumber;
			cout << endl;
			int v = 0;
			for (int i = 0; i < R.size(); ++i)
				if (R[i].trainNumber == trainNumber)
				{
					choiceTrip = R[i];
					v = 1;
				}
			if (v)
				break;
			else
				cout << "The train number is not exist\nPlease enter again.\n\n";
		}
		else
		{
			cout << "No results.Please reselect.\n\n";
			BookingMenu();
		}
	}
	cout << "Trip Details\n\n      Date  Train No.     From        To  Departure  Arrival   Adult  Concession  Fare     Class\n";
	if (departureDate.length() == 3)
		cout << "       " << departureDate;
	else
		cout << "      " << departureDate;

	if (trainNumber.length() == 3)
		cout << "        " << trainNumber;
	else
		cout << "       " << trainNumber;

	if (choiceOS == 7 || choiceOS == 8)
		cout << " " << location[choiceOS];
	else if (choiceOS == 1 || choiceOS == 3 || choiceOS == 4 || choiceOS == 5 || choiceOS == 12)
		cout << "  " << location[choiceOS];
	else
		cout << "   " << location[choiceOS];

	if (choiceOS == 7 || choiceOS == 8)
		cout << "  " << location[choiceOS];
	else if (choiceOS == 1 || choiceOS == 3 || choiceOS == 4 || choiceOS == 5 || choiceOS == 12)
		cout << "   " << location[choiceOS];
	else
		cout << "    " << location[choiceOS];
	
	cout << "      " << choiceTrip.departureTime << "    " << choiceTrip.arrivalTime;

	int thePrice = adultTicketPrice[choiceDS][choiceOS];
	if (choiceCC == 2)
		thePrice = adultTicketPrice[choiceOS][choiceDS];
	if (thePrice >= 1000)
		cout << "  ";
	else if (thePrice < 100)
		cout << "    ";
	else
		cout << "   ";
	cout << thePrice << "*" << AdultTicketsAmount;

	if (thePrice /2 >= 1000)
		cout << "      ";
	else if (thePrice /2 < 100)
		cout << "        ";
	else
		cout << "       ";
	cout << thePrice /2 << "*" << concessionTicketsAmount;

	int fare = thePrice * AdultTicketsAmount + thePrice / 2 * concessionTicketsAmount;
	if (fare < 100)
		cout << "    ";
	else if (fare < 1000)
		cout << "   ";
	else if (fare < 10000)
		cout << "  ";
	else
		cout << " ";
	cout << fare;

	if (choiceCC == 1)
		cout << "  Standard\n\n";
	else
		cout << "  Business\n\n";

	cout << "Enter Contact Person Information\n\nID Number: ";
	cin >> idNumber;
	cout << "\nPhone: ";
	cin >> phoneNumber;
	cout << "\nReservation Number: ";
	
	srand(time(NULL));
	int min = 10000000;
	int max = 99999999;
	int RN = rand() % (max - min + 1) + min;
	
	cout << RN << "\n\n";
	A.save_reservation(RN, trainNumber, idNumber, phoneNumber, departureDate, choiceOS, choiceDS, choiceCC, AdultTicketsAmount, concessionTicketsAmount,choiceTrip.departureTime,choiceTrip.arrivalTime);
	cout << "Reservation Completed!\n\n\n";

}

void BookingHistoryMenu()
{
	Booking B;
	string idNumberH;
	vector<Reservation> reservationH;
	string reservationNumberH;
	int reservationS;
	int choice;
	while (true)
	{
		cout << "Enter ID Number: ";
		cin >> idNumberH;
		cout << endl;
		bool idcheck = 0;
		for (int i = 0; i < A.get_vecReservationSize(); ++i)
		{
			
			for (int j = 0; j < idNumberH.length(); ++j)
			{
				if (idNumberH[j] == A.get_reservation(i).idNumber[j])
				{
					reservationH.push_back(A.get_reservation(i));
					idcheck = 1;
				}
			}
			if (idcheck)
				if (A.get_reservation(i).idNumber[idNumberH.length()] != NULL)
					idcheck = 0;
		}
		if (!idcheck)
			cout << "The ID Number is not exist\nPlease enter again.\n\n";
		else
			break;
	}
	while (true)
	{
		cout << "Enter Reservation Number: ";
		cin >> reservationNumberH; cout << endl;
		bool RN_Check = 0;
		Reservation reservationHT;
		for (int i = 0; i < reservationH.size(); ++i)
		{
			if (reservationNumberH == reservationH[i].reservationNumber)
			{
				reservationHT = reservationH[i];
				reservationS = i;
				RN_Check = 1;
				break;
			}
		}
		if (RN_Check)
		{
			cout << "Reservation Details\n\n";
			cout << "      Date  Train No.     From        To  Departure  Arrival   Adult  Concession  Fare     Class\n";
			if (reservationHT.date[3] == NULL)
				cout << "       ";
			else
				cout << "      ";
			cout << reservationHT.date;

			if (reservationHT.trainNumber[3] == NULL)
				cout << "        ";
			else
				cout << "       ";
			cout << reservationHT.trainNumber;

			if (reservationHT.originStation == 7 || reservationHT.originStation == 8)
				cout << " " << location[reservationHT.originStation];
			else if (reservationHT.originStation == 1 || reservationHT.originStation == 3 || reservationHT.originStation == 4 || reservationHT.originStation == 5 || reservationHT.originStation == 12)
				cout << "  " << location[reservationHT.originStation];
			else
				cout << "   " << location[reservationHT.originStation];

			if (reservationHT.destinationStation == 7 || reservationHT.destinationStation == 8)
				cout << "  " << location[reservationHT.destinationStation];
			else if (reservationHT.destinationStation == 1 || reservationHT.destinationStation == 3 || reservationHT.destinationStation == 4 || reservationHT.destinationStation == 5 || reservationHT.destinationStation == 12)
				cout << "   " << location[reservationHT.destinationStation];
			else
				cout << "    " << location[reservationHT.destinationStation];

			cout << "      " << reservationHT.departureTime << "    " << reservationHT.arrivalTime;

			int thePrice = adultTicketPrice[reservationHT.destinationStation][reservationHT.originStation];
			if (reservationHT.carClass == 2)
				thePrice = adultTicketPrice[reservationHT.originStation][reservationHT.destinationStation];

			if (thePrice >= 1000)
				cout << "  ";
			else if (thePrice >= 100)
				cout << "   ";
			else
				cout << "    ";
			cout << thePrice << "*" << reservationHT.adultTickets;

			if (thePrice/2 >= 1000)
				cout << "      ";
			else if (thePrice/2 >= 100)
				cout << "       ";
			else
				cout << "        ";
			cout << thePrice/2 << "*" << reservationHT.concessionTickets;

			int fare = thePrice * reservationHT.adultTickets + thePrice / 2 * reservationHT.concessionTickets;
			if (fare >= 10000)
				cout << " ";
			else if (fare >= 1000)
				cout << "  ";
			else if (fare >= 100)
				cout << "   ";
			cout << fare;

			if (reservationHT.carClass == 1)
				cout << "  Standard\n\n";
			else
				cout << "  Business\n\n";
			break;
		}
		else
			cout << "The Reservation Number is not exist\nPlease enter again.\n\n";
	}
	while (true)
	{
		cout << "Enter Your Choice\n1. Cancellation\n2. Reduce\n3. End\n? ";
		cin >> choice; cout << endl;
		if (choice == 1)
		{
			A.delete_reservation(reservationS);
			cout << "Reservation Cancelled.\n\n\n";
			break;
		}
		else if (choice == 2)
		{
			int c = 1;
			if(A.get_reservation(reservationS).adultTickets>0)
				while (true)
				{
					cout << "How many adult tickets to cancel¡H";
					int adultTicketsCancel;
					cin >> adultTicketsCancel;
					if (A.get_reservation(reservationS).adultTickets < adultTicketsCancel)
					{
						cout << "The tickets you booked is less than this amount.\n\n";
						c = re_enter();
						if (!c)
							break;
					}
					else
					{
						A.reduceAdultTicketNumber(reservationS, adultTicketsCancel);
						break;
					}
				}
			if (!c)
				break;
			if (A.get_reservation(reservationS).concessionTickets > 0)
				while (true)
				{
					cout << "How many concession tickets to cancel¡H";
					int concessionTicketsCancel;
					cin >> concessionTicketsCancel;
					cout << endl;
					if (A.get_reservation(reservationS).concessionTickets < concessionTicketsCancel)
					{
						cout << "The tickets you booked is less than this amount.\n\n";
						c = re_enter();
						if (!c)
							break;
					}
					else
					{
						A.reduceConcessionTicketNumber(reservationS, concessionTicketsCancel);
						break;
					}
				}
			if (!c)
				break;
			if (A.get_reservation(reservationS).adultTickets == 0 && A.get_reservation(reservationS).concessionTickets == 0)
				A.delete_reservation(reservationS);
			else
			{
				Reservation reservationHT = A.get_reservation(reservationS);
				cout << "      Date  Train No.     From        To  Departure  Arrival   Adult  Concession  Fare     Class\n";

				if (strlen(reservationHT.date) == 3)
					cout << "       ";
				else
					cout << "      ";
				cout << reservationHT.date;

				if (reservationHT.trainNumber[3] == NULL)
					cout << "        ";
				else
					cout << "       ";
				cout << reservationHT.trainNumber;

				if (reservationHT.originStation == 7 || reservationHT.originStation == 8)
					cout << " " << location[reservationHT.originStation];
				else if (reservationHT.originStation == 1 || reservationHT.originStation == 3 || reservationHT.originStation == 4 || reservationHT.originStation == 5 || reservationHT.originStation == 12)
					cout << "  " << location[reservationHT.originStation];
				else
					cout << "   " << location[reservationHT.originStation];

				if (reservationHT.destinationStation == 7 || reservationHT.destinationStation == 8)
					cout << "  " << location[reservationHT.destinationStation];
				else if (reservationHT.destinationStation == 1 || reservationHT.destinationStation == 3 || reservationHT.destinationStation == 4 || reservationHT.destinationStation == 5 || reservationHT.destinationStation == 12)
					cout << "   " << location[reservationHT.destinationStation];
				else
					cout << "    " << location[reservationHT.destinationStation];
				
				cout << "      " << reservationHT.departureTime << "    " << reservationHT.arrivalTime;

				int thePrice = adultTicketPrice[reservationHT.destinationStation][reservationHT.originStation];
				if (reservationHT.carClass == 2)
					thePrice = adultTicketPrice[reservationHT.originStation][reservationHT.destinationStation];

				if (thePrice >= 1000)
					cout << "  ";
				else if (thePrice >= 100)
					cout << "   ";
				else
					cout << "    ";
				cout << thePrice << "*" << reservationHT.adultTickets;

				if (thePrice / 2 >= 1000)
					cout << "      ";
				else if (thePrice / 2 >= 100)
					cout << "       ";
				else
					cout << "        ";
				cout << thePrice / 2 << "*" << reservationHT.concessionTickets;

				int fare = thePrice * reservationHT.adultTickets + thePrice / 2 * reservationHT.concessionTickets;
				if (fare >= 10000)
					cout << " ";
				else if (fare >= 1000)
					cout << "  ";
				else if (fare >= 100)
					cout << "   ";
				cout << fare;

				if (reservationHT.carClass == 1)
					cout << "  Standard\n\n";
				else
					cout << "  Business\n\n";
			}

			cout << "You have successfully reduced the number of tickets!\n\n\n";
			break;
		}
		else if (choice == 3)
			break;
			
	}
}

int main()
{
	while (true)
	{
		cout << "Taiwan High Speed Rail Booking System\n\n";
		bool v = 0;
		while (true)
		{
			int choice;
			cout << "Enter Your Choice\n1. Booking\n2. Booking History\n3. End Program\n? ";
			cin >> choice;
			cout << endl;
			switch (choice)
			{
			case 1:
				BookingMenu();
				break;
			case 2:
				BookingHistoryMenu();
				break;
			case 3:
				v = 1;
				break;
			default:
				break;
			}
			if (v)
				break;
		}
		if (v)
			break;
	}

}