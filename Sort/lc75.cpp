//
// Created by dongcl on 2022/3/28.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * divide the entire interval into 4 sub-intervals
 * |----|   |----|   |-----|  |----|
 * 0    j-1 j   i-1  i     k  k+1  n-1
 * [0,j-1] all elements are 0
 * [j,i-1] all elements are 1
 * [i,k] unsort
 * [k+1,n-1] all elements are 2
 */

void sortColors(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0, j = 0, k = n - 1; i <= k;) {
        if (nums[i] == 0) swap(nums[i], nums[j]), ++i, ++j;
        else if (nums[i] == 1) ++i;
        else swap(nums[i], nums[k]), --k;
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (auto &num: nums) cout << num << " ";
}