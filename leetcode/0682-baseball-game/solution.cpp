class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> memo;
        for( string q: operations){
            if(q == "+"){
                int n = memo.size();
                int sum = memo[n-1] + memo[n-2];
                memo.push_back(sum);
            }
            else if(q == "D"){
                int n = memo.size();
                int Double = 2* memo[n-1];
                memo.push_back(Double);
            }
            else if( q== "C"){
                memo.pop_back();
            }
            else{
                int num = stoi(q);
                memo.push_back(num);
            }
        }
        int result = 0;
        for(int q: memo){
            result += q;
        }
        return result;
    }
};
