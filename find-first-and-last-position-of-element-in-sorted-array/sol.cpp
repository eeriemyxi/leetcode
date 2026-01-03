class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    if (!right) {
      return {-1, -1};
    }

    vector<int> res = {0, 0};

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    if (left >= nums.size() || nums[left] != target) {
      return {-1, -1};
    }

    right = nums.size();
    res[0] = left;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    res[1] = --left;

    return res;
  }
};
