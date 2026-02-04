#include <stdio.h>
#include <inttypes.h>

int board_size;
float values[400];
int m;
int n;

void init_vars() {
    board_size = 20; // Since values array size is 400 and access uses (21 + m*20 + n), we infer board_size <= 20
    // Maximum index: when m = 19, n = 19 -> index = 21 + 19*20 + 19 = 21 + 380 + 19 = 420 -> out of bounds!
    // So adjust board_size to keep within [0,399] indexing.

    // Recompute safe board_size: index = 21 + m*(20) + n < 400
    // Max m and n: let m_max = n_max = N-1
    // => 21 + (N-1)*20 + (N-1) = 21 + 21*(N-1) < 400
    // => 21*(N-1) < 379 => N-1 < 18.05 => N <= 18

    board_size = 18;

    // Initialize values array to prevent undefined behavior if inspected
    for (int i = 0; i < 400; i++) {
        values[i] = 1.0f; // arbitrary initial value
    }
}