class Solution {
  public:
    bool isNumber(string s) {
        try {
            int val = stoi(s);
            return (val >= -10000 && val <= 10000);
        } catch (invalid_argument& e) {
            return false;
        } catch (out_of_range& e) {
            return false;
        }
    }
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        int op1, op2;
        for(string ch : arr) {
            if(isNumber(ch)) st.push(stoi(ch));
            else if(st.size() >= 2){
               
                    op2 = st.top();
                    st.pop();
                    op1 = st.top();
                    st.pop();
                    if(ch == "+") st.push(op1 + op2);
                    else if(ch == "-") st.push(op1 - op2);
                    else if(ch == "*") st.push(op1 * op2);
                    else if(ch == "/") {
                        if((op1 < 0) != (op2 < 0) && op1 % op2 != 0) {
                            st.push((op1 / op2) - 1);
                        }
                        else st.push(op1 / op2);
                    }
                    else st.push(pow(op1, op2));
                
            }
        }
        return st.top();
    }
};