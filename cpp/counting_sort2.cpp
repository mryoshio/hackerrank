#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
  int t;
  long n;
  vector<int> a;
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    a.push_back(t);
  }
  sort(a.begin(), a.end());
  cout << a.at(0);
  for (int i = 1; i < n; i++)
    cout << " " << a.at(i);
  cout << endl;
}

int main() {
  solve();
  return 0;
}
