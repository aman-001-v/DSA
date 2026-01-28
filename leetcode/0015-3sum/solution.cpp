class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int p1 = i + 1;
            int p2 = n - 1;
            int target = 0 - nums[i];
            while(p1 < p2){
                if(nums[p1] + nums[p2] == target){
                    result.push_back({nums[i] , nums[p1] , nums[p2]});
                    p1++;
                    p2--;
                    while(p1 < p2 && nums[p1] == nums[p1 -1]) p1++;
                    while(p1 < p2 && nums[p2] == nums[p2 +1]) p2--;
                }
                else if(nums[p1] + nums[p2] < target){
                    p1++;
                }
                else if(nums[p1] + nums[p2] > target){
                    p2--;
                }
            }
        }
        return result;
    }
};
