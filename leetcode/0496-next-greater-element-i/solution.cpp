class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> memo;
        for(int i = 0; i< nums1.size(); i++){
            memo[nums1[i]] = i;
            nums1[i] = -1;
        }
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            if(memo.find(nums2[i]) != memo.end()){
                if(!st.empty()) nums1[memo[nums2[i]]] = st.top();
            }
            st.push(nums2[i]);
        }
        return nums1;
    }
};
