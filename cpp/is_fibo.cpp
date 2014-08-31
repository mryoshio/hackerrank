#include <iostream>
using namespace std;

long n;

void is_fibo(long a1, long a2) {
  if (a2 > n) {
    cout << "IsNotFibo" << endl;
    return;
  }
  long s = a1+a2;
  if (n == s) {
    cout << "IsFibo" << endl;
    return;
  } else {
    is_fibo(a2, s);
  }
}

int main() {
  long t;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 0 || n == 1) {
      cout << "IsFibo" << endl;
    } else {
      is_fibo(0, 1);
    }
  }
}
