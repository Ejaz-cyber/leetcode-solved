class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string myStr = "";
        
        for(int i = 0; i<s.length(); i++){
            
            if(s[i] == ' ') continue;
            
            while(i<s.length() && s[i] != ' '){
                myStr+=s[i];
                i++;
            }
            // cout << myStr << endl;
            st.push(myStr);
            myStr = "";
        }
        
        string ans = "";
        while(st.empty() == false){
            ans+=st.top();
            st.pop();
            
            if(!st.empty()){
                ans+=' ';
            }
            
        }
        
        return ans;
    }
};