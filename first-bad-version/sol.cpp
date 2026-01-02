class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    size_t low = 0;
    size_t high = nums.size();

    while (low < high) {
      size_t mid = low + (high - low) / 2;
      if (nums[mid] == target) return mid;
      else if (nums[mid] > target) high = mid;
      else low = mid + 1;
    }

    // assert(low == high, "Impossible.")
    return low; 
  }
};
