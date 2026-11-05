class Solution {
public:

    void dfs(string word, string beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& ans) {

        if(word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for(string p : parent[word]) {
            path.push_back(p);

            dfs(p, beginWord, parent, path, ans);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        if(!st.count(endWord)) return ans;

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, vector<string>> parent;

        bool found = false;

        while(!q.empty() && !found) {

            int sz = q.size();
            unordered_set<string> used;

            for(int i = 0; i < sz; i++) {

                string word = q.front();
                q.pop();

                string temp = word;

                for(int j = 0; j < word.size(); j++) {

                    char original = word[j];

                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        word[j] = ch;

                        if(st.count(word)) {

                            if(word == endWord)
                                found = true;

                            if(!used.count(word)) {
                                used.insert(word);
                                q.push(word);
                            }

                            parent[word].push_back(temp);
                        }
                    }

                    word[j] = original;
                }
            }

            for(string w : used)
                st.erase(w);
        }

        if(found) {
            vector<string> path;
            path.push_back(endWord);

            dfs(endWord, beginWord, parent, path, ans);
        }

        return ans;
    }
};