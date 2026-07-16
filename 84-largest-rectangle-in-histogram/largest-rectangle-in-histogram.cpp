#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> left_less(n);
        vector<int> right_less(n);

        left_less[0] = -1;
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left_less[p];
            }
            left_less[i] = p;
        }

        right_less[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) {
                p = right_less[p];
            }
            right_less[i] = p;
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int width = right_less[i] - left_less[i] - 1;
            int current_area = heights[i] * width;
            max_area = max(max_area, current_area);
        }

        return max_area;
    }
};