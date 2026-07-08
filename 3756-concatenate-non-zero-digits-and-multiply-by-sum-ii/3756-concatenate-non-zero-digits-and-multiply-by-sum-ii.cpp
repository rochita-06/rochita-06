class Solution {
public:
 static const int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos,preSum(1),preVal(1),p10(1,1);
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                pos.push_back(i);
                int d=s[i]-'0';
                preSum.push_back(preSum.back()+d);
                preVal.push_back((preVal.back()*10LL+d)%MOD);
                p10.push_back(p10.back()*10LL%MOD);

            }
        }
        vector<int> ans;
        for(auto &q : queries){
            int l=lower_bound(pos.begin(),pos.end(),q[0])-pos.begin();
            int r=upper_bound(pos.begin(),pos.end(),q[1])-pos.begin()-1;
            if(l>r){
                ans.push_back(0);
                continue;
            }
            long long x=(preVal[r+1]-1LL*preVal[l]*p10[r-l+1])%MOD;
            if(x<0) x+=MOD;
            ans.push_back(x*(preSum[r+1]-preSum[l])%MOD);
        }
        return ans;
    }
};