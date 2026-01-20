class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> memo;
        int sum = 0;
        int count = 0;
        memo[0] = 1;
        for(int q: nums){
            sum += q;
            if(memo.find(sum-k) != memo.end()){
                count += memo[sum-k];
            }
            memo[sum]++;
        }
        return count;
    }
};
