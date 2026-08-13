class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        unordered_map<char, int> mpp;
        int l = 0, r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        int len=1;

        while(r<n){

            mpp[s[r]]++;

            len = r - l + 1;
            maxfreq = max(maxfreq, mpp[s[r]]);

            while((len - maxfreq) > k){
                
                mpp[s[l]]--;
                l++;

                len--;
            }

            maxlen = max(maxlen, len);

            r++;

        }
    return maxlen;
    }
};