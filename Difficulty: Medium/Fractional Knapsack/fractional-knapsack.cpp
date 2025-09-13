class Solution {
  public:
    static bool comp(const pair<double, double>& a, const pair<double, double>& b) {
        double r1 = (double)(a.first / a.second) * 1.0;
        double r2 = (double)(b.first / b.second) * 1.0;
        return r1 > r2;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double, double>> items;
        for(int i=0; i<val.size(); i++) {
            items.push_back({val[i], wt[i]});
        }
        sort(items.begin(), items.end(), comp);
        double pick = 0.0;
        for(double i=0; i<items.size(); i++) {
            if(items[i].second < capacity) {
                pick += (double)items[i].first;
                capacity -= items[i].second;
            }
            else {
                pick += (double)(items[i].first / items[i].second) * capacity;
                capacity = 0;
                break;
            }
        }
        return pick;
    }
};
