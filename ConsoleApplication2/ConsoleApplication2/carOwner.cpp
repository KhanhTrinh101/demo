#include "carOwner.h"

CarOwner::CarOwner()
{
	m_ownerName = "";
	m_personalkey = "";
	m_email = "";
	m_odo = 0;
	m_serviceRemind = 0;
}

CarOwner::~CarOwner() {}

string CarOwner::getOwnerName() {
	return m_ownerName;
}

string CarOwner::getPersonalKey() {
	return m_personalkey;
}

string CarOwner::getEmail() {
	return m_email;
}

int CarOwner::getODO() {
	return m_odo;
}

int CarOwner::getServiceRemind() {
	return m_serviceRemind;
}

void CarOwner::setOwnerName(string data)
{
	m_ownerName = data;
}

void CarOwner::setPersonalKey(string data)
{
	m_personalkey = data;
}

void CarOwner::setEmail(string data)
{
	m_email = data;
}

void CarOwner::setODO(int data)
{
	m_odo = data;
}

void CarOwner::setServiceRemind(int data)
{
	m_serviceRemind = data;
}

void CarOwner::inputInfomations() {
	while (m_ownerName == "") {
		cout << "Input Owner Name:   ";
		getline(cin, m_ownerName);
	}

	do {
		cout << "Input Email:   ";
		getline(cin, m_email);
	} while (checkEmail(m_email) == false);

	bool flash = true;
	do {
		cout << "Input key number:   ";
		getline(cin, m_personalkey);
		flash = true;

		if (m_personalkey.size() == 8) {
			for (unsigned int i = 0; i < m_personalkey.size(); i++) {
				if (checkNumber(m_personalkey[i]) == false) {
					cout << "===> please, only positive numbers are allowed!" << endl;
					flash = false;
					break;
				}
			}
		}
		else {			
			flash = false;
			cout << "Please enter all 8 numbers!" << endl;
		}
	} while (flash == false);
	
	m_odo = inputNumbers("Input Information ODO Number:   ");
	m_serviceRemind = inputNumbers("Input Information Remind Service (km):   ");
}

void CarOwner::showInfomations() {
	cout << setw(20) << m_ownerName
		<< setw(25) << m_email
		<< setw(10) << m_personalkey
		<< setw(10) << m_odo
		<< setw(10) << m_serviceRemind;
}