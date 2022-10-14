class Solution {
public:
    string frequencySort(string s) {
        int arr[256] = {0};
        
        for (auto c : s)
            arr[c]++;
        
        map<int, vector<int>> m;
        
        for (int i = 0; i < 256; i++)
            if (arr[i])
                m[arr[i]].push_back(i);
        
        
        string str = s;
        int i = 0;
        for (auto it = m.rbegin(); it != m.rend(); it++) {
            for (int k = 0; k < it->second.size(); k++)
                for (int j = 0; j < it->first; j++)
                    str[i++] = it->second[k];
        }
        return str;
    }
};