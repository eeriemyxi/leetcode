class Solution {
public:
  bool isValid(std::string s) {
    using namespace std;

    unordered_map<string, string> brackets = {
      {"(", ")"}, {"{", "}"}, {"[", "]"}};
    vector<string> stack;

    for (auto c : s) {
      string cs = string(1, c);
      if (brackets.contains(cs)) {
        stack.push_back(cs);
      } else {
        if (stack.empty() || brackets[stack.back()] != cs) {
          return false;
        }
        stack.pop_back();
      }
    }

    return stack.empty();
  }
};
