class Solution {
public:
    bool isOpen(char c){
        if(c == '(' || c == '{' || c == '[')
            return true;
    
        return false;
    }
    char check(char c){
        char res;
        switch(c){
            case ')' : res = '(';
                break;
            case '}' : res = '{';
                break;
            case ']' : res = '[';
                break;
                
        }
        return res;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            if(isOpen(s[i])){
                st.push(s[i]);
                
            }else{
                if(!st.empty() && (st.top() == check(s[i]))){
                    st.pop();
                }else
                    return false;
                
            }
        }
        
        if(st.empty()) return true;
        
        return false;
    }
};