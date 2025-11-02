#include <iostream>
#include <ctime>
using namespace std;

/*
  Syed Wahaaj Ali
  CT-24035
*/

void sortColors(int* nums, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter total number of objects: ";
    cin >> n;

    int* nums = new int[n];

    cout << "\nEnter colors for each object (0 = Red, 1 = White, 2 = Blue):\n";
    for (int i = 0; i < n; i++) {
        do {
            cout << "Color " << i + 1 << ": ";
            cin >> nums[i];
            if (nums[i] < 0 || nums[i] > 2)
                cout << "Invalid input! Please enter only 0, 1, or 2.\n";
        } while (nums[i] < 0 || nums[i] > 2);
    }

    cout << "\nBefore Sorting (0 = Red, 1 = White, 2 = Blue): ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";

    sortColors(nums, n);

    cout << "\nAfter Sorting (Red → White → Blue): ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";

    delete[] nums;
    cout << "\n";
    return 0;
}
