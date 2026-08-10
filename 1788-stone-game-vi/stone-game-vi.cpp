class Solution {
public:

    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();

        vector<pair<int, int>> ids(n);

        for (int i = 0; i < n; i++) {
            ids[i] = {aliceValues[i] + bobValues[i], i};
        }

        sort(ids.begin(), ids.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int alice = 0;
        int bob = 0;

        for (int i = 0; i < n; i++) {
            int idx = ids[i].second;

            if (i % 2 == 0) {
                alice += aliceValues[idx];
            }
            else {
                bob += bobValues[idx];
            }
        }

        if (alice > bob) {
            return 1;
        }
        else if (alice == bob) {
            return 0;
        }

        return -1;
    }
};