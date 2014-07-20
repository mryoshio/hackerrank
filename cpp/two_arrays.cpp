#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
  int i, tmp, N, K;
  vector<int> a, b;
  
  cin >> N >> K;

  for (i = 0; i < N; i++) {
    cin >> tmp;
    a.push_back(tmp);
  }

  for (i = 0; i < N; i++) {
    cin >> tmp;
    b.push_back(tmp);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());

  for (i = 0; i < N; i++) {
    if (a[i] + b[i] < K) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
    solve();
  return 0;
}
