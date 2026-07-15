class MedianFinder {
public:
    multiset<int> left;
    multiset<int> right;

    void rebalance() {
        while (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            right.insert(*it);
            left.erase(it);
        }

        while (right.size() > left.size()) {
            auto it = right.begin();
            left.insert(*it);
            right.erase(it);
        }
    }

    MedianFinder() {

    }
    
    void addNum(int num) {
        if (left.empty() || *prev(left.end()) > num) {
            left.insert(num);
        }
        else {
            right.insert(num);
        }
        rebalance();
    }
    
    double findMedian() {
        double ans;
        if (left.size() == right.size()) {
            ans = (double) (*prev(left.end()) + *right.begin()) / (double) 2;
        }
        else {
            ans = *prev(left.end());
        }
        return ans;
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */