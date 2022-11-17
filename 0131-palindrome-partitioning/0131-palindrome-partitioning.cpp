class Solution {
public:
    bool isPalindrome(string str, int s, int e){
        while(s < e){
            if(str[s] != str[e]) return false;
            s++;
            e--;
        }
        
        return true; 
    }
    void fun(int ind, string s, vector<string> path,
             vector<vector<string>> & res){
        if(ind == s.length()){
            res.push_back(path);
            return;
        }
        
        for(int i = ind; i<s.size(); ++i){
            if(isPalindrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                fun(i+1, s, path, res);
                
                path.pop_back();
            }
        }
        
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        
        fun(0, s, path, res);
        
        return res;
        
    }
};