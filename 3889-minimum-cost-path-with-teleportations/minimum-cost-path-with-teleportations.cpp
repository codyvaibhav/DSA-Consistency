class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int maxVal = -1;
        vector<vector<int>> dp(n, vector<int> (m,INT_MAX));
        dp[n-1][m-1] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) maxVal = max(maxVal,grid[i][j]);
        }
        vector<int> telep(maxVal + 1,INT_MAX);
        for(int t=0;t<=k;t++){
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(i==n-1 && j==m-1) continue;
                    if(i + 1 < n){
                        dp[i][j] = min(dp[i][j], grid[i+1][j] + dp[i+1][j]);
                    }
                    if(j + 1 < m){
                        dp[i][j] = min(dp[i][j], grid[i][j+1] + dp[i][j+1]);
                    }
                    if(t > 0){
                        dp[i][j] = min(dp[i][j], telep[grid[i][j]]);
                    }
                }
            }
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    int val = grid[i][j];
                    telep[val] = min(telep[val],dp[i][j]);
                }
            }
            for(int i=1;i<telep.size();i++){
                telep[i] = min(telep[i],telep[i-1]);
            }
        }
        return dp[0][0];
    }
};
//dp[i][j][k] -> layered dp