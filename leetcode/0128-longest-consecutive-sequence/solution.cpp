class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 ) return 0;
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxC = 0;
        for(int i = 1; i< nums.size() ; i++){
            cout << nums[i] << endl;
            if(nums[i] == nums[i-1] + 1 ){
                
                count++;
            }
            else if(nums[i] == nums[i-1]) continue;
            else{
                if(maxC < count) maxC = count;
                count = 1;
            }
            
        }
        if(maxC < count) maxC = count;
        return maxC;
    }
};
