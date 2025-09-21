/*
    Syed Wahaaj Ali
    CT-24035
*/

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	int start = 0, end = rows * cols - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		int row = mid / cols;
		int col = mid % cols;

		if (matrix[row][col] == target) return true;
		else if (matrix[row][col] < target) start = mid + 1;
		else end = mid - 1;
	}
	return false;
}

int main() {
	int rows, cols;
	cout << "Enter rows: ";
	cin >> rows;
	cout << "Enter cols: ";
	cin >> cols;

	vector<vector<int>> matrix(rows, vector<int>(cols));

	cout << "Enter matrix values (sorted row-wise):\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

	int target;
	cout << "Enter target: ";
	cin >> target;

	if (searchMatrix(matrix, target))
		cout << "Found\n";
	else
		cout << "Not Found\n";

	return 0;
}
