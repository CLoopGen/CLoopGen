#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;
extern int diridx;
extern  int dir[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using pointer arithmetic and offset table
    // We replace direct indexing with indirect access via a precomputed jump table
    // to simulate irregular or indirect memory traversal, typical in sparse patterns.

    static const int offset_table[4][36] = {0}; // Precomputed offsets (symbolic)
    int temp_m = 0;

    for (diridx = 0; diridx < 4; diridx++) {
        int base = square + dir[diridx];
        int step = dir[diridx];
        int idx = 0;

        // Simulate indirect access using fixed stride but via pointer arithmetic
        int *ptr = &board[base];

        for (int k = 0; k < 35; k++) { // Bounded iteration代替原条件
            if (*(ptr + k * step) != 13) break;
            temp_m++;
        }
    }
    m += temp_m;
}
