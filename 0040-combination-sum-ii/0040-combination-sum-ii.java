class Solution {
    
    public void fun(List<List<Integer>> ans, List<Integer> out,
                    int[] arr,int target, int index){
        
        if(target == 0){
            ans.add(new ArrayList<>(out));
            return;
        }
        
        for(int i = index; i < arr.length; i++){
            
            if(i>index && arr[i] == arr[i-1]) continue;
            
            if(arr[i] > target)
                break;
            
            out.add(arr[i]);
            
            fun(ans, out, arr, target-arr[i] , i+1);
            int r = out.size() - 1;
            out.remove(r);
        }
        
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> out = new ArrayList<>();
        
        Arrays.sort(candidates);
        
        fun(ans, out, candidates, target, 0);
        
        return ans;
    }
}