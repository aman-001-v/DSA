class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0 , count2 = 0 , cand1 =0 , cand2 = 0;

        for (int n: nums){
            if(count1> 0 && n== cand1) {
                count1++;
            }
            else if(count2 > 0 && n == cand2){
                count2++;
            }
            else if(count1 == 0){
                count1 = 1;
                cand1 = n;
            }
            else if(count2 == 0){
                count2 = 1;
                cand2 = n;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int n: nums){
            if(n == cand1) count1++;
            else if(n== cand2) count2++;
        }

        int n = nums.size();
        vector <int> result;
        if(count1 > n/3) result.push_back(cand1);
        if(count2 > n/3) result.push_back(cand2);
        return result;
    }
};
