#include <iostream>
#include <vector>

using namespace std;

struct DataPosisi {
    int r, c;
    int arahKe;
};

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    int SR, SC, FR, FC;
    cin >> SR >> SC >> FR >> FC;

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<DataPosisi> tumpukan;
    int jumlahJalur = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    tumpukan.push_back({SR, SC, 0});
    visited[SR][SC] = true;

    while (!tumpukan.empty()) {
        int r = tumpukan.back().r;
        int c = tumpukan.back().c;
        int d = tumpukan.back().arahKe;

        if (r == FR && c == FC) {
            jumlahJalur++;
            visited[r][c] = false;
            tumpukan.pop_back();
            continue;
        }

        if (tumpukan.back().arahKe < 4) {
            int arahSekarang = tumpukan.back().arahKe;
            tumpukan.back().arahKe++;

            int barisBaru = r + dr[arahSekarang];
            int kolomBaru = c + dc[arahSekarang];

            if (barisBaru >= 0 && barisBaru < R &&
                kolomBaru >= 0 && kolomBaru < C &&
                grid[barisBaru][kolomBaru] == 0 &&
                !visited[barisBaru][kolomBaru]) {

                visited[barisBaru][kolomBaru] = true;
                tumpukan.push_back({barisBaru, kolomBaru, 0});
            }
        } else {
            visited[r][c] = false;
            tumpukan.pop_back();
        }
    }

    cout << jumlahJalur << endl;

    return 0;
}