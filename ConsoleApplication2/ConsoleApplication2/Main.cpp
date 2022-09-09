#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "Carsetting.h"
#include "valiuData.h"

using namespace std;

vector<CarSetting*> Listcar; // danh sach luu thong tin cac xe

vector<Common> timezoneList; // danh sach luu thong tin timezone
vector<Common> languageList; // danh sach luu thong tin languge

int countCnt = 0; // bien giam xac chi so cua xe hien tai

void InputInfomations(); // ghi thong tin: info user, display, sound, general.
void ShowInfomations(int, string); // in thong tin: in theo display, sound, general, all.
void ShowOptions(); // lua chon in theo ma so ca nhan, ten chu xe, in tat ca.

void ShowInfomations_Sound(int, string); // in thong tin sound: Media volume level, Call volume level, Navigation volume level, Notification volume level.
void ShowInfomations_General(int, string); // in thong tin general: timezone, language.
void ShowInfomations_Display(int, string); // in thong tin display: light level, screen light level, taplo light level.
void ShowInfomations_All(int, string); // in tat ca thong tin.

void downloadLanguage(string); // doc thong tin language tu file language.txt vao list language
void downloadTimeZone(string); // doc thong tin timezone tu file timezone.txt vao list timezone

void readFileData(string); // doc thong tin tu file data.txt vao listcar
void writeFileData(string); // ghi thong tin tu listcar vao file data.txt

void menu();

int main() {
	
	readFileData("data.txt"); // doc thong tin tu file setting.txt vao list car

	countCnt = Listcar.size(); // lay so luong xe tu list car
	downloadTimeZone("timezones.txt");
	downloadLanguage("languages.txt");
	
	menu(); // goi vao ham menu de thuc hien cac chuc nang cua chuong trinh
	
	writeFileData("data.txt"); // ghi thong tin vao file setting.txt tu list car

	return 0;
}

void menu() {
	
	int selection = 0; // menu lua chon nhap, xuat thong tin

	system("cls");
	cout << "--- MENU ---" << endl;
	cout << "1. Input Setting Information" << endl;
	cout << "2. Print Setting Information" << endl;
	cout << "3. Exit" << endl;

	do {
		selection = inputNumbers("Your Selection:	"); // dung ham inputNumbers de valiudata du lieu nhap vao
		if (selection >= 1 && selection <= 3) { // lua chon chi duoc nam trong khoang tu 1 den 3
			break;
		}
		else {
			cout << "Please Enter Only 1,2,3!" << endl; // in ra thong bao neu nhap sai
		}
	} while (true);
	
	switch (selection) {
	
	case 1: // neu chon 1 thi thuc hien nhap thong tin cai dat
		system("cls");
		InputInfomations();
		break;
	
	case 2: // neu chon 2 thi thuc hien xuat thong tin cai dat
		system("cls");
		ShowOptions();
		break;
	
	case 3: // neu lua chon 3 thi thoat khoi chuong trinh
		cout << "Good Bye" << endl;
		break;
	}
}

void InputInfomations() {
	string continues = "";

	do {
		system("cls");
		cout << " Input Infomation User And Car" << endl;
		cout << " Car Index " << countCnt + 1 << endl;
		CarSetting* newcar = new CarSetting(); // khoi tao xe moi

		cout << "*** Input User Information\n";
		newcar->inputInfomations(); // nhap thong tin user info cho xe

		int index = 0;
		bool checkPersonalKey = false;
		for (int i = 0; i < Listcar.size(); i++) {
			if (Listcar[i]->getPersonalKey() == newcar->getPersonalKey()) {
				index = i;
				checkPersonalKey = true;
				break;
			}
		}
		if (checkPersonalKey == true) {
			cout << "\n*** Car Already Exists, Information Will Be Overwritten \n";

			cout << "*** Input Display Information\n";
			newcar->getDisplay()->inputInfomations(); // nhap thong tin dislay cho xe
			cout << "*** Input Sound Information\n";
			newcar->getSound()->inputInfomations(); // nhap thong tin sound cho xe
			cout << "*** Input General Information\n";
			newcar->getGeneral()->inputInfomations(); // nhap thong tin general cho xe
			
			Listcar[index] = newcar;
		}
		else {
			cout << "\n*** New Car\n";

			cout << "*** Input Display Information\n";
			newcar->getDisplay()->inputInfomations(); // nhap thong tin dislay cho xe
			cout << "*** Input Sound Information\n";
			newcar->getSound()->inputInfomations(); // nhap thong tin sound cho xe
			cout << "*** Input General Information\n";
			newcar->getGeneral()->inputInfomations(); // nhap thong tin general cho xe

			Listcar.push_back(newcar);
			countCnt++;
		}

		// kiem tra xem nguoi dung co muon nhap tiep khong?
		do {
			cout << "Will You Input For Car " << countCnt + 1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "n") break;
		} while (true);
		cout << endl;

	} while (continues == "y");

	menu(); // goi lai ham menu
}

