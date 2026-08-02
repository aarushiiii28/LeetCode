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

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long smallest = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            smallest += left * right * 1LL * arr[i];
        }

        return smallest;
    }

    vector<int> findNGE(vector<int>& arr) {
        stack<int> st;
        vector<int> nge(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGEE(vector<int>& arr) {
        stack<int> st;
        vector<int> pgee(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        long long largest = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;

            largest += left * right * 1LL * arr[i];
        }

        return largest;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};