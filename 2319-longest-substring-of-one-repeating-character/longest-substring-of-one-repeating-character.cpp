class Solution {
public:
    int n;

    struct Node {
        int len;
        int pre;
        int suf;
        int lng;
        char left;
        char right;

        Node() {
            len = pre = suf = lng = 0;
            left = right = '#';
        }
    };

    vector<Node> seg;
    string str;

    Node start(int index) {
        Node temp;

        temp.len = 1;
        temp.pre = 1;
        temp.suf = 1;
        temp.lng = 1;
        temp.left = str[index];
        temp.right = str[index];

        return temp;
    }

    Node merge(Node a, Node b) {
        Node temp;

        int v = 0;

        // Longest substring crossing the boundary
        if (a.right == b.left) {
            v = a.suf + b.pre;
        }

        temp.lng = max(v, max(a.lng, b.lng));

        temp.len = a.len + b.len;
        temp.left = a.left;
        temp.right = b.right;

        // Prefix
        if (a.pre == a.len && a.right == b.left) {
            temp.pre = a.len + b.pre;
        }
        else {
            temp.pre = a.pre;
        }

        // Suffix
        if (b.suf == b.len && a.right == b.left) {
            temp.suf = b.len + a.suf;
        }
        else {
            temp.suf = b.suf;
        }

        return temp;
    }

    void build(int i, int l, int r) {
        if (l == r) {
            seg[i] = start(l);
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);

        seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
    }

    void update(int i, int l, int r, int idx) {
        if (l == r) {
            seg[i] = start(idx);
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {
            update(2 * i, l, mid, idx);
        }
        else {
            update(2 * i + 1, mid + 1, r, idx);
        }

        seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
    }

    int query(int index, char ch) {
        str[index] = ch;

        update(1, 0, n - 1, index);

        return seg[1].lng;
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        str = s;
        n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> res;

        for (int i = 0; i < queryCharacters.size(); i++) {
            char ch = queryCharacters[i];
            int idx = queryIndices[i];

            res.push_back(query(idx, ch));
        }

        return res;
    }
};