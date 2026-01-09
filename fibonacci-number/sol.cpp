class Solution {
public:
    unordered_map<int, int> memo = {};
    int fib(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return 1;
        if (memo.contains(n)) return memo[n];
        auto comp = fib(n - 1) + fib(n - 2);
        memo[n] = comp;
        return comp;
    }
};