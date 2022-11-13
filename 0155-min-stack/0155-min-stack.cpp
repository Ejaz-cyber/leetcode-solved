class MinStack {
public:
    stack<int> s;
    stack<int> hs;  // helper stack
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        
        if(hs.empty() || hs.top() >= val){  // new min
            hs.push(val);
        }
        
        return;
    }
    
    void pop() {
        if(hs.size() == 0)
            return ;
        
        if(hs.top() == s.top()){
            hs.pop();
        }
        s.pop();
    }
    
    int top() {
        
        return s.top();
        
    }
    
    int getMin() {
        if(hs.size() == 0)
            return -1;
        else return hs.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */