class Solution {
public:
    int n;
    vector<int> arr;
    vector<vector<int>> seg;
    void build(int i, int l, int r) {
        if (l == r) {
            seg[i].push_back(arr[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);

        merge(seg[2 * i].begin(), seg[2 * i].end(), seg[2 * i + 1].begin(), seg[2 * i + 1].end(), back_inserter(seg[i]));
        return;
    }

    int query(int i, int l, int r, int ql, int qr, int x) {
        if (ql > r || l > qr) return 0;

        if (ql <= l && r <= qr) {
            auto it = lower_bound(seg[i].begin(), seg[i].end(), x);
            return it - seg[i].begin();
        }

        int mid = l + (r - l) / 2;

        int left = query(2 * i, l, mid, ql, qr, x);
        int right = query(2 * i + 1, mid + 1, r, ql, qr, x);

        return left + right;
    }

    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        seg.assign(4 * n, vector<int>());
        build(1, 0, n - 1);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            int val = query(1, 0, n - 1, i, n - 1, x);
            ans.push_back(val);
        }

        return ans;
    }
};