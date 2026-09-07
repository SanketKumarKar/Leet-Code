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
    public ListNode removeElements(ListNode head, int val) {
        while(head!=null && head.val==val) {
            head=head.next;
        }
        ListNode temp = head;
        while(temp!=null && temp.next!=null){
            if(temp.next.val==val)
            temp.next=temp.next.next; // agar next wala val ke barabar ho remove the link
            else temp=temp.next; // warna ek node aage 
        } return head;
    }
}