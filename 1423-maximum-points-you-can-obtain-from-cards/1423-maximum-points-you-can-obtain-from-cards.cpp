class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        int sum = 0;

        for(int i = 0; i < k; i++){
            lsum = lsum + cardPoints[i];
        }
            sum = lsum;
        

        int r_index = n-1;
        for(int i = k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[r_index];
            r_index--;

            sum = max(sum, lsum+rsum);
        }
        
        return sum;
    }
};