class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0;
        int l = 0;
        for(int q : weights){
            r += q;
            if(l < q) l = q;
        }
        int k = 0;
        int result = INT_MAX;
        while(l <= r){
            k = l + ((r-l)/2);
            int d = 0;
            int w = 0;
            for(int q: weights){
                if(w + q <= k) w += q;
                else{
                    d++;
                    w = q;
                }
            } 
            d++;
            if(d <= days && k < result) result = k;

            if(d <= days) r = k - 1;
            else l = k + 1;
        }
        return result;
    }
};
