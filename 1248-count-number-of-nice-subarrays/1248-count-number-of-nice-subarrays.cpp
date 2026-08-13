class Solution {
public:

    int solve(vector<int>& nums, int k) {

        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        int cnt_odd = 0;

        while (r < n) {

            if (nums[r] % 2 == 1)
                cnt_odd++;

            while (cnt_odd > k) {

                if (nums[l] % 2 == 1)
                    cnt_odd--;

                l++;
            }

            cnt = cnt + (r - l + 1);

            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return solve(nums, k) - solve(nums, k - 1);
    }
};