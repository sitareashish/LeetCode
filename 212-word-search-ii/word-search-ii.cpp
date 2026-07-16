class Solution {
public:
    int n, m;
    vector<vector<char>> a;
    struct Trie {
        int Prefix;
        bool isEOW;
        Trie* child[26];

        Trie() {
            Prefix = 0;
            isEOW = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    void insert (Trie* root, string s) {
        Trie* cur = root;

        for (char ch : s) {
            int id = ch - 'a';

            if(cur -> child[id] == nullptr){
                cur -> child[id] = new Trie();
            }
            cur -> Prefix++;
            cur = cur -> child[id];
        }
        cur -> isEOW = true;
    }

    int dd[5] = {1,0,-1,0,1};
    vector<string> ans;
    void dfs(int i, int j, Trie* node, string& cur){
        char ch = a[i][j];
        if(ch == '#') return;
        int id = ch - 'a';

        node = node -> child[id];

        if(node == nullptr) return;
        a[i][j] = '#';
        if(node -> isEOW){
            cur.push_back(ch);
            ans.push_back(cur);
            cur.pop_back();
            node -> isEOW = false;
        }
        for(int k = 0; k < 4; k++){
            int nx = i + dd[k], ny = j + dd[k + 1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                cur.push_back(ch);
                dfs(nx,ny, node, cur);
                cur.pop_back();
            }
        }
        a[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        a = board;
        n = a.size(), m = a[0].size();
        ans.clear();
        Trie* root = new Trie();
        for(auto& x: words){
            insert(root, x);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                string cur;
                dfs(i,j,root, cur);
            }
        }
        return ans;
    }
};