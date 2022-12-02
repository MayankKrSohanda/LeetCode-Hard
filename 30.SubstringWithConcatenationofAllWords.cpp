class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int i, j, k, n = words.size(), m = words[0].size(), total = n * m;
        if(s.size() < total){
            return ans;
        }
        for(i = 0; i <= s.size() - total; i++) {
            unordered_map<string, int> mp;
            for(j = 0; j < n; j++) {
                mp[words[j]]++;
            }
            for(k = 0; k < n; k++) {
                string temp = s.substr(i + k * m, m);
                if(mp.count(temp) == 0) {
                    break;
                }
                else{
                    if(mp[temp] != 0) {
                        mp[temp]--;
                    }
                    else {
                        break;
                    }
                }
            }
            if(k == n) {
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};
