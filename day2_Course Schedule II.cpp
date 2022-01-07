class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int indegree[numCourses];
        for(int i=0;i<numCourses;i++)
            indegree[i]=0;
        vector<int> gr[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            gr[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<prerequisites.size();i++)
            indegree[prerequisites[i][0]]++;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0)
                q.push(i);
        int count=0;
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            ans.push_back(fr);
            count++;
            for(auto it:gr[fr])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(count==numCourses)
            return ans;
        else
            return {};
    }
};