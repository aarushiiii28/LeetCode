class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int max_fruits = 0;

        unordered_map<int,int> mpp;

        while(r<n){

            if(mpp.size() <= 2)
                mpp[fruits[r]]++;

            while(mpp.size() > 2){
                mpp[fruits[l]]--;

                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            
            max_fruits = max(max_fruits, r - l + 1);
            r++;
        }
    return max_fruits;
    }
};