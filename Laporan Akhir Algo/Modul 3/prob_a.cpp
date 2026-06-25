#include "single_linked_list.h"
#include <iostream>
using namespace std;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;

    int initial_K = K;
    SingleLinkedList stones;
    stones.init();

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        stones.add_back(val);
    }

    int current_idx = 0; 
    while (stones.size > 1) {
        int target_idx = (int)((current_idx + (K - 1) % stones.size) % stones.size);

        int stone_val = stones.get(target_idx);

        if (stone_val % 2 == 0) {
            K++;
        } else {
            K--;
        }

        if (K <= 0) {
            K = initial_K;
        }

        stones.delete_idx(target_idx);

        current_idx = target_idx % stones.size;
    }
    cout << stones.get(0) << endl;

    return 0;
}