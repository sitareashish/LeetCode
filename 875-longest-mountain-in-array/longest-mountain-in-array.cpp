class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        if (n < 3) {
            return 0;
        }

        bool inc = true;
        bool ok = false;

        int ans = 0;
        int move = 1;

        for (int i = 1; i < n; i++) {

            if (inc) {
                if (arr[i - 1] < arr[i]) {
                    move++;
                }
                else if (arr[i - 1] > arr[i]) {
                    if (move >= 2) {
                        inc = false;
                        ok = true;
                        move++;
                    }
                    else {
                        move = 1;
                    }
                }
                else {
                    move = 1;
                }
            }

            else {
                if (arr[i - 1] > arr[i]) {
                    move++;
                }
                else if (arr[i - 1] < arr[i]) {
                    ans = max(ans, move);
                    move = 2;
                    inc = true;
                    ok = false;
                }
                else {
                    ans = max(ans, move);
                    move = 1;
                    inc = true;
                    ok = false;
                }
            }

            if (ok) {
                ans = max(ans, move);
            }
        }

        return ans;
    }
};