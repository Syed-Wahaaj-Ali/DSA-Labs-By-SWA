#include <iostream>
#include <algorithm>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

void flip(int arr[], int k) {
	int start = 0;
	while (start < k) {
		swap(arr[start], arr[k]);
		start++;
		k--;
	}
}

void pancakeSort(int arr[], int n, int flips[], int &flipCount) {
	flipCount = 0;
	for (int i = n; i > 1; i--) {
		int maxIdx = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] > arr[maxIdx])
				maxIdx = j;
		}

		if (maxIdx != i - 1) {
			if (maxIdx != 0) {
				flip(arr, maxIdx);
				flips[flipCount++] = maxIdx + 1;
			}
			flip(arr, i - 1);
			flips[flipCount++] = i;
		}
	}
}

int main() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;

	int* arr = new int[n];
	cout << "Enter elements:\n";
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> arr[i];
	}

	int* flips = new int[2 * n];
	int flipCount = 0;

	pancakeSort(arr, n, flips, flipCount);

	cout << "\nFlip positions: ";
	for (int i = 0; i < flipCount; i++)
		cout << flips[i] << " ";

	cout << "\nSorted array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << "\nSorting complete.\n";

	delete[] arr;
	delete[] flips;
	return 0;
}
