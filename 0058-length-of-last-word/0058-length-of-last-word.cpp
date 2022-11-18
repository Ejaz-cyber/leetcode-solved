class Solution {
public:
    int lengthOfLastWord(string s) {
        
        string str = "";
        int cnt = 0;
        bool flag = false;
        
        int n = s.size(); 
        int i = n-1;
        // for(i; i>=0; i--){
           
        while(i>=0 && s[i] == ' ') i--;
        while(i>=0 && s[i] != ' '){
            cnt++;
            i--;
            
        }
        
        return cnt;
    }
};