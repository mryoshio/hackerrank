#include <iostream>
#include <array>

#define N_MAX 100000

using namespace std;

int N, T;
array<int, 100000> widths;
int memo[N_MAX + 1][N_MAX + 1] = { 0 };

void solve() {
  int s, e;
  for (int i = 0; i < T; i++) {
    int v = 3;
    cin >> s >> e;
    if (memo[s][e] > 0) {
      cout << memo[s][e] << endl;
      continue;
    }
    for (int i = s; i < e; i++)
      if (v > widths.at(i)) v = widths.at(i);
    cout << (memo[s][e] = v) << endl;
  }
}

int main() {
  cin >> N >> T;
  for (int i = 0; i < N; i++) cin >> widths[i];
  solve();
  return 0;
}
