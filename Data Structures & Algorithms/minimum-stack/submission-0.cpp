class MinStack {
private:
    stack<pair<int, int>> st;
    int min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            min = val;
        }
        else {
            if (min > val) min = val;
            st.push({val, min});
        }
    }
    
    void pop() {
        st.pop();
        if (!st.empty()) min = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
