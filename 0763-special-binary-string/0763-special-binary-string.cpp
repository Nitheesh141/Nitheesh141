class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        int cnt = 0,start = 0;
        vector<string> sp;
        for(int i = 0;i<n;i++){
            cnt += (s[i]=='1') ? 1 : -1;
            if(cnt == 0){
                string special = "1" + makeLargestSpecial(s.substr(start+1,i-start-1)) + "0";
                sp.push_back(special);
                start = i+1;
            }
        }
        sort(sp.begin(), sp.end(), greater<string>());
        string ans = "";
        for(auto it : sp){
            ans += it;
        }
        return ans;
    }
};