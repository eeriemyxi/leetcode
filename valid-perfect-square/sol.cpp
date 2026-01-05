class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if ((double) mid * mid >= num) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return (double) left * left == num; // Don't use floats, they're 32-bit and will fail on some test cases like 100000001
  }
};
