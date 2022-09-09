#pragma once
#ifndef SOUND_H_
#define SOUND_H_

#include <iostream>
#include <string>
#include <iomanip>
#include "valiuData.h"

using namespace std;

class Sound
{
public:
	Sound();
	~Sound();
	void inputInfomations();
	void showInfomations();
	int getMediaLevel();
	int getCallLevel();
	int getNaviLevel();
	int getNotificationLevel();
	void setMediaLevel(int);
	void setCallLevel(int);
	void setNaviLevel(int);
	void setNotificationLevel(int);

private:
	int m_mediaLevel;
	int m_callLevel;
	int m_naviLevel;
	int m_notificationLevel;
};

#endif
