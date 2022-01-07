// DFS solution

class Solution {
public:
    void dfs(int n,vector<vector<int>> &isConnected,int cur,int vis[])
    {
        vis[cur]=1;
        for(int i=0;i<n;i++)
        {
            if(isConnected[cur][i]==1 && i!=cur && vis[i]==0)
            {
                dfs(n,isConnected,i,vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        int n=isConnected.size();
        int vis[201]={0};
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(n,isConnected,i,vis);
                cnt++;
            }
        }
        return cnt;
    }
};




// DSU solution

class Solution {
public:
    int get(vector<int> &dsu,int cur)
    {
        return ((dsu[cur]==-1)?cur:(dsu[cur]=get(dsu,dsu[cur])));
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> dsu(n,-1);
        int group=n;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    int p1=get(dsu,i);
                    int p2=get(dsu,j);
                    if(p1!=p2)
                    {
                        group--;
                        dsu[p1]=p2;
                    }
                }
            }
        }
        return group;
    }
};