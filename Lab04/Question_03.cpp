#include <iostream>
#include <vector>
using namespace std;

/*
  Syed Wahaaj Ali
*/

void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums); // reached a complete permutation
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);             // place nums[i] at current position
        permuteHelper(nums, start + 1, result); // generate permutations for the rest
        swap(nums[start], nums[i]);             // backtrack to restore original order
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> result;
    permuteHelper(nums, 0, result);

    cout << "All permutations:\n";
    for (auto& perm : result) {
        cout << "[ ";
        for (int num : perm) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
