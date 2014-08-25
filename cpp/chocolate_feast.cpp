#include <iostream>
using namespace std;

int main() {
  int t, n, c, m;
  cin >> t;
  while (t--) {
    cin >> n >> c >> m;
    int answer = 0;

    while (n >= c) {
      n -= c;
      answer++;
      if (answer > 0 && (answer % m == 0))
        answer++;
    }
    cout << answer << endl;
  }
  return 0;
}
