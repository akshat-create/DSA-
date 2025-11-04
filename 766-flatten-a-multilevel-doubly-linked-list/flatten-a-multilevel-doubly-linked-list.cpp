/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;
        stack<Node*> nodeStack;

        while (current != nullptr) {
            if (current->child != nullptr) {
                Node* nextNode = current->next;

                // Connect current node to the child list
                current->next = current->child;
                current->child->prev = current;
                current->child = nullptr;

                // Push the next node onto the stack for later processing
                if (nextNode != nullptr) {
                    nodeStack.push(nextNode);
                }
            } else if (current->next == nullptr && !nodeStack.empty()) {
                // If there are no more nodes in the current level,
                // pop a node from the stack and connect it to the current node
                Node* nextNode = nodeStack.top();
                nodeStack.pop();
                current->next = nextNode;
                nextNode->prev = current;
            }

            current = current->next;
        }

        return head;
    }
};