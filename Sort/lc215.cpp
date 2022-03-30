//
// Created by dongcl on 2022/3/30.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
 * solution 1
 * sort nums into descending order, then return nums[k-1]
 *
 * time complexity O(nlogn) space complexity O(logn)
 */
//int findKthLargest(vector<int> &nums, int k) {
//    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
//    return nums[k - 1];
//}

/*
 * maintain a small top heap of size K
 * after loop, the top element in small top heap is actually the Kth largest element in the array
 *
 */
int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<>> pq;

    for (auto &num: nums) {
        pq.push(num);
        if (pq.size() > k) pq.pop();
    }
    return pq.top();
}

int main() {
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(nums, 4) << endl;

}