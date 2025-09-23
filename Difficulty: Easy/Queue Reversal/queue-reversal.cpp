class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int> temp;
        while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
    }
};