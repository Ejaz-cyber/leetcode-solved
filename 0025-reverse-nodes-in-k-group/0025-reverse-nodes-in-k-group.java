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
    public ListNode reverseKGroup(ListNode node, int k) {
         //Your code here
        
        // using recursion to reverse
        // TC O(N)
        // SC O(K)
        /*
        if(node == null && k == 1) return node;
        
        ListNode cur = node;
        ListNode prev = null;
        ListNode nxt = node.next;
        int count = 0;
        
        while(cur != null && count < k){
            nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
            
            
            count++;
            
        }
        
        
        if(nxt != null){
            ListNode rem = reverseKGroup(nxt, k);
            node.next = rem;
        }
        
        
        return prev;*/
        
        ListNode dummy = new ListNode(0);
        dummy.next = node;
        
        ListNode curr = dummy;
        ListNode frwd = dummy, prev = dummy;
        int cnt = 0;
        while(curr.next != null){   // counting total nodes
            curr = curr.next;
            cnt++;
        }
        
        while(cnt >= k){
            curr = prev.next;
            frwd = curr.next;
            
            // now reversing nodes in k groups
            for(int i = 1; i<k; i++){
                curr.next = frwd.next;
                frwd.next = prev.next;
                prev.next = frwd;
                frwd = curr.next;
            }
            prev = curr;
            cnt-=k;
            
        }
        
        
        return dummy.next;
    }
}