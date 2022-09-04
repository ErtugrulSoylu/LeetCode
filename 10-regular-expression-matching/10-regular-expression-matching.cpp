class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() + s.length() == 0)
            return true;
        if (!p.length())
            return false;
        if (p.length() > 1 && p[1] == '*') {
            if (isMatch(s.substr(0), p.substr(2)) == true)
                return true;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == p[0] || p[0] == '.') {
                    if (isMatch(s.substr(i + 1), p.substr(2)) == true)
                        return true;
                } else
                    return false;
            }
        } else if (s.length() && (p[0] == '.' || s[0] == p[0])) {
            if (isMatch(s.substr(1), p.substr(1)) == true)
                return true;
        }
        return false;
    }
};