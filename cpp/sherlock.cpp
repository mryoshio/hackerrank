#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<int> v(n), s_up(n), s_down(n);
    bool found = false;

    for (int j = 0; j < n; j++) {
      cin >> v[j];
      if (j < n-1) s_up[j+1] = s_up[j] + v[j];
    }

    for (int j = 0; j < n; j++)
      if (j < n-1) s_down[j+1] = s_down[j] + v[n-1-j];

    for (int j = 0; j < n; j++)
      if (s_up[j] == s_down[n-1-j]) found = true;

    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;;
  }
  return 0;
}
