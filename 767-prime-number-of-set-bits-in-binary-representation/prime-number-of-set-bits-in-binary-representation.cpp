class Solution {
public:
    vector<bool> getPrimes(int n){
        vector<bool> primes(n+1,true);
        primes[1] = false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i) primes[j] = false;
            }
        }
        return primes;
    }
    int countPrimeSetBits(int left, int right) {
        vector<bool> primes = getPrimes(32);
        int ans = 0;
        for(int i=left;i<=right;i++){
            int setBits = __builtin_popcount(i);
            if(primes[setBits]) ans++;
        }
        return ans;
    }
};