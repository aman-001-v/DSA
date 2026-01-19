class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> memo;
        for(const auto q: nums){
            memo.insert(q);
        }
        cout << "nuaugf" << endl;
        int longest = 0;
        for(const auto q: memo){
            if(memo.find(q-1) == memo.end()){
                int length = 0;
                while(memo.find(q + length) != memo.end()){
                    length++;
                } 
                if(length > longest) longest = length;
            }
        }
        return longest;
    }
};
