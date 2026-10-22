class SummaryRanges {
private:
    set<int> nums;

public:
    SummaryRanges() {
    }

    void addNum(int value) {
        nums.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;

        for (int num : nums) {
            if (intervals.empty() || 
                num > intervals.back()[1] + 1) {
                intervals.push_back({num, num});
            } else {
                intervals.back()[1] = num;
            }
        }

        return intervals;
    }
};