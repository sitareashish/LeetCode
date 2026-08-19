class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rS) {
        map<int, vector<int>> seats;

        for (auto &p : rS) {
            int row = p[0];
            int col = p[1];

            if (!seats.count(row)) {
                seats[row] = {1, 1, 1};
            }

            if (col == 2 || col == 3) {
                seats[row][0] = 0;
            }
            else if (col == 4 || col == 5) {
                seats[row][0] = 0;
                seats[row][1] = 0;
            }
            else if (col == 6 || col == 7) {
                seats[row][1] = 0;
                seats[row][2] = 0;
            }
            else if (col == 8 || col == 9) {
                seats[row][2] = 0;
            }
        }

        long long ans = 2LL * n;

        for (auto &[row, seat] : seats) {
            int l = seat[0];
            int m = seat[1];
            int r = seat[2];

            int families = 0;

            if (l && r) {
                families = 2;
            }
            else if (l || m || r) {
                families = 1;
            }

            // This row was initially counted as 2
            ans -= 2;
            ans += families;
        }

        return ans;
    }
};