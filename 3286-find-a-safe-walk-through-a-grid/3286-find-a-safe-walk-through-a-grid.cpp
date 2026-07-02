class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> best(m,vector<int>(n,-1));
        int startHealth =health-grid[0][0];
        if(startHealth<=0) return false;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},startHealth});
        best[0][0]=startHealth;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int x=cur.first.first;
            int y=cur.first.second;
            int h=cur.second;
            if(x==m-1&&y==n-1)
                return true;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
            if(nx<0||ny<0||nx>=m||ny>=n)
                continue;
            int nh=h-grid[nx][ny];
            if(nh>0&&nh>best[nx][ny]){
                best[nx][ny]=nh;
                q.push({{nx,ny},nh});
            }    

        }
        }
   return false; }
};