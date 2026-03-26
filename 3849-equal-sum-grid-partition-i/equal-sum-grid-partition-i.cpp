class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<ll> colSum(n,0);
        vector<ll> rowSum(m,0);
        ll total = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total += grid[i][j];
                colSum[i] += grid[i][j];
                rowSum[j] += grid[i][j];
            }
        }
        if(total % 2 != 0) return false;

        ll upper = 0;
        for(int j=0;j<m-1;j++){
            upper += rowSum[j];
            if(upper == total - upper) return true;
        }

        ll left = 0;
        for(int i=0;i<n-1;i++){
            left += colSum[i];
            if(left == total - left) return true;
        }
        return false;
    }
};