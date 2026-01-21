class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map <int, double> memo;
        for(int i = 0 ; i < n; i++){
            memo[position[i]] = (float)(target - position[i]) / speed[i];
        }
        sort(position.begin(), position.end());
        stack <int> st;
        int fleet = 0;
        for(int i = n-1; i >= 0; i--){
            if(st.empty()) st.push(position[i]);
            else if(!st.empty() && memo[position[i]]>memo[st.top()]){
                fleet++;
                while(!st.empty()){
                    st.pop();
                }
                st.push(position[i]);
            }
            else{
                memo[position[i]] = memo[st.top()];
                st.push(position[i]);
            }
        }
        return fleet+1;
    }
};
