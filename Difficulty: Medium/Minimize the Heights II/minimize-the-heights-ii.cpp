class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = arr[n-1] - arr[0];
        for(int i=1; i<n; i++) {
            if(arr[i]-k < 0) continue;
            int mini = min(arr[0]+k, arr[i]-k);
            int maxi = max(arr[i-1]+k, arr[n-1]-k);
            ans = min(ans, maxi-mini);
        }
        return ans;
    }
};