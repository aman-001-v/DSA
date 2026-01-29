class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int p1 = 0;
        int p2 = height.size() - 1;
        while(p1 < p2){
            if(height[p1] > height[p2]){
                max_area = max(max_area, height[p2]* (p2 - p1));
                p2--;
            }else{
                max_area = max(max_area, height[p1]* (p2 - p1));
                p1++;
            }
        }
        return max_area;
    }
};
