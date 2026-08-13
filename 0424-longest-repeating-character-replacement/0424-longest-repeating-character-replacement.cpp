class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        vector<int> mpp(26, 0);
        int l = 0, r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        int len=1;

        while(r<n){

            mpp[s[r]- 'A']++;

            len = r - l + 1;
            maxfreq = max(maxfreq, mpp[s[r] - 'A']);

            while((len - maxfreq) > k){
                
                mpp[s[l] - 'A']--;
                l++;

                len--;
            }

            maxlen = max(maxlen, len);

            r++;

        }
    return maxlen;
    }
};