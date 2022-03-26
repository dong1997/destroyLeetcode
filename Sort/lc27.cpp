//
// Created by dongcl on 2022/3/26.
//

#include <vector>
#include <iostream>

using namespace std;

/*
 * two pointers i initialize with 0 j initialize with n-1
 * when we encounter nums[i]==val
 * we swap the nums[i] with the nums[j]
 * and dispose the last one this essentially reduce array's size by 1
 */
int removeElement(vector<int> &nums, int val) {
    int n = nums.size();
    int i = 0, j = n - 1;
    for (; i <= j; ++i) {
        if (nums[i] == val) {
            swap(nums[i], nums[j]);
            --j;
            --i;
        }
    }
    return j + 1;
}

int main() {
    vector<int> nums = {4, 1, 2, 3, 5};
    int newSize = removeElement(nums, 3);
}