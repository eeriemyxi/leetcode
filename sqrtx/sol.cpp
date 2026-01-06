class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if ((size_t) mid*mid <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left - 1;
    }
};
