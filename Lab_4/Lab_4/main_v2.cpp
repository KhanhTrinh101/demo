#include <iostream>
#include <algorithm> 

using namespace std;

int main() {

    int myints[] = { 12, 23, 56, 76, 43, 56, 21, 78, 80, 56,21 };

    for (int i = 0; i < 10; i++) {

        cout << myints[i] << " ";

    }

    int pattern[] = { 56,21 };

    int* n = search(myints, myints + 10, pattern, pattern + 2);
    int index = n - myints; // khoang cach giua hai dia chi la vi tri cua patten.
    if (index < 10) {
        cout << "\n===============";
        cout << "\nvi tri cua patten trong mang la: " << index + 1 << endl;
    }   
    else {
        cout << "\n===============";
        cout << "\nnot found!\n";
    }
    return 0;

}