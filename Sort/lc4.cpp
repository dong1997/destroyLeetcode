//
// Created by dongcl on 2022/3/31.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int findKthNumber(const vector<int> &nums1, int i, const vector<int> &nums2, int j, int k) {
    int n = nums1.size(), m = nums2.size();
    if (n - i > m - j) return findKthNumber(nums2, j, nums1, i, k);

    if (n == i) return nums2[j + k - 1];
    if (k == 1) return min(nums1[i], nums2[j]);
    int si = min(i + k / 2, n), sj = j + k / 2;
    if (nums1[si - 1] < nums2[sj - 1]) {
        return findKthNumber(nums1, si, nums2, j, k - (si - i));
    } else {
        return findKthNumber(nums1, i, nums2, sj, k - (sj - j));
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int total = nums1.size() + nums2.size();
    if (total % 2 == 0) {
//        cout << findKthNumber(nums1, 0, nums2, 0, total / 2) << endl;
//        cout << findKthNumber(nums1, 0, nums2, 0, total / 2 + 1) << endl;

        return (findKthNumber(nums1, 0, nums2, 0, total / 2) + findKthNumber(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
    } else {
        return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
    }
}

int main() {
    vector<int> nums1 = {1, 3}, nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}