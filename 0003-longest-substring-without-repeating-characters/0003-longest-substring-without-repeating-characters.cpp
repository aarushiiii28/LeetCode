class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int l = 0, r = 0;

        vector<int> mpp(256, -1);
        int max_length = 0;

        while (r < n) {

           if(mpp[s[r]] != -1){
            if (mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }
           }
            max_length = max(max_length, r - l + 1);

        
            mpp[s[r]] = r;

            r++;
        }

        return max_length;
    }
};