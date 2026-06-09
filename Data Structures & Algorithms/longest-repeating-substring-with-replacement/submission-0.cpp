class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left=0;
        int maxFrequency=0;
        int maxLength=0;
        for(int right=0; right< s.length(); right++){
            count[s[right]]++;
            maxFrequency= max(maxFrequency, count[s[right]]);

            while((right-left+1- maxFrequency > k)){
                count[s[left]]--;
                left++;
            }
            maxLength= max(maxLength, right-left+1);
        }
        return maxLength;
    }
};
