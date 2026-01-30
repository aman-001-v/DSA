class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = height.size() - 1;
        int maxL = height[0];
        int maxR = height[n - 1];
        int total_area = 0;
        while(left < right){
            if(height[left] > height[right]){
                maxR = max(maxR, height[right]);
                maxL = max(maxL, height[left]);
                right--;
                int area = min(maxL, maxR) - height[right];
                if(area > 0) total_area += area;
            }else{
                maxL = max(maxL, height[left]);
                maxR = max(maxR, height[right]);
                left++;
                int area = min(maxL, maxR) - height[left];
                if(area > 0 ) total_area += area;
            }
        }
        return total_area;
    }
};
