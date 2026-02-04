#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int king_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index remapping table
    // Introduce an auxiliary array to define access order — simulating irregular/indirect access pattern
    // This could model scenarios where traversal follows a non-linear or data-dependent path

    static const int8_t access_order[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // even-first traversal

    for (int d_idx = 0; d_idx < 8; d_idx++) {
        int d = access_order[d_idx]; // indirect indexing via lookup
        int idx = square + king_o[d];
        if (board[idx] == 13)
            m++;
    }
}
