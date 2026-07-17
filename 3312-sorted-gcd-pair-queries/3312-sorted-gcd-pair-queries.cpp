class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;
        vector<long long> divCnt(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                divCnt[g] += freq[j];
        }
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long pairs = divCnt[g] * (divCnt[g] - 1) / 2;

            for (int j = 2 * g; j <= mx; j += g)
                pairs -= exact[j];

            exact[g] = pairs;
        }

    
        vector<long long> pref(mx + 1, 0);

        for (int g = 1; g <= mx; g++)
            pref[g] = pref[g - 1] + exact[g];

        vector<int> ans;

        for (long long k : queries) {
            int g = lower_bound(pref.begin(), pref.end(), k + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};