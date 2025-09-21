/*
    Syed Wahaaj Ali
    CT-24035
*/

#include <iostream>
using namespace std;

int main() {
	int rows, cols;
	
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << "Enter number of columns: ";
	cin >> cols;

	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
	int* oneD = new int[rows * cols];

	cout << "Enter elements of 2D array:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> arr[i][j];
		}
	}

	int index = 0;
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			oneD[index++] = arr[i][j];
		}
	}

	cout << "1D array in column-major order:" << endl;
	for (int i = 0; i < rows * cols; i++) {
		cout << oneD[i] << " ";
	}
	cout << endl;
	
	delete[] oneD;
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	
	return 0;
}
