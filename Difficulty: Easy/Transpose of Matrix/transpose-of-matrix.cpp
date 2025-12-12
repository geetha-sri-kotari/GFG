class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res;
        
        for(int i=0; i<m; i++) {
            vector<int> temp;
            for(int j=0; j<n; j++) {
                temp.push_back(mat[j][i]);
            }
            res.push_back(temp);

        }
        return res;
    }
};