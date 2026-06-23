class Solution {
public:
    bool solve(string& s, int i, int j){
        if(i>j){
            return true;
        }
        if(s[i]==s[j]){
            return solve(s, i+1, j-1);
        }else{
            return false;
        }
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(solve(s, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};
