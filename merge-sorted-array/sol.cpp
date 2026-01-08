class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; ++i) {
            nums1[i] = nums2[i - m];
        }

        auto insertion_sort = [&](vector<int> &arr) {
            for (int i = 1; i < arr.size(); ++i) {
                auto key = arr[i];
                auto j = i - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    --j;
                }

                arr[j + 1] = key;
            }
        };

        insertion_sort(nums1);
    }
};
