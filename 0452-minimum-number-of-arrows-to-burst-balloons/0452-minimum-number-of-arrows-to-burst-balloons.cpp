class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        deque<vector<int>> pointsStack;
        pointsStack.push_back(points[0]);
        int size = points.size();
        for (int indx = 1; indx < size; indx++) {
            int currEnd = points[indx][1];
            int currStart = points[indx][0];
            while (!pointsStack.empty() && pointsStack.back()[1] >= currStart) {
                auto popInter = pointsStack.back();
                currStart = max(currStart, popInter[0]);
                currEnd = min(currEnd, popInter[1]);
                pointsStack.pop_back();
            }
            pointsStack.push_back({currStart, currEnd});
        }
        return pointsStack.size();
    }
};