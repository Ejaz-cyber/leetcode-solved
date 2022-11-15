class Solution {
public:
    /*
    n = 1 k = 1     0
    n = 2 k = 2     0 1
    n = 3 k = 4     0 1 1 0
    n = 4 k = 8     0 1 1 0 1 0 0 1
    
    */
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }
        
        int mid = pow(2, n-1) / 2;  // length / 2
        
        if(k <= mid){
            return kthGrammar(n-1, k);
        }else{
            // mid ke baad sara complement hai 
            return !kthGrammar(n-1, k-mid);
        }
        
    }
};