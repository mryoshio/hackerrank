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

  if (s == 1) {
    d();
    return;
  }

  int idx = 0;

  for (int i = 1; i < s; i++) {
    for (int j = 0; j < i; j++) {
      while (ar[j] <= ar[i])
        idx++;
    }


    for (int i=s-1; idx < i; i--) {
      ar[i] = ar[i-1];
      d();
  }
    
  }

  while(t < s) {
    int x = ar[t];
    int idx = 0;

    while (ar[idx] <= x)
      idx++;

    cout << idx << endl;

    for (int i=t; idx < i; i--) {
      ar[i] = ar[i-1];
    }

    ar[idx] = x;

    t++;
  }
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
