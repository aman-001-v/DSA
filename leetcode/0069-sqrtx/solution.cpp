class Solution {
public:
    int mySqrt(int x) {
        int h = 0;
        int t = x;
        while(h <= t){
            long mid = h + ((t - h)/2);
            if(mid * mid == x) return mid;
            else if(mid * mid < x) h = mid + 1;
            else if(mid * mid > x) t = mid - 1;
        }
        return t;
    }
};
