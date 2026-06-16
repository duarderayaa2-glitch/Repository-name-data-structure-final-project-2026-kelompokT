// solution.cpp — THIS IS WHAT YOU WILL WORK ON.
//
// Write your algorithm ONLY inside the solve() function below.
// Do not add other functions. Do not modify harness.h.
//
// Compile: g++ -O2 -std=c++17 solution.cpp -o solution
// Run:     ./solution ../maps/soal1.txt output.txt
// View:    open engine/index.html, select the question/map, drag output.txt, click Play/Run.

#include "harness.h"
#include <queue>
#include <vector>

vector<Cell> solve(vector<vector<char>>& grid, Cell start, Cell goal){
  vector<Cell> visited;
  int dr[] = {-1, 1, 0, 0};
  int dc[] = { 0, 0,-1, 1};
  queue<Cell> q;
  
  int rows = grid.size();
  int cols = grid[0].size();
  vector<vector<bool>> explored(rows, vector<bool>(cols, false));
  q.push(start);
  explored[start.first][start.second] = true;

  while(!q.empty()) {
    Cell currentcell = q.front();
    q.pop();
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
                explored[nr][nc] = true; 
                came_from[neighbor] = currentcell;
                q.push(neighbor);
            }
        }
    }
  }
  // =========================================================================
  return visited;
}