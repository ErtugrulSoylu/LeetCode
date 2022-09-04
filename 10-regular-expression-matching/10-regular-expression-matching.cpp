class Solution {
public:
    map<pair<string, string>, bool> m;
    bool isMatch(string s, string p) {
        if (p.length() + s.length() == 0)
            return true;
        if (!p.length())
            return false;
        if (m.count({s, p}) > 0)
            return m[{s, p}];
        if (p.length() > 1 && p[1] == '*') {
            if (isMatch(s.substr(0), p.substr(2)) == true) {
                m[{s, p}] = true;
                return true;
            }
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == p[0] || p[0] == '.') {
                    if (isMatch(s.substr(i + 1), p.substr(2)) == true) {
                        m[{s, p}] = true;
                        return true;
                    }
                } else {
                    m[{s, p}] = false;
                    return false;
                }
            }
        } else if (s.length() && (p[0] == '.' || s[0] == p[0])) {
            if (isMatch(s.substr(1), p.substr(1)) == true) {
                m[{s, p}] = true;
                return true;
            }
        }
        m[{s, p}] = false;
        return false;
    }
};