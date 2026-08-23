class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 1;
        sort(intervals.begin(), intervals.end(), comp);

        if(n==0 || n==1){
            return 0;
        }

        int lastEndTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= lastEndTime){
                count++;
                lastEndTime = intervals[i][1];
            }
        }
        return n - count;
    }

    static bool comp(vector<int>& val1, vector<int>& val2) {
    return val1[1] < val2[1];
    }
};