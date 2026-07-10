class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int d, vector<vector<int>>& q) {
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++) a[i] = {nums[i], i};
        sort(a.begin(), a.end());

        vector<int> pos(n), comp(n), nxt(n);
        for(int i = 0; i < n; i++) pos[a[i].second] = i;

        int id = 0;
        for(int i = 1; i < n; i++) {
            if(a[i].first - a[i-1].first > d) id++;
            comp[i] = id;
        }

        int r = 0;
        for(int i = 0; i < n; i++) {
            while(r + 1 < n && a[r + 1].first - a[i].first <= d) r++;
            nxt[i] = r;
        }

        const int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for(int k = 1; k < LOG; k++)
            for(int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        vector<int> ans;

        for(auto &v : q) {
            int l = pos[v[0]], rr = pos[v[1]];
            if(l > rr) swap(l, rr);

            if(l == rr) {
                ans.push_back(0);
                continue;
            }

            if(comp[l] != comp[rr]) {
                ans.push_back(-1);
                continue;
            }

            int cur = l, res = 0;
            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < rr) {
                    cur = up[k][cur];
                    res += 1 << k;
                }
            }

            ans.push_back(res + 1);
        }

        return ans;
    }
};