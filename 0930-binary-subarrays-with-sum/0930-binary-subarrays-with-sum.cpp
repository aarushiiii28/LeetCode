class Solution {
public:

    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int n = nums.size();
        int l = 0, sum = 0, cnt = 0;

        for (int r = 0; r < n; r++) {

            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1);
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};