#pragma once
#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include "valiuData.h"

using namespace std;

class CarOwner
{
public:
	CarOwner();
	virtual ~CarOwner();
	void inputInfomations();
	void showInfomations();
	string getOwnerName();
	string getPersonalKey();
	string getEmail();
	int getODO();
	int getServiceRemind();
	void setOwnerName(string);
	void setPersonalKey(string);
	void setEmail(string);
	void setODO(int);
	void setServiceRemind(int);
private:
	string m_ownerName;
	string m_personalkey;
	string m_email;
	int m_odo;
	int m_serviceRemind;
};

#endif