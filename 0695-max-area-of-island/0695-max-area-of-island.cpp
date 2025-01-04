class Solution {
private:
    int getArea(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        
        int lft = getArea(grid, i, j-1, n, m);
        int ryt = getArea(grid, i, j+1, n, m);
        int up = getArea(grid, i-1, j, n, m);
        int down = getArea(grid, i+1, j, n, m);
        
        return up + down + lft + ryt + 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = getArea(grid, i, j, n, m);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};