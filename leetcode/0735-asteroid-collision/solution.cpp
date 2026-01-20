class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> space;
        space.push_back(asteroids[0]);
        for(int i = 1; i<n ;i++){
            if(space.empty()) space.push_back(asteroids[i]);
            else if(asteroids[i] * space.back() > 0){
                space.push_back(asteroids[i]);
            }
            else if(asteroids[i] > 0 && space.back() < 0){
                space.push_back(asteroids[i]);
            }
            else{
                if(abs(asteroids[i]) == abs(space.back())){
                    space.pop_back();
                    continue;
                }
                while(!space.empty() && abs(asteroids[i]) > abs(space.back()) && asteroids[i] * space.back() < 0){
                    space.pop_back();
                }
                if(space.empty()){
                    space.push_back(asteroids[i]);
                }
                else if(abs(asteroids[i]) == abs(space.back()) && asteroids[i] * space.back() < 0){
                    space.pop_back();
                }
                else if(asteroids[i] * space.back() > 0){
                space.push_back(asteroids[i]);
                }
                
            }

        }
        return space;
    }
}; 
