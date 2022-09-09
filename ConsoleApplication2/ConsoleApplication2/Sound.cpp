#include "Sound.h"

Sound::Sound() {
	m_mediaLevel = 0;
	m_callLevel = 0;
	m_naviLevel = 0;
	m_notificationLevel = 0;
}

Sound::~Sound() {}

int Sound::getMediaLevel() {
	return m_mediaLevel;
}

int Sound::getCallLevel() {
	return m_callLevel;
}

int Sound::getNaviLevel() {
	return m_naviLevel;
}

int Sound::getNotificationLevel() {
	return m_notificationLevel;
}

void Sound::setMediaLevel(int data) {
	m_mediaLevel = data;
}

void Sound::setCallLevel(int data) {
	m_callLevel = data;
}

void Sound::setNaviLevel(int data) {
	m_naviLevel = data;
}

void Sound::setNotificationLevel(int data) {
	m_notificationLevel = data;
}

void Sound::inputInfomations() {
	m_mediaLevel = inputNumbers("Input Information Media Level:   ");
	m_callLevel = inputNumbers("Input Information Call Level:   ");
	m_naviLevel = inputNumbers("Input Information Navi Level:   ");
	m_notificationLevel = inputNumbers("Input Information Notification Level:   ");
}

void Sound::showInfomations() {
	cout << setw(10) << m_mediaLevel;
	cout << setw(10) << m_callLevel;
	cout << setw(10) << m_naviLevel;
	cout << setw(10) << m_notificationLevel;
}
