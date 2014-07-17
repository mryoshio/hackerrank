#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int, int> pos;
void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
  stack<pos> st;
  queue<pos> visited;
  vector<vector<pos> > paths(r);

  st.push(pos(pacman_r, pacman_c));

  int dr[4] = { -1, 0, 0, +1 };
  int dc[4] = { 0, -1, +1, 0 };

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      paths[i].push_back(pos(-1, -1));

  while (!st.empty()) {
    pos cur = st.top(); st.pop();

    if (grid[cur.first][cur.second] == '.') {
      visited.push(pos(cur.first, cur.second));
      break;
    }

    if (grid[cur.first][cur.second] != 'f') {
      grid[cur.first][cur.second] = 'f';
      visited.push(pos(cur.first, cur.second));

      for (int i = 0; i < 4; i++) {
        int new_r = cur.first + dr[i];
        int new_c = cur.second + dc[i];

        if (new_r >= 0 && new_r <= r-1 &&
            new_c >= 0 && new_c <= c-1 &&
            grid[new_r][new_c] != '%' && grid[new_r][new_c] != 'f') {
          paths[new_r][new_c] = pos(cur.first, cur.second);
          st.push(pos(new_r, new_c));
        }
      }
    }
  }

  cout << visited.size() << endl;
  while (!visited.empty()) {
    cout << visited.front().first << ' ' << visited.front().second << endl;
    visited.pop();
  }

  stack<pos> shortest;
  shortest.push(pos(food_r, food_c));
  while (shortest.top().first != -1 && shortest.top().second != -1)
    shortest.push(paths[shortest.top().first][shortest.top().second]);
  shortest.pop();
  cout << shortest.size() - 1 << endl;
  while (!shortest.empty()) {
    cout << shortest.top().first << ' ' << shortest.top().second << endl;
    shortest.pop();
  }
}
int main(void) {

  int r,c, pacman_r, pacman_c, food_r, food_c;
    
  cin >> pacman_r >> pacman_c;
  cin >> food_r >> food_c;
  cin >> r >> c;
    
  vector <string> grid;

  for(int i=0; i<r; i++) {
    string s; cin >> s;
    grid.push_back(s);
  }

  dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

  return 0;
}
