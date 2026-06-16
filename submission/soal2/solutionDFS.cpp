// solution.cpp — THIS IS WHAT YOU WILL WORK ON.
//
// Write your algorithm ONLY inside the solve() function below.
// Do not add other functions. Do not modify harness.h.
//
// Compile: g++ -O2 -std=c++17 solution.cpp -o solution
// Run:     ./solution ../maps/soal1.txt output.txt
// View:    open engine/index.html, select the question/map, drag output.txt, click Play/Run.

#include "harness.h"
#include <stack>
#include <vector>

vector<Cell> solve(vector<vector<char>>& grid, Cell start, Cell goal){
  vector<Cell> visited;
  int dr[] = {-1, 1, 0, 0};
  int dc[] = { 0, 0,-1, 1};
  stack<Cell> s;
  int rows = grid.size();
  int cols = grid[0].size();

  vector<vector<bool>> explored(rows, vector<bool>(cols, false));
  s.push(start);

  while(!s.empty()) {
    Cell currentcell = s.top();
    s.pop();
    if (explored[currentcell.first][currentcell.second]) {
        continue;
    }
    explored[currentcell.first][currentcell.second] = true;
    visited.push_back(currentcell);
    if (currentcell == goal) {
        break;
    }
    for (int k = 0; k < 4; ++k) {
        int nr = currentcell.first + dr[k];
        int nc = currentcell.second + dc[k];
        if (inBounds(nr, nc)) {
            if (!isWall(grid[nr][nc]) && !explored[nr][nc]) {
                Cell neighbor = {nr, nc};
                came_from[neighbor] = currentcell;
                
                s.push(neighbor);
            }
        }
    }
  }
  // =========================================================================
  return visited;
}