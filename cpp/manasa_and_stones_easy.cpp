#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int a, b, n, t;
  vector<long> v;
  cin >> t;
  while (t--) {
    v.clear();
    cin >> n >> a >> b;
    n--;
    if (a == b) {
      cout << (n*a) << endl;
      continue;
    }
    for (int i = 0; i <= n; i++)
      v.push_back(a*i + (n-i)*b);

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size()-1; i++)
      cout << v[i] << ' ';
    cout << v[v.size()-1] << endl;
  }
  return 0;
}
