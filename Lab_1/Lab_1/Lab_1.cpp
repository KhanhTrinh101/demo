//#include <iostream>
//#include <iomanip>
//#include <string>
//using namespace std;
//#include "CTime.h"
//
//int main(void)
//{
//	const int SECONDS_IN_A_DAY = 60 * 60 * 24;
//	long int seconds;
//	Time now, later;
//	cout << "Enter a number of seconds between 1 and " << SECONDS_IN_A_DAY - 1 << ": ";
//	cin >> seconds;
//	cout << setfill('0');
//	cout << "It is now " << now.get_hours() << ":" << setw(2) << now.get_minutes() << ":" << setw(2) << now.get_seconds() << ". ";
//
//	later = now;
//	later.add_seconds(seconds);
//
//	cout << "In " << seconds << " seconds, it will be ";
//	cout << later.get_hours() << ":" << setw(2) << later.get_minutes() << ":" << setw(2) << later.get_seconds() << "."
//		<< endl;
//
//	return 0;
//}