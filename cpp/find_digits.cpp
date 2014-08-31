#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long m, n, o, s = 0;
    cin >> n;
    o = n;
    do {
      m = n % 10;
      n /= 10;
      if (m != 0 && o % m == 0) s++;
    } while (n);
    cout << s << endl;
  }
}
