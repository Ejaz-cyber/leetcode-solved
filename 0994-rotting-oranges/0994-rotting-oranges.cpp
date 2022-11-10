class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int days = 0;   // min time to rotten all
        queue<pair<int, int>> rotten;
        int total = 0;  // total i have
        int count = 0;  // those i rottened
        int n = grid.size(), m = grid[0].size();
        
        // traversing grid - count initial rotten
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    pair<int, int> p(i, j);
                    rotten.push(p);
                }
                if(grid[i][j] != 0)
                    total++;
            }
        }
        
        // axis directions to move
                //  right left bottom top
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            count += k;
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                    
                // moving in allowed directions
                for(int i = 0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    
                    // movement not allowed
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                        continue;
                    
                    grid[nx][ny] = 2;   // make it rotten
                    rotten.push({nx, ny});
                    
                }
            }
            
            if(rotten.empty() == false) days++;
            
        }
        
        // if all are rottened then return days else -1
        return total == count ? days : -1;  
        
    }
};