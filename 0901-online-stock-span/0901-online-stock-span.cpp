class StockSpanner {
public:
    stack<pair<int,int>> st;   // {price, span}

    StockSpanner() {

    }

    int next(int price) {

        int span = 1;

        // Remove all smaller or equal previous prices
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price with its span
        st.push({price, span});

        return span;
    }
};