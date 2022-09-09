#pragma once
#ifndef GENERAL_H_
#define GENERAL_H_

#include "Common.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "valiuData.h"

using namespace std;

class General
{
public:
	General();
	~General();
	void inputInfomations();
	void showInfomations();
	string getLanguage();
	string getTimeZone();
	void setTimeZone(string);
	void setLanguage(string);
private:
	string m_timeZone;
	string m_language;
};

#endif