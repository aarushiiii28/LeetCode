class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        int count = 0;
        int l=0, r=0;

        while(r<n){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;

                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            
            count += r-l+1;

            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};