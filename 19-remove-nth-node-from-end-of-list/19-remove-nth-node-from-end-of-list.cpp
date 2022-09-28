/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left = new ListNode(-1);
	ListNode* right = head;
	left->next = head;

	for (size_t i = 0; i < n - 1; i++) {
		right = right->next;
	}

	if (right->next == NULL) {
		return head->next;
	}

	while (right->next != NULL) {
		left = left->next;
		right = right->next;
	}

	left->next = left->next->next;

	return head;
        }
};