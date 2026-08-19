class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int cnt5 = 0;
        int cnt10 = 0;

        for(int i = 0; i<n; i++){

            if(bills[i] == 5) cnt5++;
            if(bills[i] == 10) {
                cnt10++;
                if(cnt5 != 0){
                    cnt5--;
                }
                else{
                    return false;
                }
            }
            if(bills[i] == 20){

                if(cnt5 > 0 && cnt10 > 0){
                    cnt5--;
                    cnt10--;
                }
                else if(cnt5 >= 3){
                    cnt5 = cnt5 - 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }

};