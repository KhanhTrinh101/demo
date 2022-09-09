#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>
#include <string>
#include <iomanip>
#include "valiuData.h"

using namespace std;

class Display
{
public:
	Display();
	~Display();
	void inputInfomations();
	void showInfomations();
	int getLightLevel();
	int getScreenLightLevel();
	int getTaploLightLevel();
	void setLightLevel(int);
	void setScreenLightLevel(int);
	void setTaploLightLevel(int);
private:
	int m_lightLevel;
	int m_screenLightLevel;
	int m_taploLightLevel;
};

#endif
