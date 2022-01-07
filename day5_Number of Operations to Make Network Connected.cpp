// DSU with path compression
class Solution {
public:
    int get_parent(vector<int> &dsu,int cur)
    {
        return ((dsu[cur]==-1)?cur:(dsu[cur]=get_parent(dsu,dsu[cur])));   // path compression 
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<int> dsu(n,-1);
        int cnt=0;
        for(auto con:connections)
        {
            int p1=get_parent(dsu,con[0]);
            int p2=get_parent(dsu,con[1]);
            if(p1!=p2)
            {
                dsu[p1]=p2;
                cnt++;
            }
        }
        return n-cnt-1;
    }
};