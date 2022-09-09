//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <fstream>
//using namespace std;
//#include "CTime.h"
//
//int main(void)
//{
//	const int SECONDS_IN_A_DAY = 60 * 60 * 24;
//	long int seconds;
//	Time now, later;
//
//	//=============== begin =============
//	ifstream _file;
//	// setup exception
//	_file.exceptions(ifstream::badbit | ifstream::failbit);
//
//	// try catch()
//	try {
//		// mo file
//		_file.open("testdata.txt");
//		//doc file
//		_file >> seconds;
//		// dong file
//		_file.close();
//	}
//	catch (ifstream::failure& ex) {
//		cout << ex.what() << endl;
//		cout << " something went wrong!" << endl;
//		return 1;
//	}
//
//
//	later = now;
//	later.add_seconds(seconds);
//
//
//	ofstream file;
//	// setup exception
//	file.exceptions(ifstream::badbit | ifstream::failbit);
//
//	// try catch()
//	try {
//		// mo file
//		file.open("result.txt");
//		//ghi file
//		file << setfill('0');
//		file << "It is now " << now.get_hours() << ":" << setw(2) << now.get_minutes() << ":" << setw(2) << now.get_seconds() << ". ";
//		file << "In " << seconds << " seconds, it will be ";
//		file << later.get_hours() << ":" << setw(2) << later.get_minutes() << ":" << setw(2) << later.get_seconds() << "."
//			<< endl;
//		// dong file
//		file.close();
//	}
//	catch (ifstream::failure& ex) {
//		cout << ex.what() << endl;
//		cout << " something went wrong!" << endl;
//		return 1;
//	}
//	//=============== end ============
//
//
//	return 0;
//}