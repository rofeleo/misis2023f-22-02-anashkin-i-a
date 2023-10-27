#include <iostream>
#include <array>
#include <string>

void solve() {
  const int N_lets = 'z' - 'a' + 1;
  std::array<int, N_lets> cnt_lets;
  cnt_lets.fill(0);
  int word_len, n_deleted;
  std::cin >> word_len >> n_deleted;
  std::string word;
  std::cin >> word;
  for (const char& i : word) {
    cnt_lets[i - 'a'] += 1;
  }
  int cnt_odds = 0;
  for (const int& i : cnt_lets) {
    if (i % 2) cnt_odds += 1;
  }
  std::cout << (cnt_odds - 1 > n_deleted ? "NO" : "YES");
}


int main() {
  int n_tests;
  std::cin >> n_tests;

  while (n_tests--) {
    solve();
    std::cout << "\n";
  }
}