class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> rows(numRows--);
        bool flag = true;
        int count = 0;
        for(auto str:s){
            if(count==0){
                flag = true;
            }
            else if(count == numRows){
                flag = false;
            }
            string tempstr = rows[count];
            tempstr += str;
            rows[count] = tempstr;
            if(flag == true) count++;
            else if(flag == false) count--;
        }
        string output = "";
        for(auto str:rows){
            output+= str;
        }
        return output;
    }
};
