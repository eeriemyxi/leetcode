class Solution {
public:
  vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> even_nums;
    vector<int> odd_nums;

    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 == 0) {
        even_nums.push_back(nums[i]);
      } else {
        odd_nums.push_back(nums[i]);
      }
    }

    sort(even_nums.begin(), even_nums.end());
    sort(odd_nums.begin(), odd_nums.end());

    int total = nums.size();

    for (int i = 0; i < total; i++) {
      if (i % 2 == 0) {
        nums.at(i) = even_nums.front();
        even_nums.erase(even_nums.begin());
      } else {
        nums.at(i) = odd_nums.back();
        odd_nums.pop_back();
      }
    }

    return nums;
  }
};
