class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;
        // if(n == 1 & m == 1){
        //     if(matrix[0][0] == target) return true;
        //     else return false;
        // }
        int l = 0;
        int r = n;
        int mid = 0;
        while(l <= r){
            mid = l + ((r-l)/2);
            if(target == matrix[mid][0] || target == matrix[mid][m]) return true;
            else if(target < matrix[mid][0]) r = mid - 1;
            else if(target > matrix[mid][0] && target > matrix[mid][m]) l = mid + 1;
            else break;
        }
        l = 0;
        n = mid;
        r = m;
        while(l <= r){
            mid = l + ((r-l)/2);
            if(target == matrix[n][mid]) return true;
            else if(target < matrix[n][mid]) r = mid - 1;
            else l = mid + 1;
        }
        if(matrix[n][mid] == target) return true;
        return false;
    }
};
