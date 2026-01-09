class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> found = {};
        int when = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] <= k && !found.contains(nums[i])) {
                found.insert(nums[i]);
                when = i;
            }
        }
        return nums.size() - when;
    }
};