#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> v;

void solve() {
  vector<long> ans;
  for (long i = 0; i < v.size(); i++) {
    if (v[v.size()-1] % v[i] != 0)
      continue;
    long t = v[i];
    bool possible = true;
    for (long idx = 1; idx < v[v.size()-1]/v[i]; idx++) {
      if (find(v.begin()+i, v.end(), t*idx) == v.end()) {
        possible = false;
        break;
      }
    }
    if (possible)
      ans.push_back(t);
  }
  for (long i = 0; i < ans.size(); i++) {
    if (i != 0)
      cout << ' ';
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  long n;
  int x;
  cin >> n;
  cin >> x;
  v.push_back(x);
  for (long i = 1; i < n; i++) {
    cin >> x;
    v.push_back(v[i-1] + x);
  }
  solve();
  return 0;
}
