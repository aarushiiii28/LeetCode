class Solution {

    vector<int> findNSE(vector<int>& arr) {
        stack<int> st;
        vector<int> nse(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr) {
        stack<int> st;
        vector<int> psee(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        const int mod = 1e9 + 7;
        long long total = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long left = i - psee[i];
            long long right = nse[i] - i;

            total = (total + (left * right % mod) * arr[i]) % mod;
        }

        return total;
    }
};