/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> mp;
    void dfs(Node* cur,Node* copycur)
    {
        mp[cur->val]=copycur;
        for(auto nbr:(cur->neighbors))
        {
            if(mp[nbr->val]==NULL)
            {
                Node* tmp=new Node(nbr->val);
                (copycur->neighbors).push_back(tmp);
                dfs(nbr,tmp);
            }
            else
                (copycur->neighbors).push_back(mp[nbr->val]);        
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        for(int i=1;i<=100;i++)
            mp[i]=NULL;
        Node* root= new Node(node->val);
        mp[node->val]=root;
        for(auto it:(node->neighbors))
        {
            if(mp[it->val]==NULL)
            {
                Node* tmp= new Node(it->val);
                (root->neighbors).push_back(tmp);
                dfs(it,tmp);
            }
            else
                (root->neighbors).push_back(mp[it->val]);  
        }
        return root;
    }
};