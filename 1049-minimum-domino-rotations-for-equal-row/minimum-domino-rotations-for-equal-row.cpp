class Solution {
public:
    int check(vector<int>& top, vector<int>& bottom, int x) {
        int topRot = 0;
        int bottomRot = 0;

        for (int i = 0; i < top.size(); i++) {
            if (top[i] != x && bottom[i] != x)
                return INT_MAX;

            if (top[i] != x) topRot++;
            if (bottom[i] != x) bottomRot++;
        }

        return min(topRot, bottomRot);
    }

    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        int ans = min(check(top, bottom, top[0]),
                      check(top, bottom, bottom[0]));

        return ans == INT_MAX ? -1 : ans;
    }
};