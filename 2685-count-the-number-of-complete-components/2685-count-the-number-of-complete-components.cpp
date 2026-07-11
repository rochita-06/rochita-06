class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> vis(n);
        int ans=0;
        function<void(int)> dfs=[&](int u){
            vis[u]=1;
            nodes++;
            deg+=g[u].size();
            for(int v:g[u])
                if(!vis[v]) dfs(v);
        };
        for(int i=0;i<n;i++){
            if(!vis[i]){
                nodes=deg=0;
                dfs(i);
                if(deg==nodes*(nodes-1))
                    ans++;
            }
        }
        return ans;
    }
    private:
        int nodes,deg;
};