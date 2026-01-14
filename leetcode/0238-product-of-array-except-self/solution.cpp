class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int n = nums.size();
        answer.resize(n);
        int pre = 1;
        for(int i = 0; i < n ; i++){
            answer[i] = pre;
            pre *= nums[i];
        }
        int post = nums[n-1];
        for(int i = n-2; i>=0;i--){
            answer[i] = answer[i] * post;
            post *= nums[i];
        }
        return answer;
    }
};
