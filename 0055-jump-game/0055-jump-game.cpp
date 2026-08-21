class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return true;
        }

        if(nums[0] == 0) return false;

        for(int i = 0; i < n - 1; ) {

            if(nums[i] >= n - i - 1) {
                return true;
            }

            int j = i + 1;
            int maxi = -1;
            int maxiIndex = i;

            while(j <= i + nums[i] && j < n) {
                if(j + nums[j] > maxi) {
                    maxi = j + nums[j];
                    maxiIndex = j;
                }
                j++;
            }

            if(maxiIndex == i) {
                return false;
            }

            i = maxiIndex;
        }

        return false;
    }
};