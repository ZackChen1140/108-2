#ifndef DEPARTURETIME_H
#define DEPARTURETIME_H

#include <string>

using namespace std;

class departureTime
{
public:
	departureTime();
	~departureTime();
	string get_departureTime(int s);
private:
	string hour[35];
	string minute[35];
};

departureTime::departureTime()
{
	char h = '6';
	for (size_t i = 0; i < 34; i+=2)
	{
		++h;
		if (h < '10')
		{
			hour[i] = "00";
			hour[i + 1] = "00";
			hour[i][1] = h;
			hour[i + 1][1] = h;
		}
		else
		{
			hour[i] = h;
			hour[i + 1] = h;
		}
		minute[i] = "00";
		minute[i + 1] = "30";
	}
}

departureTime::~departureTime()
{
}

string departureTime::get_departureTime(int s)
{
	--s;
	return hour[s] + ":" + minute[s];
}
#endif // !DEPARTURETIME_H

