#include <iostream>
#include <algorithm>

using namespace std;

int LinearExhaustive(int a[], int n, int x) {

	for (int i = 0; i < n; i++) {
		if (a[i] == x) return i;
	}

	return -1;
}

int LinearSentinel(int a[], int n, int x) {
	int value = a[n - 1];
	a[n - 1] = x;
	int i = -1;
	for (; i < n; i++) {
		if (a[i] == x) break;
	}

	a[n - 1] = value;
	// TH: i == n - 1
	if (i == (n - 1) && value == x) {
		return i;
	}
	// TH con lai
	else {
		return i;
	}
}

int BinarySearch(int a[], int n, int x) {

	int low = 0;
	int high = n - 1;

	while (low < high) {
		int mid = (low + high) / 2;

		//if (x < a[mid]) high = mid - 1;
		if (x > a[mid]) low = mid + 1;
		//if (x == a[mid]) return mid;
		else {
			high = mid;
		}
	}

	if (a[low] == x) {
		return low;
	}

	return -1;
}

int main() {

	int a[] = { 1,2,3,4 };



	int x = 2;
	

	//int i = LinearExhaustive(a, 10, x);
	// int i = LinearSentinel(a, 10, x);
	//swap(a[3], a[5]);
	//sort(a, a + 10);
	//for (int i = 0; i < 10; i++) {
	//	cout << a[i] << " ";
	//}

	 int i = BinarySearch(a, 4, x);

	if (i == -1) {
		cout << "Khong tim thay " << x << " trong mang A\n";
	}
	else {
		cout << "Vi tri " << x << " trong mang A la: " << i + 1 << "\n";
	}

	return 0;

}