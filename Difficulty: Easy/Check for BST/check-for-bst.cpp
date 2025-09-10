class Solution {
  public:
    void InOrder(Node*root, vector<int> &inOrder){
        if(!root) return;
        InOrder(root->left, inOrder);
        inOrder.push_back(root->data);
        InOrder(root->right, inOrder);
    }
    bool isBST(Node* root) {
        vector<int> inOrder;
        InOrder(root, inOrder);
        for(int i=0; i<inOrder.size()-1; i++){
            if(inOrder[i] >= inOrder[i+1]) return false;
        }
        return true;
    }
};

