/*
    Syed Wahaaj Ali
    CT-24035
*/

#include <iostream>
#include <algorithm>
using namespace std;

class MedianFinder {
	private:
		int* arr;
		int size;

	public:
		MedianFinder() {
			arr = nullptr;
			size = 0;
		}

		void addNum(int num) {
			int* newArr = new int[size + 1];
			for (int i = 0; i < size; i++) {
				newArr[i] = arr[i];
			}
			newArr[size] = num;
			delete[] arr;
			arr = newArr;
			size++;
		}

		double findMedian() {
			int* temp = new int[size];
			for (int i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			sort(temp, temp + size);
			double median;
			if (size % 2 == 1) {
				median = temp[size / 2];
			} else {
				median = (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
			}

			delete[] temp;
			return median;
		}

		~MedianFinder() {
			delete[] arr;
		}
};

int main() {
	MedianFinder medianFinder;
	medianFinder.addNum(1);
	medianFinder.addNum(2);
	cout << medianFinder.findMedian() << endl;
	medianFinder.addNum(3);
	cout << medianFinder.findMedian() << endl;
	return 0;
}