void ShowOptions() {
	int selection = 0;
	string personalkey = "";
	string userName = "";

	system("cls");
	cout << "--- SEARCH OPTIONS ---" << endl;
	cout << "1. Search By Personalkey" << endl;
	cout << "2. Search By User Name" << endl;
	cout << "3. Show All" << endl;
	cout << "4. Exit" << endl;
	do {
		selection = inputNumbers("Your Selection:	"); // goi ham inputNumbers de valiudata du lieu nhap vao 
		if (selection >= 1 && selection <= 4) { // lua chon chi duoc nam trong khoang tu 1 den 3
			break;
		}
		else {
			cout << "Please Enter Only 1,2,3!" << endl; // in ra thong bao neu nhap sai 
		}
	} while (true);

	switch (selection)
	{
		// tim theo personalkey
	case 1:
		personalkey = inputPersonalkey(); // goi ham inputPersonalkey de valiudata du lieu nhap vao 
		ShowInfomations(selection, personalkey);
		break;

		// tim theo user name
	case 2:
		do {
			cout << "Input Oner Name:   ";
			getline(cin, userName); // nhap thong tin user name muon tim
			if (userName.size() > 0) {
				break;
			}
			else {
				cout << "Please, Re-enter Name!" << endl; // in ra thong bao neu nhap sai
			}
		} while (true);
		ShowInfomations(selection, userName); // goi vao ham ShowInfomations
		break;

		// in ra tat ca info user
	case 3:
		ShowInfomations(selection, userName); // goi vao ham ShowInfomations
		break;

		// tro ve menu
	default:
		menu(); // goi lai ham menu
		break;
	}
}

void ShowInfomations(int chose, string userName_Or_personalkey) {
	int selection = 0;
	
	system("cls");
	cout << "--- SELECT MENU SHOW INFOMATIONS ---" << endl;
	cout << "1. Print Display Setting Informations" << endl;
	cout << "2. Print Sound Setting Informations" << endl;
	cout << "3. Print General Setting Informations" << endl;
	cout << "4. Print All Setting Informations" << endl;
	cout << "5. Exit" << endl;

	do {
		selection = inputNumbers("Your Selection:	"); // goi ham inputNumbers de valiudata du lieu nhap vao 
		if (selection >= 1 && selection <= 5) { // chi duoc nhap tu 1 den 5
			break;
		}
		else {
			cout << "Please enter only 1,2,3,4,5!" << endl; // in ra thong bao neu nhap sai
		}
	} while (true);

	switch (selection)
	{
	case 1: // in ra thong tin display
		system("cls");
		ShowInfomations_Display(chose, userName_Or_personalkey);
		break;

	case 2: // in ra thong tin sound
		system("cls");
		ShowInfomations_Sound(chose, userName_Or_personalkey);
		break;

	case 3: // in ra thong tin general
		system("cls");
		ShowInfomations_General(chose, userName_Or_personalkey);
		break;

	case 4: // in ra thong tin all
		system("cls");
		ShowInfomations_All(chose, userName_Or_personalkey);
		break;

	case 5: // goi lai ham ShowOptions
		ShowOptions();
	}
}

