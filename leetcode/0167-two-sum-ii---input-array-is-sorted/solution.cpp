class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size() - 1;
        while(true){
            if(numbers[p1] + numbers[p2] == target){
                if(p1 < p2) return {p1 + 1 , p2 + 1};
                else return {p2 + 1, p1 + 1};
            }
            else if(numbers[p1] + numbers[p2] > target){
                if(p2 > 0) p2--;
            }
            else if(numbers[p1] + numbers[p2] < target){
                if(p1 < numbers.size() - 1) p1++;
            }
        }
        return {0,0};
    }
};
