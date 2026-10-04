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

        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        // Created copied nodes
        Node* curr = head;

        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Connecting next and random pointers
        curr = head;

        while (curr != nullptr) {
            Node* copy = mp[curr];

            copy->next = mp[curr->next];
            copy->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};