void displayTitleInfo(int type) {
	switch (type)
	{
		case 1: // display
			cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
				<< setw(10) << "Sevices" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
			break;
		case 2: // sound
			cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
				<< setw(10) << "Sevices" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;

			break;
		case 3: // general
			cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
				<< setw(10) << "Sevices" << setw(20) << "TimeZone" << setw(20) << "Language" << endl;
			break;
	default: // all
		cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC"
			<< setw(10) << "ODO" << setw(10) << "Sevices"
			<< setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
			<< setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"
			<< setw(15) << "TimeZone" << setw(20) << "Language" << endl;
		break;
	}
}

void ShowInfomations_Sound(int chose, string userName_Or_personalkey) {
	bool checkEmpty = false;
	if (Listcar.size() == 0) {
		checkEmpty = true;
	}

	if (checkEmpty == false) {
		// in theo personalkey
		if (chose == 1) {
			string personalkey = userName_Or_personalkey;
			displayTitleInfo(TYPE_SOUND);
			for (auto car : Listcar) {
				if (personalkey == car->getPersonalKey()) {
					car->showInfomations();
					car->getSound()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in theo user name
		else if (chose == 2) {
			string userName = userName_Or_personalkey;
			displayTitleInfo(TYPE_SOUND);
			for (auto car : Listcar) {
				if (userName == car->getOwnerName()) {
					car->showInfomations();
					car->getSound()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in ra tat ca
		else {
			displayTitleInfo(TYPE_SOUND);
			for (auto car : Listcar) {
				car->showInfomations();
				car->getSound()->showInfomations();
				cout << "\n";
			}
		}
	}
	else {
		cout << "\n*** List Empty!\n";
	}
	system("PAUSE");
	ShowInfomations(chose, userName_Or_personalkey);
}

void ShowInfomations_General(int chose, string userName_Or_personalkey) {
	bool checkEmpty = false;
	if (Listcar.size() == 0) {
		checkEmpty = true;
	}

	if (checkEmpty == false) {
		// in theo personalkey
		if (chose == 1) {
			string personalkey = userName_Or_personalkey;
			displayTitleInfo(TYPE_GENERAL);
			for (auto car : Listcar) {
				if (personalkey == car->getPersonalKey()) {
					car->showInfomations();
					car->getGeneral()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in theo user name
		else if (chose == 2) {
			string userName = userName_Or_personalkey;
			displayTitleInfo(TYPE_GENERAL);
			for (auto car : Listcar) {
				if (userName == car->getOwnerName()) {
					car->showInfomations();
					car->getGeneral()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in ra tat ca
		else {
			displayTitleInfo(TYPE_GENERAL);
			for (auto car : Listcar) {
				car->showInfomations();
				car->getGeneral()->showInfomations();
				cout << "\n";
			}
		}
	}
	else {
		cout << "\n*** List Empty!\n";
	}
	system("PAUSE");
	ShowInfomations(chose, userName_Or_personalkey);
}

void ShowInfomations_Display(int chose, string userName_Or_personalkey) {
	bool checkEmpty = false;
	if (Listcar.size() == 0) {
		checkEmpty = true;
	}

	if (checkEmpty == false) {
		// in theo personalkey
		if (chose == 1) {
			string personalkey = userName_Or_personalkey;
			displayTitleInfo(TYPE_DISPLAY);
			for (auto car : Listcar) {
				if (personalkey == car->getPersonalKey()) {
					car->showInfomations();
					car->getDisplay()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in theo user name
		else if (chose == 2) {
			string userName = userName_Or_personalkey;
			displayTitleInfo(TYPE_DISPLAY);
			for (auto car : Listcar) {
				if (userName == car->getOwnerName()) {
					car->showInfomations();
					car->getDisplay()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in ra tat ca
		else {
			displayTitleInfo(TYPE_DISPLAY);
			for (auto car : Listcar) {
				car->showInfomations();
				car->getDisplay()->showInfomations();
				cout << "\n";
			}
		}
	}
	else {
		cout << "\n*** List Empty!\n";
	}
	system("PAUSE");
	ShowInfomations(chose, userName_Or_personalkey);
}

void ShowInfomations_All(int chose, string userName_Or_personalkey) {
	bool checkEmpty = false;
	if (Listcar.size() == 0) {
		checkEmpty = true;
	}

	if (checkEmpty == false) {
		// in theo personalkey
		if (chose == 1) {
			string personalkey = userName_Or_personalkey;
			displayTitleInfo(TYPE_ALL);
			for (auto car : Listcar) {
				if (personalkey == car->getPersonalKey()) {
					car->showInfomations();
					car->getDisplay()->showInfomations();
					car->getSound()->showInfomations();
					car->getGeneral()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in theo user name
		else if (chose == 2) {
			string userName = userName_Or_personalkey;
			displayTitleInfo(TYPE_ALL);
			for (auto car : Listcar) {
				if (userName == car->getOwnerName()) {
					car->showInfomations();
					car->getDisplay()->showInfomations();
					car->getSound()->showInfomations();
					car->getGeneral()->showInfomations();
					cout << "\n";
				}
			}
		}
		// in ra tat ca
		else {
			displayTitleInfo(TYPE_ALL);
			for (auto car : Listcar) {
				car->showInfomations();
				car->getDisplay()->showInfomations();
				car->getSound()->showInfomations();
				car->getGeneral()->showInfomations();
				cout << "\n";
			}
		}
	}
	else {
		cout << "\n*** List Empty!\n";
	}
	system("PAUSE");
	ShowInfomations(chose, userName_Or_personalkey);
}

void downloadTimeZone(string namefile)
{
	ifstream readfile;
	string line;
	vector<int> timezone;
	vector<string> NameArea;

	try {
		readfile.open(namefile.c_str());
		if (readfile.fail()) {
			throw 1;
		}
		else {
			while (getline(readfile, line)) {
				vector<string> newvec = explode(line, '/'); // tach cac chuoi cach nhau boi dau '/'
				if (newvec.size() == 2) {
					// lay so gio sau GMT.
					size_t pos = newvec[0].find("T");
					string str = newvec[0].substr(pos + 1, pos + 3);
					int number = atoi(str.c_str());
					// add vao danh sach so gio
					timezone.push_back(number);
					// add vao danh sach ten khu vuc
					NameArea.push_back(newvec[1]);
				}
			}
			// sap xep so gio tang dan
			// su dung thuat toan sap xep bubble sort
			for (unsigned int i = 0; i < timezone.size() - 1; i++) {
				for (unsigned int j = 0; j < timezone.size() - 1 - i; j++) {
					if (timezone[j] > timezone[j + 1]) {
						swap(timezone[j], timezone[j + 1]);
						swap(NameArea[j], NameArea[j + 1]);
					}
				}
			}
			// add vao danh sach timezoneList
			for (unsigned int i = 0; i < timezone.size(); i++) {
				Common info;
				info.setName(NameArea[i]);
				info.setNumber("(GMT " + to_string(timezone[i]) + ":00)");
				timezoneList.push_back(info);
			}
		}
	}
	catch (int e) {
		cout << "Error opening file " << namefile << endl;
		if (e == 1) {
			Common info;
			info.setNumber("(GMT+07:00)");
			for (int i = 0; i < 99; i++) {
				timezoneList.push_back(info);
			}
		}
		system("pause");
	}
	readfile.close();
}

void downloadLanguage(string namefile)
{
	ifstream writefile;
	string line;
	vector<string> languge;
	vector<string> number;

	try {
		writefile.open(namefile.c_str());
		if (writefile.fail()) {
			throw 1;
		}
		else {
			while (getline(writefile, line)) {
				// khoi tao danh sach cac chuoi cach nhau boi dau '/'
				vector<string> newvec = explode(line, '/');
				if (newvec.size() == 2) {
					languge.push_back(newvec[1]);
					number.push_back(newvec[0]);
				}
			}
			// sap xep languge theo anphabet
			sort(languge.begin(), languge.end());
			// add vao danh sach languageList
			for (unsigned int i = 0; i < languge.size(); i++) {
				Common info;
				info.setName(languge[i]);
				info.setNumber(number[i]);
				languageList.push_back(info);
			}
		}
	}
	catch (int e) {
		cout << "Error opening file " << namefile << endl;
		if (e == 1) {
			Common info;
			info.setName("Vietnamese");
			for (int i = 0; i < 99; i++) {
				languageList.push_back(info);
			}
		}
		system("pause");
	}

	writefile.close();
}

void readFileData(string nameFile)
{
	ifstream file;
	
	file.exceptions(ifstream::failbit | ifstream::badbit);

	try {
		file.open(nameFile.c_str(), ios_base::in);
		string line = "";
		while (getline(file, line)) {
			// khoi tao xe moi theo cac gia tri doc duoc trong file 
			CarSetting* newCar = new CarSetting;
			// tao danh sach cac chuoi cach nhau boi dau '/'
			vector<string> data1;
			// tao danh sach cac chuoi cach nhau boi dau ','
			vector<string> data2;

			// tach cac chuoi duoc cach nhau boi dau '/'
			data1 = explode(line, '/');
			// tach cac chuoi duoc cach nhau boi dau ','
			data2 = explode(data1[0], ',');

			// khoi tao cac gia tri cua setting
			newCar->setOwnerName(data2[1]);
			newCar->setEmail(data2[2]);
			newCar->setPersonalKey(data2[3]);

			int ODO = atoi(data2[4].c_str());
			int ServiceRemind = atoi(data2[5].c_str());
			newCar->setODO(ODO);
			newCar->setServiceRemind(ServiceRemind);

			// khoi tao cac gia tri cua display setting
			data2 = explode(data1[1], ',');
			int light_level = atoi(data2[1].c_str());
			int screen_light_level = atoi(data2[2].c_str());
			int taplo_light_level = atoi(data2[3].c_str());
			newCar->getDisplay()->setLightLevel(light_level);
			newCar->getDisplay()->setScreenLightLevel(screen_light_level);
			newCar->getDisplay()->setTaploLightLevel(taplo_light_level);

			// khoi tao cac gia tri cua sound setting
			data2 = explode(data1[2], ',');
			int call_level = atoi(data2[1].c_str());
			int media_level = atoi(data2[2].c_str());
			int navi_level = atoi(data2[3].c_str());
			int notification_level = atoi(data2[4].c_str());
			newCar->getSound()->setCallLevel(call_level);
			newCar->getSound()->setMediaLevel(media_level);
			newCar->getSound()->setNaviLevel(navi_level);
			newCar->getSound()->setNotificationLevel(notification_level);

			// khoi tao cac gia tri cua general setting
			data2 = explode(data1[3], ',');
			newCar->getGeneral()->setLanguage(data2[1]);
			newCar->getGeneral()->setTimeZone(data2[2]);

			// them phan tu moi vao danh sach
			Listcar.push_back(newCar);
		}
		file.close();
	}
	catch (ifstream::failure& ex) {
		cout << ex.what() << endl;
		cout << "Something went wrong!\n";
	}
}

void writeFileData(string nameFile)
{
	ofstream file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		file.open(nameFile.c_str(), ios_base::out);
		for (auto car : Listcar) {
			// ghi thong tin common
			file << "Common: ";
			file << ",";
			file << car->getOwnerName();
			file << ",";
			file << car->getEmail();
			file << ",";
			file << car->getPersonalKey();
			file << ",";
			file << car->getODO();
			file << ",";
			file << car->getServiceRemind();
			file << "/";

			// ghi thong tin display setting
			file << "Display: ";
			file << ",";
			file << car->getDisplay()->getLightLevel();
			file << ",";
			file << car->getDisplay()->getScreenLightLevel();
			file << ",";
			file << car->getDisplay()->getTaploLightLevel();
			file << "/";

			// ghi thong tin sound setting
			file << "Sound: ";
			file << ",";
			file << car->getSound()->getCallLevel();
			file << ",";
			file << car->getSound()->getMediaLevel();
			file << ",";
			file << car->getSound()->getNaviLevel();
			file << ",";
			file << car->getSound()->getNotificationLevel();
			file << "/";

			// ghi thong tin general setting
			file << "General: ";
			file << ",";
			file << car->getGeneral()->getLanguage();
			file << ",";
			file << car->getGeneral()->getTimeZone();
			file << "\n";
		}
	}
	catch (ifstream::failure& ex) {
		cout << ex.what() << endl;
		cout << "somthing went wrong!!" << endl;
	}

	file.close();
}