class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        int n = points.size();
        vector<pair<int, int>> distances;
        for(int i=0; i<n; i++) {
            distances.push_back({(points[i][0] * points[i][0] + 
                                         points[i][1] * points[i][1])
                                 , i});
        }
        sort(distances.begin(), distances.end());
        //for(int i=0; i<n; i++) cout << distances[i].second << " " << distances[i].first << endl;
        vector<vector<int>> ans;
        for(int i=0; i<k; i++) {
            int idx = distances[i].second;
            ans.push_back(points[idx]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};