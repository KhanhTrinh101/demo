#include <iostream>
#include <algorithm> 

using namespace std;

int main() {

    int myints[] = { 12, 23, 56, 76, 43, 56, 21, 78, 80, 56 };

    for (int i = 0; i < 10; i++) {
        cout << myints[i] << " ";
    }

    int number = 21;
    int n = count(myints, myints + 10, number);
    cout << "\nso lan xuat hien cua "<< number <<" trong mang la: " << n;

    return 0;

}