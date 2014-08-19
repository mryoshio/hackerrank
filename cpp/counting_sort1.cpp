#include <iostream>
#include <array>
using namespace std;

void solve() {
  int t;
  long n;
  array<long, 100> a;
  a.fill(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    a.at(t)++;
  }
  cout << a.at(0);
  for (int i = 1; i < 100; i++)
    cout << " " << a.at(i);
  cout << endl;
}

int main() {
  solve();
  return 0;
}
