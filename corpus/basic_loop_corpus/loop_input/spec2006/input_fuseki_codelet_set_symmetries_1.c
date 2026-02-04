#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int board_size = 400;
Intersection board[421] = {0};
int horizontally_symmetric = 1;
int vertically_symmetric = 1;
int diagonally_symmetric = 1;
int i = 0;
int j = 0;

void init_vars() {
    // Adjust board_size to fit within the declared array bounds
    // The board is accessed with offset (19+2) and index involving (19+1)*i + j
    // So effective size must satisfy: (19+2) + (board_size-1)*(19+1) + (board_size-1) < 421
    // Solving: 21 + (board_size-1)*20 + (board_size-1) = 21 + (board_size-1)*21 < 421
    // => (board_size-1)*21 < 400 => board_size-1 < 19.04 => board_size <= 19
    board_size = 19;

    // Initialize board with symmetric pattern around center
    for (int idx = 0; idx < 421; idx++) {
        board[idx] = (idx * 17) & 0xFF; // deterministic non-zero pattern
    }

    // Ensure initial symmetry by mirroring values in valid region
    for (int i_idx = 0; i_idx < board_size; i_idx++) {
        for (int j_idx = 0; j_idx < board_size; j_idx++) {
            int base = (19 + 2) + i_idx * (19 + 1) + j_idx;
            int h_mirror = (19 + 2) + i_idx * (19 + 1) + (board_size - 1 - j_idx);
            int v_mirror = (19 + 2) + (board_size - 1 - i_idx) * (19 + 1) + j_idx;
            int d_mirror = (19 + 2) + (board_size - 1 - j_idx) * (19 + 1) + (board_size - 1 - i_idx);

            // Copy base value to mirrors to enforce symmetry initially
            if (h_mirror < 421) board[h_mirror] = board[base];
            if (v_mirror < 421) board[v_mirror] = board[base];
            if (d_mirror < 421) board[d_mirror] = board[base];
        }
    }

    // Reset loop flags to ensure full traversal
    horizontally_symmetric = 1;
    vertically_symmetric = 1;
    diagonally_symmetric = 1;
}