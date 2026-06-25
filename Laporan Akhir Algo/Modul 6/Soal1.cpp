#include <iostream>
#include <vector>

int main() {
    int N, M;

    if (!(std::cin >> N)) return 0;
    std::vector<char> labels(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> labels[i];
    }
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N,
    0));

    if (!(std::cin >> M)) return 0;
    for (int i = 0; i < M; ++i) {
        char u, v;
        int w;
        if (std::cin >> u >> v >> w) {
            int u_idx = -1, v_idx = -1;
            for (int k = 0; k < N; ++k) {
                 if (labels[k] == u) u_idx = k;
                 if (labels[k] == v) v_idx = k;
        }
        if (u_idx != -1 && v_idx != -1) {
            matrix[u_idx][v_idx] = w;
        }
    }
}

std::cout << "Adjacency Matrix:\n";
for (int i = 0; i < N; ++i) std::cout << " " << labels[i];
std::cout << std::endl;

for (int i = 0; i < N; ++i) {
    std::cout << labels[i];
    for (int j = 0; j < N; ++j) {
        std::cout << " " << matrix[i][j];
    }
    std::cout << std::endl;
}
return 0;
}