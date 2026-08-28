class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1000000007;

        long long ans = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {

            int curr = (i == n) ? 0 : arr[i];

            while (!st.empty() && arr[st.top()] > curr) {

                int h = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();

                long long leftChoices = h - left;
                long long rightChoices = i - h;

                ans = (ans + 1LL * arr[h] * leftChoices * rightChoices) % MOD;
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};