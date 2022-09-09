#pragma once
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class node {
private:
	T m_data;
	node<T>* m_next;
public:
	node(T);
	T Data();
	node<T>* Next();
	void setData(T);
	void setNext(node<T>*);
};

template<typename T>
class LList {
private:
	node<T>* head;
public:
	LList();
	void readFile(string);
	void writeFile(string);
	void add(T);
	int size();
	node<T>* searchPerSonnalKey(string);
	void showData_name(string, int);
	void showData_all(int);
};


