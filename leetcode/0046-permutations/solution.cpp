class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            vector<vector<int>> result = {{}};
            return result;
        }
        int le = nums[nums.size() -1];
        nums.pop_back();
        vector<vector<int>> result = permute(nums);
        nums.push_back(le);
        int n = result[0].size();
        int m = result.size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j<n+1 ; j++){
                vector<int> temp = result[0];
                temp.insert((temp.begin()+j),le);
                result.push_back(temp);
            }
            result.erase(result.begin());
        }
        return result;
    }
};
