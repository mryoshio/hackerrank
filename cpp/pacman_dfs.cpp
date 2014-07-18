#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pos;

const int MaxSize = 40;

void dfs(int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid) {
  stack<pos> stck;
  queue<pos> visited;
  pos paths[MaxSize+1][MaxSize+1] = { pos(-1, -1) };

  int dr[4] = { -1, 0, 0, +1 };
  int dc[4] = { 0, -1, +1, 0 };

  stck.push(pos(pacman_r, pacman_c));
  grid[pacman_r][pacman_c] = 'f';

  while (!stck.empty()) {
    pos cur = stck.top(); stck.pop();
    visited.push(cur);

    if (cur == pos(food_r, food_c)) break;

    for (int i = 0; i < 4; i++) {
      int new_r = cur.first + dr[i];
      int new_c = cur.second + dc[i];

      if (new_r >= 0 && new_r <= r-1 &&
          new_c >= 0 && new_c <= c-1 &&
          grid[new_r][new_c] != '%' && grid[new_r][new_c] != 'f') {
        grid[new_r][new_c] = 'f';
        paths[new_r][new_c] = cur;
        stck.push(pos(new_r, new_c));
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
  while (shortest.top() != pos(pacman_r, pacman_c))
    shortest.push(paths[shortest.top().first][shortest.top().second]);

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
