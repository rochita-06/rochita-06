class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
       int n=grid.size();
       vector<vector<int>> d(n,vector<int>(n,INT_MAX));
       queue<pair<int,int>> q;
       int dir[5]={1,0,-1,0,1};
       for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j]){
                d[i][j]=0;
                q.push({i,j});
            }
            while(!q.empty()){
                auto[x,y]=q.front();q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dir[k],ny=y+dir[k+1];
                    if(nx>=0&&ny>=0&&nx<n&&ny<n&&d[nx][ny]==INT_MAX){
                        d[nx][ny]=d[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
            auto check=[&](int s){
                if(d[0][0]<s) return false;
                vector<vector<int>> vis(n,vector<int> (n));
                queue<pair<int,int>> q;
                q.push({0,0});
                vis[0][0]=1;
                  
                while(!q.empty()){
                    auto[x,y]=q.front();q.pop();
                    if(x==n-1&&y==n-1) return true;
                    for(int k=0;k<4;k++){
                        int nx=x+dir[k],ny=y+dir[k+1];
                        if(nx>=0&&ny>=0&&nx<n&&ny<n&&!vis[nx][ny]&& d[nx][ny]>=s){
                            vis[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                } 
                return false; 
            };
            int l=0,r=2*n,ans=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(check(mid)){
                    ans=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            return ans;

    }
};