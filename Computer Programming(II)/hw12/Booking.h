#ifndef BOOKING_H
#define BOOKING_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

char location[14][11] = { "",
"Nangang","Taipei","Banqiao","Taoyuan","Hsinchu","Miaoli",
"Taichung","Changhua","Yunlin","Chiayi","Tainan","Zuoying"
};

int adultTicketPrice[13][13] = {
   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   0,    0,    0,    0,  500,  700,  920, 1330, 1510, 1660, 1880, 2290, 2500,
   0,   40,    0,    0,  440,  640,  850, 1250, 1430, 1600, 1820, 2230, 2440,
   0,   70,   40,    0,  400,  590,  800, 1210, 1390, 1550, 1780, 2180, 2390,
   0,  200,  160,  130,    0,  400,  620, 1010, 1210, 1370, 1580, 1990, 2200,
   0,  330,  290,  260,  130,    0,  410,  820, 1010, 1160, 1390, 1790, 2000,
   0,  480,  430,  400,  280,  140,    0,  610,  790,  950, 1160, 1580, 1790,
   0,  750,  700,  670,  540,  410,  270,    0,  400,  550,  770, 1180, 1390,
   0,  870,  820,  790,  670,  540,  390,  130,    0,  370,  580, 1000, 1210,
   0,  970,  930,  900,  780,  640,  500,  230,  110,    0,  430,  830, 1040,
   0, 1120, 1080, 1050,  920,  790,  640,  380,  250,  150,    0,  620,  820,
   0, 1390, 1350, 1320, 1190, 1060,  920,  650,  530,  420,  280,    0,  410,
   0, 1530, 1490, 1460, 1330, 1200, 1060,  790,  670,  560,  410,  140,    0 };


char departureTimes[37][8] = { "",
   "06:00", "06:30", "07:00", "07:30", "08:00", "08:30", "09:00", "09:30",
   "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "13:00", "13:30",
   "14:00", "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30",
   "18:00", "18:30", "19:00", "19:30", "20:00", "20:30", "21:00", "21:30",
   "22:00", "22:30", "23:00", "23:30" };

struct Reservation
{
	char reservationNumber[12]; // used to identify a reservation  訂位代號
	char trainNumber[8]; // used to identify a train  車次號碼
	char idNumber[12]; // the id number of the contact person  取票人的身分證字號
	char phone[12]; // the (local or mobile) phone number of the contact person  取票人的聯絡電話
	char date[12]; // outbound date  搭乘日期
	int originStation; // the origin station code  起程站代碼
	int destinationStation; // the destination station code  到達站代碼
	int carClass; // the car class code; 1:standard car, 2:business car  車廂種類; 1:標準車廂, 2:商務車廂
	int adultTickets; // the number of adult tickets  全票張數
	int concessionTickets; // the number of concession tickets  優待票張數
	char departureTime[8];
	char arrivalTime[8];
};

struct Train
{
	char trainNumber[8]; // used to identify a train  車次號碼
	char departureTimes[13][8]; // the departure time of a train for each station  火車在各站的離站時間
};

class Booking
{
public:
	Booking();
	~Booking();
	void readN();
	void readS();
	void readR();
	void writeR();
	int get_vecTrainSize(int S_or_N);
	Train get_train(int S_or_N, int s);
	void save_reservation(int reservationNumberP, string trainNumberP,string idNumberP,string phoneP,string dateP,int originStationP,int destinationStationP,int carClassP, int adultTicketsP, int concessionTicketsP,string departureTimeP, string arrivalTimeP);
	void delete_reservation(int s);
	Reservation get_reservation(int s);
	int get_vecReservationSize();
	void reduceAdultTicketNumber(int s,int num);
	void reduceConcessionTicketNumber(int s, int num);
private:
	vector<Reservation> reservationP;
	vector<Train> N;
	vector<Train> S;
};

Booking::Booking()
{
	readN();
	readS();
	readR();
}

Booking::~Booking()
{
	writeR();
}

void Booking::readN()
{
	ifstream inFile("Northbound timetable.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be find\n";
		exit(0);
	}
	Train in;
	while (inFile.read((char*)(&in), sizeof(Train)))
		N.push_back(in);
	inFile.close();
}

