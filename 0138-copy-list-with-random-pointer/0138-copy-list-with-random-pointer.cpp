/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * iter = head;
        Node * front = head;
        
        // first make copy of each node linking side by side
        while(iter != NULL){
            front = iter->next;
            
            Node * copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            
            iter = front;
            
        }
        
        // second assign random ptrs for copy nodes
        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            
            iter = iter->next->next;
        }
        
        // third restore the original list and extract the copy list
        
        iter = head;
        Node * pseudoNode = new Node(0);
        Node * copy = pseudoNode;
        
        while(iter != NULL){
            front = iter->next->next;
            
            // extract copy
            copy->next = iter->next;
            
            // restore original
            iter->next = front;
            
            copy = copy->next;
            iter = front;
            
        }
        
        return pseudoNode->next;
        
        
    }
};