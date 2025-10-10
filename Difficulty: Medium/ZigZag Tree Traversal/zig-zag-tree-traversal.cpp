/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<pair<Node *, int>> q;
        vector<pair<int, int>> node_levels;
        q.push({root, 1});
        node_levels.push_back({root->data, 1});
        while(!q.empty()) {
            Node* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            if(curr->left) {
                q.push({curr->left, level+1});
                node_levels.push_back({curr->left->data, level+1});
            }
            if(curr->right) {
                q.push({curr->right, level+1});
                node_levels.push_back({curr->right->data, level+1});
            }
        }
        vector<int> res;
        for(int i=0; i<node_levels.size(); i++) res.push_back(node_levels[i].first);
        int idx = 0;
        int even_start_idx;
        while(idx < res.size()) {
            if(node_levels[idx].second % 2 != 0) {
                while(node_levels[idx].second % 2 != 0) idx++;
                
            }
            else {
                even_start_idx = idx;
                while(idx < node_levels.size() && node_levels[idx].second % 2 == 0) idx++;
                reverse(res.begin()+even_start_idx, res.begin()+idx);
            }
            
        }
        return res;
    }
};