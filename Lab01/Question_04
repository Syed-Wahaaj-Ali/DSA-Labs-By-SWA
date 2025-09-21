/*
    Syed Wahaaj Ali
    CT-24035
*/

#include <iostream>
using namespace std;

int search(int arr[], int size, int target) {
    int l = 0, r = size - 1, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " sorted elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter element to look for: ";
    cin >> target;

    int idx = search(arr, size, target);
    if (idx == -1) {
        cout << "Element does not exist!!\n";
    }
    else {
        cout << "Element is at index " << idx << endl;
    }

    delete[] arr;
    return 0;
}
