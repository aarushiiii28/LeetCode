class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        int cnt_odd = 0;
        int prefix = 0;

        while (r < n) {

            if (nums[r] % 2 == 1) {
                cnt_odd++;
                prefix = 0;
            }

            while (cnt_odd == k) {

                prefix++;

                if (nums[l] % 2 == 1)
                    cnt_odd--;

                l++;
            }

            cnt += prefix;

            r++;
        }

        return cnt;
    }
};