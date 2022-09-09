#pragma once
#ifndef CARSETTING_H_
#define CARSETTING_H_

#include <iostream>
#include "Display.h"
#include "General.h"
#include "Sound.h"
#include "carOwner.h"

class CarSetting : public CarOwner
{
public:
	CarSetting();
	~CarSetting();
	Display* getDisplay();
	Sound* getSound();
	General* getGeneral();
private:
	Display* m_display;
	Sound* m_sound;
	General* m_general;
};

#endif
