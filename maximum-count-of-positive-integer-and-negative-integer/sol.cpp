class Solution {
public:
  int maximumCount(vector<int>& nums) {
    auto firstNonNegative = [&](int n) { return n >= 0; };

    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (firstNonNegative(nums[mid])) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    auto firstPositive = [&](int n) { return 0 < n; };

    int negs = left;
    right = nums.size();

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (firstPositive(nums[mid])) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return std::max(negs, (int)nums.size() - left);
  }
};
