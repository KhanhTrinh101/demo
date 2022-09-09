#include "LList.h"

template<typename T>
node<T>::node(T data)
{
	m_data = data;
	m_next = NULL;
}

template<typename T>
T node<T>::Data()
{
	return m_data;
}

template<typename T>
node<T>* node<T>::Next()
{
	return m_next;
}

template<typename T>
void node<T>::setData(T data)
{
	m_data = data;
}

template<typename T>
void node<T>::setNext(node<T>* next)
{
	m_next = next;
}

template<typename T>
LList<T>::LList()
{
	head = NULL;
}

template<typename T>
void LList<T>::readFile(string)
{
}

template<typename T>
void LList<T>::writeFile(string)
{
}

template<typename T>
void LList<T>::add(T data)
{
	node<T>* newNode = new node<T>(data);
	if (head == NULL) {
		head = newNode;
	}
	else {
		node<T>* tmp = head;
		while (tmp->Next() != NULL) {
			tmp = tmp->Next();
		}
		tmp->setNext(newNode);
	}
}

template<typename T>
int LList<T>::size()
{
	if (head == NULL) {
		return 0;
	}
	else {
		int number = 0;
		node<T>* tmp = head;
		do {
			number++;
			tmp = tmp->Next();
		} while (tmp != NULL);
		return number;
	}
}

template<typename T>
node<T>* LList<T>::searchPerSonnalKey(string perSonnalKey)
{
	if (head == NULL) {
		return NULL;
	}
	else {
		node<T>* tmp = head;
		do {
			if (tmp->Data().getPersonalKey() == perSonnalKey)
				return tmp;
			tmp = tmp->Next();
		} while (tmp != NULL);
		return NULL;
	}
}

template<typename T>
void LList<T>::showData_name(string name, int type)
{
	if (head == NULL) {
		cout << "List Empty!\n";
	}
	else {
		node<T>* tmp = head;
		do {
			if (tmp->Data().getOwnerName() == name) {
				if (type == 1) {
					tmp->Data().getDisplay()->showInfomations();
				}
				else if (type == 2) {
					tmp->Data().getSound()->showInfomations();
				}
				else if (type == 3) {
					tmp->Data().getGeneral()->showInfomations();
				}
				else {
					tmp->Data().getDisplay()->showInfomations();
					tmp->Data().getSound()->showInfomations();
					tmp->Data().getGeneral()->showInfomations();
				}
			}
			tmp = tmp->Next();
		} while (tmp != NULL);
	}
}

template<typename T>
void LList<T>::showData_all(int type)
{
	if (head == NULL) {
		cout << "List Empty!\n";
	}
	else {
		node<T>* tmp = head;
		do {
			if (type == 1) {
				tmp->Data().getDisplay()->showInfomations();
			}
			else if (type == 2) {
				tmp->Data().getSound()->showInfomations();
			}
			else if (type == 3) {
				tmp->Data().getGeneral()->showInfomations();
			}
			else {
				tmp->Data().getDisplay()->showInfomations();
				tmp->Data().getSound()->showInfomations();
				tmp->Data().getGeneral()->showInfomations();
			}
			tmp = tmp->Next();
		} while (tmp != NULL);
	}
}
