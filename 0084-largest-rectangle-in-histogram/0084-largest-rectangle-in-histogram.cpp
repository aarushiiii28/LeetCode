class Solution {
    vector<int> findNSE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));

        return ans;
    }
};