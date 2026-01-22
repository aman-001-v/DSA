
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> memo;
        string content = "";
        for(int i = 0; i< path.length(); i++){
            if(path[i] == '/'){
                memo.push_back(content);
                content = "";
            }
            else{
                content += path[i];
            }
        }
        if(!content.empty()) memo.push_back(content);
        vector<string> answer;
        for(string q: memo){
            if(q == "" || q == "."){
                continue;
            }
            else if(q == ".."){
                if(!answer.empty()) answer.pop_back();
                
            }
            else{
                answer.push_back(q);
            }
        }
        string ans = "/";
        for(string q: answer){
            ans += q;
            ans += "/";
        }
        if(ans.size() > 1) ans.pop_back();
        return ans;
    }
};
