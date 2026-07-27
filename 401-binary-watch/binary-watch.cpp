class Solution {
public:
    int count_(int num) {
        int ans = 0;
        int i = 0;
        while (num > 0) {
            if (num & ( 1 << i)) {
                ans++;
            }
            num /= 2;
        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> validTimes;
        
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                
                if (count_(h) + count_(m) == turnedOn) {
                    
                    string timeStr = to_string(h) + (m < 10 ? ":0" : ":") + to_string(m);
                    validTimes.push_back(timeStr);
                }
            }
        }
        
        return validTimes;
    }
};