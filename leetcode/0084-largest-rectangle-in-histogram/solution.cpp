class Solution {
    stack<pair<int,int>> memo;
    int max_area = 0;
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        for(int i = 0; i< n; i++){
            if(memo.empty()){
                memo.push({heights[i],0});
                continue;
            }else{
                pair<int,int> t = memo.top();
                int count = 0;
                if(t.first > heights[i]){
                    while(!memo.empty() && t.first > heights[i]){
                        int width = i - t.second;
                        //cout << width << " " << t.second << " " << t.first << endl;
                        int area = t.first*width;
                        max_area = max(max_area,area);
                        count = memo.top().second;
                        memo.pop();
                        //count += width;
                        if(!memo.empty()) t = memo.top();
                    }
                if(!memo.empty()) memo.push({heights[i],count});
                else memo.push({heights[i],0});
                    
                }else{
                    //cout << i << " ajfuirga " << heights[i]<<endl;
                    memo.push({heights[i],i});
                }

            }
        }
        int num = n;
        while(!memo.empty()){
            int width = num - (memo.top()).second;
            int area = (memo.top()).first * width;
            cout << area << "fahsu" << (memo.top()).second << endl;
            max_area = max(max_area, area);
            memo.pop();
        }
        return max_area;
    }
};
