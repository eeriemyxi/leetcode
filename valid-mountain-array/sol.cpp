class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) return false;

    auto switched = false;

    for (int i = 0; i < arr.size() - 1; i++) {
      if (arr[i] == arr[i + 1]) {
        return false;
      }
            
      if (switched && arr[i + 1] > arr[i]) {
        return false;
      } 

      if (arr[i + 1] > arr[i]) {
        continue;
      }

      if (arr[i + 1] < arr[i]) {
        switched = true;
      } else {
        return false;
      }
    }

    return switched && arr[0] < arr[1];
  }
};
