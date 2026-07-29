class Solution {
private:
    long long comb(long long n, long long r, long long limit) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long res = 1;
        for (long long i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res > limit)
                return limit + 1;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int partition = n / 2;

        vector<int> bucket(26, 0);
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";
        for (int i = 0; i < 26; i++) {
            bucket[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid = string(1, char('a' + i));
        }

        auto permutations = [&](int rem) {
            long long ways = 1;
            int left = rem;

            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0)
                    continue;

                ways *= comb(left, bucket[i], k);
                if (ways > k)
                    return (long long)k + 1;

                left -= bucket[i];
            }
            return ways;
        };

        if (permutations(partition) < k)
            return "";

        string left = "";

        for (int pos = 0; pos < partition; pos++) {
            bool found = false;

            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0)
                    continue;

                bucket[i]--;

                long long ways = permutations(partition - pos - 1);

                if (ways >= k) {
                    left += char('a' + i);
                    found = true;
                    break;
                }

                k -= ways;
                bucket[i]++;
            }

            if (!found)
                return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};