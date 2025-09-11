class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        /*int n = arr.size();
        
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for(int i=0; i<n-1; i++) {
            if(arr[i] == 0) continue;
            for(int j = i + 1; j <= i + arr[i] && j < n; j++) {
                if(dp[i] != INT_MAX) {
                    dp[j] = min(dp[j], dp[i]+1);
                }
            }
        }
        return (dp[n-1] == INT_MIN || dp[n-1] == INT_MAX) ? -1 : dp[n - 1];*/
        
        //greedy
        int n = arr.size();
        if(arr[0] == 0) return -1;
        int currReach = 0, maxReach = 0, jumps = 0;
        for(int i=0; i<n; i++) {
            maxReach = max(maxReach, i+arr[i]);
            if(maxReach >= n-1) return jumps + 1;
            if(i == currReach) {
                if(i == maxReach) return -1;
                else {
                    jumps++;
                    currReach = maxReach;
                }
            }
        }
        return -1;
    }
};
