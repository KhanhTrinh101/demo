#include <iostream>
#include "LList.h"
#include "LList.cpp"

using namespace std;

int main() {
	LList<int> list;
	list.add(1);
	list.add(1);
	list.add(1);
	list.add(1);

	cout << list.size();
}
