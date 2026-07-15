class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();

        vector<vector<int>> ans;
        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < n; i++)  {
            if (right >= intervals[i][0]) {
                right = max(right, intervals[i][1]);
            }
            else {
                vector<int> two;
                two.push_back(left);
                two.push_back(right);

                ans.push_back(two);
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        
        vector<int> two;
        two.push_back(left);
        two.push_back(right);

        ans.push_back(two);

        return ans;
    }
};