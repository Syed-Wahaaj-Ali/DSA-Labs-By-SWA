#include <iostream>
#include <algorithm>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

int maxToysCount(int* arr, int n, int k) {
	int idx = 0, count = 0;

	while(idx < n and k >= arr[idx]) {
		k-=arr[idx];
		idx++;
		count++;
	}
	return count;
}

int main() {

	int k ;
	cout << "Enter the value of k : ";
	cin >> k;

	int size;
	cout << "\nEnter the size of Array for Toys : ";
	cin >> size;

	int* arr = new int[size];

	for(int i = 0 ; i < size ; i++) {
		cout << "\nEnter the price of Toy " << i+1 << " : ";
		cin >> arr[i];
	}
	
	sort(arr,arr+size);
	int count = maxToysCount(arr,size,k);
	cout << "\nThe maximum number of toys you can buy with " << k << "Rs are " << count ;
	delete[] arr;
	return 0;
}
