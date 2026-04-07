class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 0;
        for(int i = 0; i< piles.size(); i++){
            if(r < piles[i]) r = piles[i];
        }
        int result = INT_MAX;
        int l = 1;
        int k = 0;
        while(l <= r){
            k = l + ((r-l)/2);
            //cout << k << " ";
            long t = 0;
            for(int i = 0; i< piles.size(); i++){
                if (piles[i] % k == 0) t += piles[i]/k;
                else t += (piles[i]/k) + 1;
            }
            //cout << "t" << t << " ";
            if(k < result && t <= h){
                result = k;
            }
            if(t <= h){
                r = k - 1;
            }else{
                l = k + 1;
            }
        }
        return result;
    }
};
