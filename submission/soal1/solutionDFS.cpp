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
#include <set>

vector<Cell> solve(vector<vector<char>>& grid, Cell start, Cell goal){
    vector<Cell> visited;

    stack<Cell> st;
    set<Cell> discovered;

    st.push(start);
    discovered.insert(start);

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!st.empty()){
        Cell current = st.top();
        st.pop();

        visited.push_back(current);

        if(current == goal){
            break;
        }

        int r = current.first;
        int c = current.second;

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(!inBounds(nr, nc))
                continue;

            Cell neighbor = {nr, nc};

            if(discovered.count(neighbor))
                continue;

            discovered.insert(neighbor);

            came_from[neighbor] = current;

            st.push(neighbor);
        }
    }

    return visited;
}
