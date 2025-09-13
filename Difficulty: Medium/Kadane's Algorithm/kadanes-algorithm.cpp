class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int max_so_far = 0;
        int total_max = INT_MIN;
        for(int i=0; i<arr.size(); i++) {
            
            max_so_far += arr[i];
            if(max_so_far > total_max) total_max = max_so_far;
            if(max_so_far < 0)  max_so_far = 0;
            
        }
        return total_max;
    }
};