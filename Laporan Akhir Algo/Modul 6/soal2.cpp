#include <iostream>
#include <vector>

int main() {
    int N;
    if (!(std::cin >> N) || N <= 0) return 0;

    std::vector<char> labels(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> labels[i];
    }

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

std::cout << "Adjacency List:\n";
for (int i = 0; i < N; ++i) {
    std::cout << labels[i] << " -> ";
    bool first = true;
    bool Edge = false;
    for (int j = 0; j < N; ++j) {
        if (matrix[i][j] != 0) {
            if (!first) std::cout << ", ";
            std::cout << "(" << labels[j] << "," << matrix[i][j] << ")";
            first = false;
            Edge = true;
        }
    }
    if (!Edge) {
    std::cout << "-";
    }
    std::cout << std::endl;
}

return 0;
}
