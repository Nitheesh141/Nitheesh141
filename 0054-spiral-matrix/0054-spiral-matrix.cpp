class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> res;
        int a1 = 0, a2 = m.size() - 1;
        int b1 = 0, b2 = m[0].size() - 1;

        while (a1 <= a2 && b1 <= b2) {
            for (int j = b1; j <= b2; j++) {
                res.push_back(m[a1][j]);
            }
            a1++;
            for (int i = a1; i <= a2; i++) {
                res.push_back(m[i][b2]);
            }
            b2--;
            if (a1 <= a2) {
                for (int j = b2; j >= b1; j--) {
                    res.push_back(m[a2][j]);
                }
                a2--;
            }
            if (b1 <= b2) {
                for (int i = a2; i >= a1; i--) {
                    res.push_back(m[i][b1]);
                }
                b1++;
            }
        }
        return res;
    }
};