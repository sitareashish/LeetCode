class Solution {
public:
    vector<string> ans;

    void backtrack(string& num, int target, int index, long cv, long pv, string path) {
        if (index == num.length()) {
            if (cv == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {
            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long curr = stol(part);

            if (index == 0) {
                backtrack(num, target, i + 1, curr, curr, path + part);
            } else {
                backtrack(num, target, i + 1, cv + curr, curr, path + "+" + part);
                backtrack(num, target, i + 1, cv - curr, -curr, path + "-" + part);
                backtrack(num, target, i + 1, cv - pv + (pv * curr), pv * curr, path + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        if (num.empty()) return ans;
        backtrack(num, target, 0, 0, 0, "");
        return ans;
    }
};