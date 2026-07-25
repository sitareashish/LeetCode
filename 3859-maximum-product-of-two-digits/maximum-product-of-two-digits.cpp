class Solution {
public:
    int maxProduct(int n) {
        
        string s = to_string(n);
        sort(s.rbegin() , s.rend());
        int maxProduct = (s[0]-'0')*(s[1]-'0');
        return maxProduct;
    }
};