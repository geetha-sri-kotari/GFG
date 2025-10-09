/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void postTraversal(Node* root, vector<int>& post) {
        if(root == nullptr) return;
        postTraversal(root->left, post);
        postTraversal(root->right, post);
        post.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> post;
        postTraversal(root, post);
        return post;
    }
};