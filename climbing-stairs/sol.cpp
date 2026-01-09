class Solution {
public:
    unordered_map<int, int> memo = {};
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        if (memo.contains(n)) return memo[n];
        int computed = climbStairs(n - 1) + climbStairs(n - 2);
        memo[n] = computed;
        return computed;
    }
};