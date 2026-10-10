/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prevGroupTail = dummy;

        while (true) {
            // Find the kth node from the start of this group
            ListNode kth = prevGroupTail;

            for (int i = 0; i < k && kth != null; i++) {
                kth = kth.next;
            }

            // Fewer than k nodes remain: do not reverse them
            if (kth == null) {
                break;
            }

            ListNode groupNext = kth.next;

            // Reverse the current group
            ListNode prev = groupNext;
            ListNode curr = prevGroupTail.next;

            while (curr != groupNext) {
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }

            // Connect the reversed group to the previous part
            ListNode oldGroupHead = prevGroupTail.next;
            prevGroupTail.next = kth;
            prevGroupTail = oldGroupHead;
        }

        return dummy.next;
    }
}