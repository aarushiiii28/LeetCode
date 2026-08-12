class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int l = 0;
        int r = 0;

        unordered_map<char, int> mpp;
        int max_length = 0;
        int length;

        while(r<n){

            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                l = mpp[s[r]] + 1;
            }

            length = r - l + 1;
            max_length = max(max_length, length);

            mpp[s[r]] = r;
            r++;
        }
    return max_length;
    }
};