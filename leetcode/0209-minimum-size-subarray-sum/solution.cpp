class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int minLen = 0;
        while( r <= n){
            if(r<n) sum += nums[r];
            while(sum >= target){
                if(minLen == 0) minLen = r-l + 1;
                else minLen = min(minLen , r-l + 1) ;
                sum -= nums[l];
                l++;
                
            }
            r++;
        }
        return minLen;
    }
};
