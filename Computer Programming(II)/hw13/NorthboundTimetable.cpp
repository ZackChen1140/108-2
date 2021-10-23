// NorthboundTimetable.cpp
// Member-function definitions for class NorthboundTimetable.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "NorthboundTimetable.h"

extern string departureTimes[ 37 ];

// NorthboundTimetable default constructor
// loads northbound timetable from the file "Northbound timetable.dat"
NorthboundTimetable::NorthboundTimetable()
{
   loadNorthboundTimetable();
}

void NorthboundTimetable::loadNorthboundTimetable()
{
    ifstream inFile("Northbound timetable.dat", ios::binary);
    if (!inFile)
    {
        cout << "File count not be find\n";
        exit(0);
    }
    Train in;
    while (inFile.read((char*)(&in), sizeof(Train)))
        northboundTimetable.push_back(in);
    inFile.close();
}

// returns departureTimes[ station ]
string NorthboundTimetable::getDepartureTimes( string trainNumber, int station )
{
   vector< Train >::iterator it = searchTrain( trainNumber );
   return it->getDepartureTimes( station );
}

bool NorthboundTimetable::trainsAvailable( int departureTime,
     int originStation, int destinationStation )
{
    for (int i = 0; i < northboundTimetable.size(); ++i)
        if (northboundTimetable[i].getDepartureTimes(originStation) != "-" && northboundTimetable[i].getDepartureTimes(originStation) >= departureTimes[departureTime])
            if (northboundTimetable[i].getDepartureTimes(destinationStation) != "-")
                return true;
    return false;
}

void NorthboundTimetable::displayComingTrains( int departureTime,
     int originStation, int destinationStation )
{
    int count = 0;
    cout << "Train No.  Departure  Arrival\n";
    for (int i = 0; i < northboundTimetable.size(); ++i)
        if (northboundTimetable[i].getDepartureTimes(originStation) != "-" && northboundTimetable[i].getDepartureTimes(originStation) >= departureTimes[departureTime])
            if (northboundTimetable[i].getDepartureTimes(destinationStation) != "-")
            {
                cout << setw(9) << northboundTimetable[i].getTrainNumber() << "      "
                    << northboundTimetable[i].getDepartureTimes(originStation) << "    "
                    << northboundTimetable[i].getDepartureTimes(destinationStation) << endl;
                ++count;
                if (count == 10)
                    break;
            }
    
}

vector< Train >::iterator NorthboundTimetable::searchTrain( string trainNumber )
{
   vector< Train >::iterator it = northboundTimetable.begin();
   for( ; it != northboundTimetable.end(); ++it )
      if( it->getTrainNumber() == trainNumber )
         return it;

   return northboundTimetable.end();
}