void Booking::readS()
{
	ifstream inFile("Southbound timetable.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be find\n";
		exit(0);
	}
	Train in;
	while (inFile.read((char*)(&in), sizeof(Train)))
		S.push_back(in);
	inFile.close();
}

void Booking::readR()
{
	ifstream inFile("Reservation details.dat", ios::binary);
	if (!inFile)
	{
		ofstream outFile("Reservation details.dat", ios::binary);
	}
	else 
	{
		Reservation in;
		while (inFile.read((char*)(&in), sizeof(Reservation)))
			reservationP.push_back(in);
		inFile.close();
	}

}

void Booking::writeR()
{
	ofstream outFile("Reservation details.dat", ios::binary);
	if (!outFile)
	{
		cout << "File count not be find\n";
		exit(0);
	}
	for (size_t i = 0; i < reservationP.size(); ++i)
		outFile.write((char*)(&reservationP[i]), sizeof(Reservation));
	outFile.close();
}

int Booking::get_vecTrainSize(int S_or_N)
{
	if (S_or_N == 0)
		return N.size();
	else if (S_or_N == 1)
		return S.size();
}

Train Booking::get_train(int S_or_N, int s)
{
	if (S_or_N == 0)
		return N[s];
	else if (S_or_N == 1)
		return S[s];
}

void Booking::save_reservation(int reservationNumberP, string trainNumberP, string idNumberP, string phoneP, string dateP, int originStationP, int destinationStationP, int carClassP, int adultTicketsP, int concessionTicketsP, string departureTimeP, string arrivalTimeP)
{
	Reservation ticket;
	ticket.adultTickets = adultTicketsP;
	ticket.carClass = carClassP;
	ticket.concessionTickets = concessionTicketsP;
	for (int i = 0; i < dateP.length(); ++i)
		ticket.date[i] = dateP[i];
	for (int i = dateP.length(); i < 12; ++i)
		ticket.date[i] = NULL;
	ticket.destinationStation = destinationStationP;
	for(int i=0;i<idNumberP.length();++i)
		ticket.idNumber[i] = idNumberP[i];
	for (int i = idNumberP.length(); i < 12; ++i)
		ticket.idNumber[i] = NULL;
	ticket.originStation = originStationP;
	for(int i=0;i<phoneP.length();++i)
		ticket.phone[i] = phoneP[i];
	for (int i = phoneP.length(); i < 12; ++i)
		ticket.phone[i] = NULL;
	int reservationNumberPII = reservationNumberP;
	for (int i=7; i>=0; --i)
	{
		ticket.reservationNumber[i] = reservationNumberPII % 10 + '0';
		reservationNumberPII /= 10;
	}
	for (int i = 8; i < 12; ++i)
		ticket.reservationNumber[i] = NULL;

	for (int i = 0; i < trainNumberP.length(); ++i)
		ticket.trainNumber[i] = trainNumberP[i];
	for (int i = trainNumberP.length(); i < 8; ++i)
		ticket.trainNumber[i] = NULL;

	//strcpy_s(ticket.departureTime, departureTimeP[originStationP])
	for (int i = 0; i < departureTimeP.length(); ++i)
		ticket.departureTime[i] = departureTimeP[i];
	for(int i= departureTimeP.length();i<8;++i)
		ticket.departureTime[i] = NULL;

	for (int i = 0; i < arrivalTimeP.length(); ++i)
		ticket.arrivalTime[i] = arrivalTimeP[i];
	for (int i = arrivalTimeP.length(); i < 8; ++i)
		ticket.arrivalTime[i] = NULL;

	reservationP.push_back(ticket);
}

void Booking::delete_reservation(int s)
{
	reservationP.erase(reservationP.begin() + s);
}

Reservation Booking::get_reservation(int s)
{
	return reservationP[s];
}

int Booking::get_vecReservationSize()
{
	return reservationP.size();
}

void Booking::reduceAdultTicketNumber(int s, int num)
{
	reservationP[s].adultTickets -= num;
}

void Booking::reduceConcessionTicketNumber(int s, int num)
{
	reservationP[s].concessionTickets -= num;
}
#endif // 
