#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

class SortAnalyzer {
	private:
		int compCount;
		int swapCount;

	public:
		SortAnalyzer() {
			compCount = 0;
			swapCount = 0;
			srand(time(0));
		}

		void resetCounters() {
			compCount = 0;
			swapCount = 0;
		}

		void fillRandom(int* arr, int n) {
			for (int i = 0; i < n; i++)
				arr[i] = rand() % 100;  // random values between 0–99
		}

		void selectionSort(int* arr, int n) {
			for (int i = 0; i < n - 1; i++) {
				int minIdx = i;
				for (int j = i + 1; j < n; j++) {
					compCount++;
					if (arr[j] < arr[minIdx])
						minIdx = j;
				}
				if (minIdx != i) {
					swap(arr[i], arr[minIdx]);
					swapCount++;
				}
			}
		}

		void bubbleSort(int* arr, int n) {
			for (int i = 0; i < n - 1; i++) {
				bool didSwap = false;
				for (int j = 0; j < n - i - 1; j++) {
					compCount++;
					if (arr[j] > arr[j + 1]) {
						swap(arr[j], arr[j + 1]);
						swapCount++;
						didSwap = true;
					}
				}
				if (!didSwap) break;
			}
		}

		void insertionSort(int* arr, int n) {
			for (int i = 1; i < n; i++) {
				int key = arr[i];
				int j = i - 1;
				while (j >= 0 && arr[j] > key) {
					compCount++;
					arr[j + 1] = arr[j];
					j--;
					swapCount++;
				}
				if (j >= 0) compCount++;
				arr[j + 1] = key;
			}
		}

		void sortAndDisplay(int* arr, int n, string algo) {
			resetCounters();

			if (algo == "selection") selectionSort(arr, n);
			else if (algo == "bubble") bubbleSort(arr, n);
			else if (algo == "insertion") insertionSort(arr, n);
			else {
				cout << "\nInvalid sorting method entered!\n";
				return;
			}

			cout << "\nArray after applying " << algo << " sort:\n";
			for (int i = 0; i < n; i++) cout << arr[i] << " ";
			cout << "\n\nTotal Comparisons: " << compCount;
			cout << "\nTotal Swaps: " << swapCount << "\n";
		}

		void compareAll(int n) {
			int* baseArr = new int[n];
			fillRandom(baseArr, n);

			cout << "\nRandomly generated array: ";
			for (int i = 0; i < n; i++) cout << baseArr[i] << " ";
			cout << "\n";

			int* sArr = new int[n];
			int* bArr = new int[n];
			int* iArr = new int[n];
			copy(baseArr, baseArr + n, sArr);
			copy(baseArr, baseArr + n, bArr);
			copy(baseArr, baseArr + n, iArr);

			int sComp, bComp, iComp;
			int sSwap, bSwap, iSwap;

			resetCounters();
			selectionSort(sArr, n);
			sComp = compCount;
			sSwap = swapCount;
			resetCounters();
			bubbleSort(bArr, n);
			bComp = compCount;
			bSwap = swapCount;
			resetCounters();
			insertionSort(iArr, n);
			iComp = compCount;
			iSwap = swapCount;

			cout << "\n--- Sorting Performance Summary ---\n";
			cout << "Selection Sort ? Comparisons: " << sComp << ", Swaps: " << sSwap << endl;
			cout << "Bubble Sort    ? Comparisons: " << bComp << ", Swaps: " << bSwap << endl;
			cout << "Insertion Sort ? Comparisons: " << iComp << ", Swaps: " << iSwap << endl;

			int totals[3] = { sComp + sSwap, bComp + bSwap, iComp + iSwap };
			string algoNames[3] = { "Selection Sort", "Bubble Sort", "Insertion Sort" };

			int minIdx = 0, maxIdx = 0;
			for (int i = 1; i < 3; i++) {
				if (totals[i] < totals[minIdx]) minIdx = i;
				if (totals[i] > totals[maxIdx]) maxIdx = i;
			}

			cout << "\nMost Efficient: " << algoNames[minIdx];
			cout << "\nLeast Efficient: " << algoNames[maxIdx] << "\n";

			delete[] sArr;
			delete[] bArr;
			delete[] iArr;
			delete[] baseArr;
		}
};

int main() {
	SortAnalyzer sorter;

	int n;
	cout << "Enter total elements: ";
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter value " << i + 1 << ": ";
		cin >> arr[i];
	}
	string algo;
	cout << "\nChoose sorting algorithm (selection / bubble / insertion): ";
	cin >> algo;
	sorter.sortAndDisplay(arr, n, algo);
	cout << "\n\n--- Running Efficiency Comparison on Random Array ---\n";
	sorter.compareAll(n);
	delete[] arr;
	return 0;
}
