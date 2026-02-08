class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - k;
        
        // Binary search for the best starting index of window size k
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Compare distance from x to arr[mid] and arr[mid + k]
            if (x - arr[mid] > arr[mid + k] - x) {
                // Better window is on the right
                left = mid + 1;
            } else {
                // Better window is on the left or current
                right = mid;
            }
        }
        
        // left is the best starting index
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

