#include "General.h"

extern vector<Common> timezoneList;
extern vector<Common> languageList;

General::General()
{
	m_timeZone = "(GMT+07:00)";
	m_language = "Vietnamese";
}

General::~General() {}

string General::getLanguage() {
	return m_language;
}

string General::getTimeZone() {
	return m_timeZone;
}

void General::setTimeZone(string data) {
	m_timeZone = data;
}

void General::setLanguage(string data) {
	m_language = data;
}

void General::showInfomations() {
	cout << setw(20) << m_timeZone
		<< setw(20) << m_language;
}

void General::inputInfomations()
{
	string line;
	int selection = 0;
	
	cout << "*** Choose A Timezone below:\n";
	// in ra thong tin trong list timezone
	for (unsigned int i = 0; i < timezoneList.size(); i++) {
		cout << i + 1 << ". ";
		cout << timezoneList[i].getNumber() << " / " << timezoneList[i].getName() << endl;
	}

	do {
		selection = inputNumbers("Your Selection:   "); // goi ham inputNumbers de valiudata du lieu nhap vao
	} while (selection < 1 || selection > 32);

	m_timeZone = timezoneList[selection - 1].getNumber(); // cai dat timezone tu list timezone

	cout << "*** Choose A Language below:\n";
	// in ra thong tin trong list timezone
	for (unsigned int i = 0; i < languageList.size(); i++) {
		cout << languageList[i].getNumber() << " / " << languageList[i].getName() << endl;
	}

	do {
		selection = inputNumbers("Your selection:   "); // goi ham inputNumbers de valiudata du lieu nhap vao
	} while (selection < 1 || selection > 30);

	m_language = languageList[selection - 1].getName(); // cai dat language tu list language
}









