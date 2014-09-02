#include <iostream>
using namespace std;

int map[100][100];
bool x[100][100];

int dir_x[] = { 0, 1, 0, -1};
int dir_y[] = { 1, 0, -1, 0};

int main() {
  int n;
  string s;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++)
      map[i][j] = s[j];
  }

  for (int i = 1; i < n-1; i++) {
    for (int j = 1; j < n-1; j++) {
      x[i][j] = true;
      for (int d = 0; d < 4; d++) {
        if (map[i][j] <= map[i+dir_x[d]][j+dir_y[d]]) {
          x[i][j] = false;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << (x[i][j] ? 'X' : (char)map[i][j]);
    cout << endl;
  }
  return 0;
}
