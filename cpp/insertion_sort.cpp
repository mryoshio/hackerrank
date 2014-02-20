#include <iostream>
#include <climits>

using namespace std;

int s;
int ar[1001] = {};

void d() {
  for (int i=0; i<s; i++)
    cout << ar[i] << " ";
  cout << endl;
}

void insertionSort(int ar[]) {
  int x = ar[s-1];
  int idx = 0;

  while (ar[idx] <= x)
    idx++;

  for (int i=s-1; idx < i; i--) {
    ar[i] = ar[i-1];
    d();
  }

  ar[idx] = x;
  d();
}

int main() {
  cin >> s;
  ar[s+1] = INT_MAX;
  for (int i=0; i<s; i++)
    cin >> ar[i];
  insertionSort (ar);
  return 0;
}
