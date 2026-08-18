class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int l = 0, r = 0;

        int minlen = INT_MAX;
        int cnt = 0;
        int sIndex = -1;

        int m = t.size();
        int n = s.size();

        for(int i = 0; i<m; i++){
            hash[t[i]]++;
        }

        while(r<n){
            if(hash[s[r]] > 0) cnt++;

            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;

                if(hash[s[l]] > 0) cnt--;

                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};