/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

// 1. Either place the function definition above the main function
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* curr = head;

    while (curr) {
        struct ListNode* next_node = curr->next;
        struct ListNode* prev = dummy;

        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;
        curr = next_node;
    }

    struct ListNode* sorted_head = dummy->next;
    free(dummy);
    return sorted_head;
}

// 2. Or add a function prototype at the top if the function is below main
// struct ListNode* insertionSortList(struct ListNode* head);