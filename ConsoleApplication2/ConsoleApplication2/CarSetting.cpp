#include "CarSetting.h"

CarSetting::CarSetting()
{
	m_display = new Display();
	m_sound = new Sound();
	m_general = new General();
}

CarSetting::~CarSetting() {
	if (m_display != nullptr) {
		delete m_display;
	}
	if (m_sound != nullptr) {
		delete m_sound;
	}
	if (m_general != nullptr) {
		delete m_general;
	}
}

Display* CarSetting::getDisplay()
{
	return m_display;
}

Sound* CarSetting::getSound()
{
	return m_sound;
}

General* CarSetting::getGeneral()
{
	return m_general;
}