// This is a newer solution on a revision day

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] >= target) {
        right = mid;
      } else {
        left += 1;
      }
    }

    if (left == nums.size() || nums[left] != target) {
      return {-1, -1};
    }

    int st = left;
    right = nums.size();

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (target >= nums[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return {st, left - 1};
  }
};
