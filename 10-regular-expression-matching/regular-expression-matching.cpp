class Solution {
public:
    string s,p;

    bool solve(int i, int j){
        if(j == p.size()){
            return i == s.size();
        }
        bool first_char_matched = false;

        if(i < s.size() && (s[i] == p[j] || p[j] == '.'))
            first_char_matched = true;

        if(j+1 < p.size() && p[j+1] == '*'){
            bool not_take = solve(i,j+2);
            bool take = first_char_matched && solve(i+1,j);
            return not_take || take;
        }
        return first_char_matched && solve(i+1,j+1);
    }
    
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        return solve(0,0);
    }
};