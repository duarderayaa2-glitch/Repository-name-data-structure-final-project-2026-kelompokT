#include "harness.h"
#include <vector>

vector<Cell> solve(vector<vector<char>>& grid, Cell start, Cell goal){
  vector<Cell> visited; 
  int dr[] = {-1, 1, 0, 0};
  int dc[] = { 0, 0,-1, 1};
  int rows = grid.size();
  int cols = grid[0].size();
  const int inf = 1e9;
  vector<vector<int>> dist(rows, vector<int>(cols, inf));

  vector<vector<bool>> into_trace(rows, vector<bool>(cols, false));

  dist[start.first][start.second] = 0;
  visited.push_back(start);
  into_trace[start.first][start.second] = true;

  int totalvertices = rows * cols;

  for (int i = 0; i < totalvertices - 1; ++i) {
    bool updated = false;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (dist[r][c] == inf || isWall(grid[r][c])) {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (inBounds(nr, nc) && !isWall(grid[nr][nc])) {
                    int stepcost = cellCost(grid[nr][nc]);
                    int newcost = dist[r][c] + stepcost;
                    if (newcost < dist[nr][nc]) {
                        dist[nr][nc] = newcost;
                        Cell neighbor = {nr, nc};
                        came_from[neighbor] = {r, c};
                        updated = true;
                        if (!into_trace[nr][nc]) {
                            visited.push_back(neighbor);
                            into_trace[nr][nc] = true;
                        }
                    }
                }
            }
        }
    }
    if (!updated) {
        break;
    }
  }
  if (dist[goal.first][goal.second] != inf && !into_trace[goal.first][goal.second]) {
      visited.push_back(goal);
  }
  // =========================================================================
  return visited;
}