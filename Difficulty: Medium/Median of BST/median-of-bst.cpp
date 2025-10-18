/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findMedian(Node* root) {
        // Code here
        queue<Node *> q;
        q.push(root);
        vector<int> nodes;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            nodes.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        sort(nodes.begin(), nodes.end());
        int n = nodes.size();
        if(n % 2 == 0) return nodes[n/2 - 1];
        else return nodes[(n + 1)/2 - 1];
    }
};