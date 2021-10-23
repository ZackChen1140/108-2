// MakingReservation.cpp
// Member-function definitions for class MakingReservation.
#include <iostream>
#include <iomanip>
#include "MakingReservation.h" // MakingReservation class definition

extern int inputAnInteger( int begin, int end );

extern string departureTimes[ 37 ];

// MakingReservation constructor
MakingReservation::MakingReservation( ReservationDatabase &theReservationDatabase,
                                      SouthboundTimetable &theSouthboundTimetable,
                                      NorthboundTimetable &theNorthboundTimetable )
   : reservationDatabase( theReservationDatabase ),
     southboundTimetable( theSouthboundTimetable ),
     northboundTimetable( theNorthboundTimetable )
{
}

void MakingReservation::execute()
{
   if( chooseTrain() ) // displays timetables for 10 coming trains, then let user choose a train
   {
      inputReservationDetails();

      inputContactPersonInfo();

      reservationDatabase.addReservation( reservation );

      cout << "\nReservation Completed!\n\n";
   }
   else
      cout << "\nSorry! No train is available!\n\n";
}

bool MakingReservation::chooseTrain()
{
    char location[14][11] = { "",
    "Nangang","Taipei","Banqiao","Taoyuan","Hsinchu","Miaoli",
    "Taichung","Changhua","Yunlin","Chiayi","Tainan","Zuoying"
    };

    cout << "Origin Station\n";
    for (int i = 1; i < 13; ++i)
        cout << i << ". " << location[i] << endl;
    int choiceOS;
    cout << "? ";
    while ((choiceOS = inputAnInteger(1, 12)) == -1)
        cout << "\n? ";
    cout << endl;
    reservation.setOriginStation(choiceOS);


    cout << "Destination  Station\n";
    for (int i = 1; i < 13; ++i)
        cout << i << ". " << location[i] << endl;
    int choiceDS;
    cout << "? ";
    while ((choiceDS = inputAnInteger(1, 12)) == -1)
        cout << "\n? ";
    cout << endl;
    reservation.setDestinationStation(choiceDS);

    cout << "Departure Time\n";
    for (int i = 1; i < 37; ++i)
        cout << setw(2) << i << ". " << departureTimes[i] << endl;
    int time;
    cout << "? ";
    while ((time = inputAnInteger(1, 36)) == -1)
        cout << "\n? ";
    cout << endl;

    string trainN;
    bool v = 0;

    if (reservation.getOriginStation() - reservation.getDestinationStation() > 0)
    {
        if (northboundTimetable.trainsAvailable(time, 13 - reservation.getOriginStation(), 13 - reservation.getDestinationStation()))
        {
            northboundTimetable.displayComingTrains(time, 13 - reservation.getOriginStation(), 13 - reservation.getDestinationStation());
            
            while (true)
            {
                
                cout << "\nEnter Train Number: ";
                getline(cin, trainN);
                if (northboundTimetable.getDepartureTimes(trainN, 13 - reservation.getOriginStation()) != "-" && northboundTimetable.getDepartureTimes(trainN, 13 - reservation.getOriginStation()) >= departureTimes[time]
                    && northboundTimetable.getDepartureTimes(trainN, 13 - reservation.getDestinationStation()) != "-")
                {
                    reservation.setTrainNumber(trainN);
                    v = 1;
                    break;
                }
            }
            
        }
    }
    else
    {
        if (southboundTimetable.trainsAvailable(time, reservation.getOriginStation(), reservation.getDestinationStation()))
        {
            southboundTimetable.displayComingTrains(time, reservation.getOriginStation(), reservation.getDestinationStation());
            while (true)
            {
                cout << "\nEnter Train Number: ";
                getline(cin, trainN);
                if (southboundTimetable.getDepartureTimes(trainN, reservation.getOriginStation()) != "-" && southboundTimetable.getDepartureTimes(trainN, reservation.getOriginStation()) >= departureTimes[time] 
                    && southboundTimetable.getDepartureTimes(trainN, reservation.getDestinationStation()) != "-")
                {
                    reservation.setTrainNumber(trainN);
                    v = 1;
                    break;
                }
            }
        }
    }

    if (v)
        return true;
    else
        return false;
}

void MakingReservation::inputReservationDetails()
{
   cout << "\nCar Class\n" << "1. Standard Car\n" << "2. Business Car";

   int carClass;
   do cout << "\n? ";
   while( ( carClass = inputAnInteger( 1, 2 ) ) == -1 );
   reservation.setCarClass( carClass );

    cout << "\nDeparture Date: ";

   char date[12];
   cin >> date;
   reservation.setDate( date );
   cin.ignore();

	cout << "\nHow many adult tickets? ";

   int adultTickets;
   cin >> adultTickets;
   reservation.setAdultTickets( adultTickets );

	cout << "\nHow many concession tickets? ";

   int concessionTickets;
   cin >> concessionTickets;
   reservation.setConcessionTickets( concessionTickets );

   cout << "\nTrip Details\n";
   reservation.displayReservationDetails();
}

void MakingReservation::inputContactPersonInfo()
{
   cout << "\nEnter Contact Person Information\n\n";

   cout << "ID Number: ";
   string idNumber;
   cin >> idNumber;
   reservation.setIdNumber( idNumber );

   cout << "\nPhone: ";
   string phone;
   cin >> phone;
   cin.ignore();
   reservation.setPhone( phone );

   srand( static_cast< unsigned int >( time( 0 ) ) );
   char reservationNumber[ 12 ];
   for( int i = 0; i < 8; i++ )
      reservationNumber[ i ] = rand() % 10 + '0';
   reservationNumber[ 8 ] = '\0';
   reservation.setReservationNumber( reservationNumber );
   
	cout << "\nReservation Number: " << reservationNumber << endl;
}