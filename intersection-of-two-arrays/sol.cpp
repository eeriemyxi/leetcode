class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        auto target = nums1.size() > nums2.size() ? nums1 : nums2;
        std::sort(target.begin(), target.end());
        auto &checks = nums2.size() < nums1.size() ? nums2 : nums1;
        auto bsearch = [&](const vector<int> &arr, int n) {
            int left = 0;
            int right = arr.size();

            while (left < right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] >= n) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            return left;
        };

        set<int> result;
        for (auto n : checks) {
            auto val = bsearch(target, n);
            if (val != target.size() && target[val] == n) {
                result.insert(target[val]);
            }          
        }

        return vector<int>(result.begin(), result.end());
    }
};
