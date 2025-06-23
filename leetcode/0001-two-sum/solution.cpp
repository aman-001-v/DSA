class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            int value = nums[i];
            if(mp[target - value] != 0 ){
                output.push_back(i);
                output.push_back(mp[target-value]-1);
                break;
            }
            else{
                mp[value]= i+1;
            }
        }
        return output;
    }
    
};
