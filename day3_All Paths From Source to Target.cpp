// DAG
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(vector<vector<int>>&gr,int cur,int dest)
    {
        if(cur==dest)
        {
            tmp.push_back(dest);
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(cur);
        for(auto it:gr[cur])
        {
                dfs(gr,it,dest); // don't have to maintain visited cause dag
        }
        tmp.pop_back();
        return ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        dfs(graph,0,n-1);
        return ans;
    }
};