class Solution {
public:
        int MOD = 1e9 + 7;
    int decodings(int ind, string &s, vector<int> &dp)
    {
        if (ind == s.size())
            return 1;
        if (s[ind] == '0')
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        long long oneCharChoice = decodings(ind + 1, s, dp);
        if (s[ind] == '*')
            oneCharChoice = (oneCharChoice *9) % MOD;

        long long twoCharChoice1 = 0;
        long long twoCharChoice2 = 0;

        if (ind + 1 < s.size())
        {
            if (s[ind] == '1' || s[ind] == '*')
            {
                twoCharChoice1 = decodings(ind + 2, s, dp);
                if (s[ind + 1] == '*')
                {
                    twoCharChoice1 = (twoCharChoice1 *9) % MOD;
                }
            }
            if (s[ind] == '2' || s[ind] == '*')
            {
                if (s[ind + 1] == '*')
                {
                    twoCharChoice2 = decodings(ind + 2, s, dp);
                    twoCharChoice2 = (6 *twoCharChoice2) % MOD;
                }
                    else if (s[ind + 1] - '0' <= 6)
                    {
                        twoCharChoice2 = decodings(ind + 2, s, dp);
                    }
                }
            }
            return dp[ind] = ((oneCharChoice + twoCharChoice1) % MOD + twoCharChoice2) % MOD;
        }
        int numDecodings(string s)
        {
            int n = s.size();
            vector<int> dp(n + 1, -1);
            return decodings(0, s, dp);
        }
    };