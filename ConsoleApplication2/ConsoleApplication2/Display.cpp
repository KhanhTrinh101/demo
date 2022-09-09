#include "Display.h"

Display::Display()
{
	this->m_lightLevel = 0;
	this->m_screenLightLevel = 0;
	this->m_taploLightLevel = 0;
}

Display::~Display() {}

int Display::getLightLevel() {
	return m_lightLevel;
}

int Display::getScreenLightLevel() {
	return m_screenLightLevel;
}

int Display::getTaploLightLevel() {
	return m_taploLightLevel;
}

void Display::setLightLevel(int data) {
	m_lightLevel = data;
}

void Display::setScreenLightLevel(int data) {
	m_screenLightLevel = data;
}

void Display::setTaploLightLevel(int data) {
	m_taploLightLevel = data;
}

void Display::inputInfomations() {
	m_lightLevel = inputNumbers("Input Information Light Level:   ");
	m_screenLightLevel = inputNumbers("Input Information Screen Light Level:   ");
	m_taploLightLevel = inputNumbers("Input Information Taplo Light Leve:   ");
}

void Display::showInfomations() {
	cout << setw(10) << m_lightLevel
		<< setw(10) << m_taploLightLevel
		<< setw(10) << m_screenLightLevel;
}