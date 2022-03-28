//
// Created by dongcl on 2022/3/28.
//

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * at first, consider just two elements in nums, the sorting result obviously correct.
 * when extend to multiple elements, there is a partial order relationship,
 * that is, when A must before B and B must before C ,A must before C
 */
string largestNumber(vector<int> &nums) {
    string res = "";
    if (nums.empty()) return res;

    sort(nums.begin(), nums.end(),
         [](int &a, int &b) -> bool { return to_string(a) + to_string(b) > to_string(b) + to_string(a); });

    for (auto &num: nums) res += to_string(num);
    int i;
    for (i = 0; i < res.size(); ++i) {
        if (res[i] != '0') break;
    }
    if (i == res.size()) --i;
    return res.substr(i);
}

int main() {
    vector<int> nums = {0, 0};
    cout << largestNumber(nums) << endl;
}