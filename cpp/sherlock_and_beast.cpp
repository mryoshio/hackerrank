#include <iostream>
using namespace std;

void solve(long n) {
  long L;
  if (n % 3 == 0) {
    for (L = 0; L < n; L++)
      cout << '5';
    cout << endl;
  } else {
    long max5 = n/3;
    bool found = false;
    for (; max5 >= 0; max5--) {
      if ((n - 3*max5) % 5 == 0) {
        found = true;
        break;
      }
    }
    if (found) {
      for (L = 0; L < max5*3; L++)
        cout << '5';
      for (L = 0; L < n-max5*3; L++)
        cout << '3';
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
}

int main() {
  int t;
  long n;
  cin >> t;
  while (t--) {
    cin >> n;
    solve(n);
  }
  return 0;
}
