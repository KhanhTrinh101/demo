#pragma once
#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <string>

using namespace std;

class Common
{
public:
	string getNumber();
	string getName();
	void setNumber(string);
	void setName(string);
private:
	string m_number;
	string m_name;
};

#endif