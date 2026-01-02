class Solution {
public:
  int search(vector<int>& nums, int target) {
    size_t head = 0;
    size_t tail = nums.size();

    while (head < tail) {
      size_t mid = head + (tail - head) / 2;
      auto guess = nums[mid];
      if (guess == target) {
        return mid;
      } else if (guess > target) {
        tail = mid;
      } else {
        head = mid + 1;
      }
    }
        
    return -1;
  }
};
