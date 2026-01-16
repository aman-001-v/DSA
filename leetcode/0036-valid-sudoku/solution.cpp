class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9));
        vector<vector<bool>> column(9,vector<bool>(9));
        vector<vector<bool>> box(9,vector<bool>(9));

        for(int i = 0; i< 9 ; i++){
            for(int j = 0; j< 9; j++){
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int boxindex = (i/3)*3 + (j/3);
                
                if(row[i][num] || column[j][num] || box[boxindex][num]) return false;

                row[i][num] = true;
                column[j][num] = true;
                box[boxindex][num] = true;
            }
        }
        return true;
    }
};
