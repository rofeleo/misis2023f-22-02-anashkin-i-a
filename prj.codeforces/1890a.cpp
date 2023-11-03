#include <iostream>


void solve() {
  int n_nums;
  std::cin >> n_nums;
  int first_entry = 0, second_entry = 0;
  int first_entry_cnt = 0, second_entry_cnt = 0;
  for (int i = 0; i < n_nums; i += 1) {
    int num;
    std::cin >> num;
    if (!first_entry) {
      first_entry = num;
      first_entry_cnt = 1;
    } else if (first_entry == num) {
      first_entry_cnt++;
    } else if (!second_entry) {
      second_entry = num;
      second_entry_cnt = 1;
    } else if (second_entry == num) {
      second_entry_cnt++;
    }
  }
  if (!second_entry_cnt || !first_entry_cnt || (second_entry_cnt + first_entry_cnt == n_nums && abs(second_entry_cnt - first_entry_cnt) <= 1)) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}


int main() {

  int n_tests;
  std::cin >> n_tests;

  while (n_tests--) {
    solve();
    std::cout << "\n";
  }
}
