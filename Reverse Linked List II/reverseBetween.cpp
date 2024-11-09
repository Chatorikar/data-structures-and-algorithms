/**
 * Reverse a sublist within a singly-linked list between two given positions.
 * 
 * This function takes the head of a linked list and two integers, `left` and `right`,
 * indicating the starting and ending positions of the sublist to reverse (1-indexed).
 * It performs the reversal in-place, reconnecting the reversed segment to the rest
 * of the list to maintain the correct structure.
 * 
 * Steps:
 * 1. Traverse to the `left`-th node, setting up `prev` to track the node just before the start.
 * 2. Reverse nodes between positions `left` and `right`, updating pointers to reverse direction.
 * 3. Reconnect the reversed sublist to the rest of the list:
 *    - Connect the node before `left` (if it exists) to the new head of the reversed sublist.
 *    - If `left` is 1, update `head` to point to the new head of the reversed sublist.
 *    - Link the end of the reversed sublist to the node following `right`.
 * 
 * @param head Pointer to the head of the linked list.
 * @param left Starting position of the sublist to reverse.
 * @param right Ending position of the sublist to reverse.
 * @return Updated head of the linked list with the specified sublist reversed.
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL)
            return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        
        // Traverse to the `left`-th node
        while (left > 1) {
            prev = temp;
            temp = temp->next;
            right--;
            left--;
        }

        ListNode* leftConnection = prev;
        ListNode* tail = temp;

        // Reverse nodes from `left` to `right`
        while (right--) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }

        // Reconnect the reversed sublist
        if (leftConnection != NULL) {
            leftConnection->next = prev;
        } else {
            head = prev;
        }

        tail->next = temp;

        return head;
    }
};
