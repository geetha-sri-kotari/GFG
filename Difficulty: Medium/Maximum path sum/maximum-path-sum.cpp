/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int maxi = INT_MIN;
    int fun(Node *root) {
        if(root == nullptr) return 0;
        int left = 0;
        int right = 0;
        if(root->left) left = fun(root->left);
        if(root->right) right = fun(root->right);
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        maxi = max(maxi, root->data+left+right);
        return root->data + max(left, right);
    }
    int findMaxSum(Node *root) {
        // code here
        int ans =fun(root);
        return maxi;
    }
};