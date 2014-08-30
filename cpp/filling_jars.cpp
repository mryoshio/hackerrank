#include <iostream>
using namespace std;

int main() {
  long n, m, a, b, k, s;
  cin >> n >> m;
  while (m--) {
    cin >> a >> b >> k;
    s += (b-a+1)*k;
  }
  cout << (long)s/n << endl;
  return 0;
}
