class Solution {
public:
    using ll = long long;

    void FloydWarshall(vector<vector<ll>> &grid){
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& orig, vector<char>& changed, vector<int>& cost) {
        int n = orig.size();
        vector<vector<ll>> grid(26,vector<ll> (26,INT_MAX));

        for(int i=0;i<n;i++){
            int s = orig[i]-'a';
            int t = changed[i]-'a';
            grid[s][t] = min(grid[s][t], (ll)cost[i]);
        }
        FloydWarshall(grid);

        ll res = 0;
        for(int i=0;i<source.size();i++){
            if(source[i] == target[i]) continue;
            if(grid[source[i]-'a'][target[i]-'a'] == INT_MAX) return -1;
            res += grid[source[i]-'a'][target[i]-'a'];
        }
        return res;
    }
};