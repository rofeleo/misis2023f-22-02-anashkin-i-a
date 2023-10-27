#include <iostream>
#include <vector>

void solve() {
  int n_nums, k;
  std::cin >> n_nums >> k;
  std::vector<int> nums(n_nums, 0);
  for (int& i : nums) std::cin >> i;
  int ans = -1;
  for (const int& i : nums) {
    if (i % k == 0) {
      std::cout << 0;
      return;
    }
    ans = std::max(ans, i % k);
  }
  ans = k - ans;
  if (k == 4) {
    int cnt_odd = 0;
    for (const int& i : nums) cnt_odd += i % 2;
    if (n_nums - cnt_odd > 1) ans = 0;
    else if (cnt_odd < n_nums) ans = 1;
    else if (cnt_odd >= 2) ans = std::min(ans, 2);
  }
  std::cout << ans;
}


int main() {
  int n_tests;
  std::cin >> n_tests;

  while (n_tests--) {
    solve();
    std::cout << "\n";
  }
}