class NumMatrix {
public:
    vector<vector<int>> memo;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memo.resize(n,vector<int>(m));
        memo[0][0] = matrix[0][0];
        for(int i = 1; i< n;i++){
            memo[i][0] = matrix[i][0] + memo[i-1][0];
        }
        for(int j = 1; j< m ; j++){
            memo[0][j] = matrix[0][j] + memo[0][j-1];
        }
        for(int i = 1; i<n; i++){
            for(int j = 1; j < m ; j++){
                int n1 = matrix[i][j] , n2 = memo[i][j-1] , n3 = memo[i-1][j] , n4 = memo[i-1][j-1];
                memo[i][j] = n1 + n2 + n3 - n4;              
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int n1 = memo[row2][col2];
        int n2 , n3 , n4;
        if(row1 == 0){
            n2 = 0;
        }else{
            n2 = memo[row1 - 1][col2];
        }
        if(col1 == 0){
            n3 = 0;
        }else{
            n3 = memo[row2][col1 -1];
        }
        if(row1 != 0 && col1 != 0){
            n4 = memo[row1 - 1][col1 -1];
            
        }else{
            n4 = 0;
        }
        return n1 + n4 - n2 - n3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
