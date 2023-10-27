#include <iostream>
#include <vector>
#include <set>

void solve() {
  int n_nums;
  std::cin >> n_nums;
  std::vector<int> nums(n_nums);
  for (int& i : nums) {
    std::cin >> i;
  }

  long long ans = 0;

  std::set<int> entries;
  std::vector<int> left_uninque_cnt(n_nums, 0);
  left_uninque_cnt[0] = 1;
  entries.insert(nums[0]);


  for (int i = 1; i < n_nums; i += 1) {
    left_uninque_cnt[i] += left_uninque_cnt[i - 1];
    left_uninque_cnt[i] += (entries.count(nums[i]) + 1) % 2;
    entries.insert(nums[i]);
  }

  entries.clear();

  for (int i = n_nums - 1; i >= 0; i -= 1) {
    if (!entries.count(nums[i])) {
      ans += left_uninque_cnt[i];
    }
    entries.insert(nums[i]);
  }

  if (n_nums == 1) ans = 1;

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
