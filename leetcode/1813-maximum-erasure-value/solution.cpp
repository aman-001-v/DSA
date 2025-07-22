class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0;
        int sum = 0;
        set <int> check;
        int j = 0;
        for (int i =0 ; i< nums.size() ; i++){
            
            if (check.find(nums[i]) == check.end()){
                sum += nums[i];
                check.insert(nums[i]);
            }
            else{
                if(sum > maxSum) maxSum = sum;
                while(nums[j] != nums[i]){
                    sum -= nums[j];
                    check.erase(nums[j]);
                    j++;
                }
                j++;
            }
        }
    if(sum > maxSum) maxSum = sum;
    return maxSum;
    }
};
