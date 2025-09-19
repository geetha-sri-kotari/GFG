class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int close_cnt = 0;
        stack<char> st;
        for(char ch : s) {
            if(ch == '(') st.push(ch);
            else if(ch == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else close_cnt++;
            }
        }
        int start_cnt = 0;
        while(!st.empty()) {
            st.pop();
            start_cnt++;
        }
        return start_cnt + close_cnt;
    }
};