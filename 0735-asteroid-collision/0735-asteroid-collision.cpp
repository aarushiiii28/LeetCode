class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int>st;
        int n = asteroids.size();

        for(int i = 0; i<n; i++){
            if(asteroids[i] >= 0) {
                st.push(asteroids[i]);
            }
            else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                      st.pop();
                    }
                    if(st.empty() || st.top() < 0){
                        st.push(asteroids[i]);
                    }
                    else if (st.top() == abs(asteroids[i])) {
                    st.pop();
                    }
                
                
            }
        }
int n1 = st.size();
vector<int> arr(n1);

for (int i = n1 - 1; i >= 0; i--) {
    arr[i] = st.top();
    st.pop();
}
return arr;

    }
};