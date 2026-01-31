class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        int minDiff = 26;
        for(int i=0;i<letters.size();i++){
            int diff = letters[i] - target;
            if(diff > 0 && diff < minDiff){
                ans = letters[i];
                minDiff = diff;
            }
        }
        return ans;
    }
};