#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern int dir;
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (j then i), access with a stride by iterating over a linear index
    // and computing i and j using striding to create non-consecutive memory accesses.
    int stride = 2;
    int total_i = ii - i0;
    int total_j = jj - j0;
    int size = total_i * total_j;

    for (int idx = 0; idx < size; idx += stride) {
        int flat_idx = idx % size;
        int i_local = flat_idx / total_j;
        int j_local = flat_idx % total_j;
        i = i0 + i_local;
        j = j0 + j_local;
        all_mv8x8[dir][0][i][j][0] = 0;
        all_mv8x8[dir][0][i][j][1] = 0;
    }

    // Handle any remaining elements if size is not divisible by stride
    for (int idx = size - (size % stride); idx < size; idx++) {
        int i_local = idx / total_j;
        int j_local = idx % total_j;
        i = i0 + i_local;
        j = j0 + j_local;
        all_mv8x8[dir][0][i][j][0] = 0;
        all_mv8x8[dir][0][i][j][1] = 0;
    }
}
