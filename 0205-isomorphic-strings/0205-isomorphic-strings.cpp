class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n = s.size();

        for (int i = 0; i < n; i++) {

            // Check previous occurrences of s[i]
            for (int j = 0; j < i; j++) {
                if (s[j] == s[i] && t[j] != t[i])
                    return false;
            }

            // Check previous occurrences of t[i]
            for (int j = 0; j < i; j++) {
                if (t[j] == t[i] && s[j] != s[i])
                    return false;
            }
        }

        return true;
    }
};