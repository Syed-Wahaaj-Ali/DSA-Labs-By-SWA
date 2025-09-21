/*
    Syed Wahaaj Ali
    CT-24035
*/

#include <iostream>
#include <iomanip>
using namespace std;

float* gpa(float **arr, int sub, int students) {
	float* res = new float[students];
	for (int i = 0; i < students; i++) {
		res[i] = 0;
		for (int j = 0; j < sub; j++) {
			res[i] += arr[i][j];
		}
		res[i] /= sub;
	}
	return res;
}

int main() {
	cout << fixed << setprecision(2);
	int fixedStudents = 5, fixedCourses = 5;

	float **grid = new float*[fixedStudents];
	for (int i = 0; i < fixedStudents; i++) {
		grid[i] = new float[fixedCourses];
	}

	double init[5][5] = {
		{3.66, 3.33, 4.0, 3.0, 2.66},   // Ali
		{3.33, 3.0,  3.66, 3.0, 0},     // Hiba
		{4.0,  3.66, 2.66, 0, 0},       // Asma
		{2.66, 2.33, 4.0,  0, 0},       // Zain
		{3.33, 3.66, 4.0,  3.0, 3.33}   // Faisal
	};

	for (int i = 0; i < fixedStudents; i++) {
		for (int j = 0; j < fixedCourses; j++) {
			grid[i][j] = init[i][j];
		}
	}

	string names[5] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};

	cout << "--- Fixed Test (Manual Data) ---\n";
	float *res1 = gpa(grid, fixedCourses, fixedStudents);
	for (int i = 0; i < fixedStudents; i++) {
		cout << names[i] << " GPA: " << res1[i] << endl;
	}
	delete[] res1;

	for (int i = 0; i < fixedStudents; i++) {
		delete[] grid[i];
	}
	delete[] grid;

	int c, s;
	cout << "\nEnter number of courses: ";
	cin >> c;
	cout << "Enter number of students: ";
	cin >> s;

	float **matrix = new float*[s];
	for (int i = 0; i < s; i++) {
		matrix[i] = new float[c];
	}

	cout << "\n--- Enter Grades ---\n";
	for (int i = 0; i < s; i++) {
		cout << "\nStudent " << i + 1 << ":\n";
		for (int j = 0; j < c; j++) {
			cout << "Course " << j + 1 << ": ";
			cin >> matrix[i][j];
		}
	}

	float *res = gpa(matrix, c, s);
	cout << "\n--- Custom Test Results ---\n";
	for (int i = 0; i < s; i++) {
		cout << "Student " << i + 1 << " GPA: " << res[i] << endl;
	}
	delete[] res;

	for (int i = 0; i < s; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
