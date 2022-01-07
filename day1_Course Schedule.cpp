// directed graph cycle detection using graph coloring
// 0=untracked  1=processing 2=processed
class Solution {
public:
    int color[100010];
    vector<int> gr[100010];
    bool go(int cur)
    {
        if(color[cur]==1)
            return true;
        color[cur]=1;
        for(auto it:gr[cur])
        {
            if(color[it]!=2)
              if(go(it))
                  return true;
        }
        color[cur]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<prerequisites.size();i++)
            gr[prerequisites[i][0]].push_back(prerequisites[i][1]);
        memset(color,0,sizeof(color));
        for(int i=0;i<numCourses;i++)
        {
            if(color[i]==0)
                if(go(i))
                    return false;
        }
        return true;
    }
};