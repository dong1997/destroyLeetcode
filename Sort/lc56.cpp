//
// Created by dongcl on 2022/3/23.
//
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

/*
 * sort given intervals into ascending order (intervals[0] first, intervals[1] second)
 * merge adjacent intervals if intervals intersect
 */

vector<vector<int>> merge(vector<vector<int>> &intervals) {
//    sort(intervals.begin(), intervals.end(), cmp);
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) -> bool { return a[0] < b[0]; });
    int n = intervals.size();
    vector<vector<int>> res;

    for (int i = 0; i < n; ++i) {
        auto now = intervals[i];
        int j = i + 1;
        while (j < n && now[0] <= intervals[j][0] && now[1] >= intervals[j][0]) {
            now[1] = max(now[1], intervals[j][1]);
            ++j;
        }
        res.push_back(now);
        i = j - 1;
    }
    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,  3},
                                     {2,  6},
                                     {8,  10},
                                     {15, 18}};
    auto res = merge(intervals);

}
