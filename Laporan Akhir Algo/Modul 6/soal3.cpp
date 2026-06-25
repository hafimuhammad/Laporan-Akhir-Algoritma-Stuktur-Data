#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int r, c, dist;
};

int main() {
    int R, C;
    if (!(cin >> R >> C) || R <= 0 || C <= 0) return 0;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    int SR, SC, FR, FC;
    if (!(cin >> SR >> SC >> FR >> FC)) return 0;
    if (SR < 0 || SR >= R || SC < 0 || SC >= C || FR < 0 || FR >= R || FC < 0 || FC >= C) {
        return 0;
    }

vector<Node> q;
int head = 0;

vector<vector<bool>> visited(R, vector<bool>(C, false));

q.push_back({SR, SC, 0});
visited[SR][SC] = true;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

while (head < q.size()) {
    Node curr = q[head];
    head++;

if (curr.r == FR && curr.c == FC) {
    cout << curr.dist << endl;
    return 0;
}

for (int i = 0; i < 4; ++i) {
    int nr = curr.r + dr[i];
int nc = curr.c + dc[i];

    if (nr >= 0 && nr < R && nc >= 0 && nc < C
        && grid[nr][nc] == 0 && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push_back({nr, nc, curr.dist + 1});
        }
    }   
}
cout << -1 << endl;
return 0;
}
