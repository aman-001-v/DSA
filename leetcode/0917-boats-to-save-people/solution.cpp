class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count = 0;
        int p1 = 0;
        int p2 = people.size() - 1;
        while(p1 <= p2){
            if(p1 < p2 && limit - people[p2]  < people[p1]){
                count++;
                p2--;
            }
            else if(people[p1] + people[p2] <= limit){
                count++;
                p2--;
                p1++;
            }
            else{
                count++;
                p2--;
            }
        }
        return count;
    }
}; 
