class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while(left < right && right - left + 1 > k){
            if(abs(arr[left] - x) <= abs(arr[right] - x)){
                right--;
            }
            else if(abs(arr[left] - x) > abs(arr[right] - x)){
                left++;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
