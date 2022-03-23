#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *construct_link_list(const vector<int> &nums) {
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;
    for (auto &num: nums) {
        ListNode *now = new ListNode(num);
        p->next = now;
        p = p->next;
    }
    return dummy->next;
}

/*
 *
 *                          time complexity   space complexity
 * quick sort(recursively)  nlogn             1
 * quick sort(circularly)   nlogn             logn
 * merge sort               nlogn             logn
 *
 * sort a linked list into ascending order
 * if we use merge sort recursively the space complexity will be o(logn) because of system stack
 * so we sort it circularly from bottom to top
 * we merge two small sub linked list into a big linked list
 * variable i represents length
 * variable j represents start position of second linked list
*/
ListNode *sortList(ListNode *head) {
    int n = 0;
    for (auto p = head; p; p = p->next) ++n;

    auto dummy = new ListNode(-1);
    dummy->next = head;

    for (int i = 1; i < n; i *= 2) {
        auto cur = dummy;
        for (int j = 1; j + i <= n; j += 2 * i) {
            auto p = cur->next, q = p;
            for (int k = 0; k < i; ++k) q = q->next;
            int x = 0, y = 0;
            while (x < i && y < i && p && q) {
                if (p->val < q->val) cur = cur->next = p, p = p->next, ++x;
                else cur = cur->next = q, q = q->next, ++y;
            }
            while (x < i && p) cur = cur->next = p, p = p->next, ++x;
            while (y < i && q) cur = cur->next = q, q = q->next, ++y;
            cur->next = q;
        }
    }
    return dummy->next;
}


int main() {
    vector<int> nums = {-1, 5, 3, 4, 0};
    auto head = construct_link_list(nums);
    head = sortList(head);
    for (; head; head = head->next) cout << head->val << " ";
    return 0;
}
