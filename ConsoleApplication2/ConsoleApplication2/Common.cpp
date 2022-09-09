#include "Common.h"

string Common::getNumber()
{
	return m_number;
}

string Common::getName()
{
	return m_name;
}

void Common::setNumber(string data)
{
	m_number = data;
}

void Common::setName(string data)
{
	m_name = data;
}
