class MedianFinder {
private:
    priority_queue<int> left; // Max heap: smaller half
    priority_queue<int, vector<int>, greater<int>> right; // Min heap: larger half

public:
    MedianFinder() {
    }

    void addNum(int num) {
        // Add the number to the appropriate heap
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return ((double)left.top() + right.top()) / 2.0;
        }

        return (left.size() > right.size())
                   ? left.top()
                   : right.top();
    }
};