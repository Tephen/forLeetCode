class Solution {
    vector<string> result;
    // unordered_map<出发机场, map<到达机场, 航班次数>>
    unordered_map<string,map<string,int>> itinerarys;
    //因为只需要找到满足条件的一条路径，故使用带返回值的遍历回溯函数便于快速返回
    bool backTrack(vector<vector<string>> tickets){
        if(result.size()==tickets.size()+1){
            return true;
        }
        //result.back()获取当前轮的出发机场
        //pair迭代所有以当前出发机场为起点的机票
        for(pair<const string,int>& itinerary:itinerarys[result.back()]){
            if(itinerary.second>0){
                result.push_back(itinerary.first);
                //防止重复使用机票造成死循环
                itinerary.second--;
                if(backTrack(tickets)) return true;
                result.pop_back();
                itinerary.second++;
            }
        }
        //for循环结束后仍未返回表明此种组合无法成功，return false
        return false;
    }
public:

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const vector<string>& ticket:tickets){
            itinerarys[ticket[0]][ticket[1]]++;
        }
        result.push_back("JFK");
        backTrack(tickets);
        return result;
    }
};