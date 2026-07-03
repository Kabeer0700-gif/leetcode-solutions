class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxHeight=0;
        int leftBar = 0;
        int rightBar = height.size() - 1;
        while(leftBar < rightBar){
            int width = rightBar - leftBar;
            int h = min(height[leftBar],height[rightBar]);
            int currArea = width*h;
            maxHeight = max(currArea,maxHeight);

            height[leftBar] < height[rightBar] ? leftBar++ : rightBar--;

        }
        return maxHeight;
    }
};
