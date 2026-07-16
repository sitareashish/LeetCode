class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> pq;
        int j = 0;

        while (k--) {

            while (j < n && projects[j].first <= w) {
                pq.push(projects[j].second);
                j++;
            }


            if (pq.empty()) {
                break;
            }

 
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};