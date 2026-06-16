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
  using Type = pair<int, Cell>;
  priority_queue<Type, vector<Type>, greater<Type>> pq;
  int rows = grid.size();
  int cols = grid[0].size();
  const int inf = 1e9;
  vector<vector<int>> dist(rows, vector<int>(cols, inf));

  pq.push({0, start});
  dist[start.first][start.second] = 0;

  while(!pq.empty()) {
    auto [currentcost, currentcell] = pq.top();
    pq.pop();
    if (currentcost > dist[currentcell.first][currentcell.second]) {
        continue;
    }
    visited.push_back(currentcell);
    if (currentcell == goal) {
        break;
    }
    for (int k = 0; k < 4; ++k) {
        int nr = currentcell.first + dr[k];
        int nc = currentcell.second + dc[k];
        if (inBounds(nr, nc)) {
            if (!isWall(grid[nr][nc])) {
                int stepcost = cellCost(grid[nr][nc]);
                int newcost = currentcost + stepcost;
                
                if (newcost < dist[nr][nc]) {
                    dist[nr][nc] = newcost;
                    Cell neighbor = {nr, nc};
                    came_from[neighbor] = currentcell;
                    pq.push({newcost, neighbor});
                }
            }
        }
    }
  }
  // =========================================================================
  return visited;
}