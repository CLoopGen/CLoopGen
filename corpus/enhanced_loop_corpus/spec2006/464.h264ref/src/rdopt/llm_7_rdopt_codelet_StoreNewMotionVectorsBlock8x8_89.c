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
    // Variant 2: Eliminate apparent dependencies by unrolling and using independent accumulators
    // This variant removes potential false sharing or dependency assumptions by unrolling the inner loop
    // and accessing elements in a non-sequential, strided pattern. No loop-carried dependencies exist.
    // Assumes ii - i0 >= 2 and jj - j0 >= 2 for safe unrolling (bounds checks omitted for clarity).
    int i_end = ii - (ii - i0) % 2;
    int j_end = jj - (jj - j0) % 2;

    for (j = j0; j < j_end; j += 2) {
        for (i = i0; i < i_end; i += 2) {
            // Unroll [i][j], [i][j+1], [i+1][j], [i+1][j+1]
            all_mv8x8[dir][0][i  ][j  ][0] = 0;
            all_mv8x8[dir][0][i  ][j  ][1] = 0;
            all_mv8x8[dir][0][i  ][j+1][0] = 0;
            all_mv8x8[dir][0][i  ][j+1][1] = 0;
            all_mv8x8[dir][0][i+1][j  ][0] = 0;
            all_mv8x8[dir][0][i+1][j  ][1] = 0;
            all_mv8x8[dir][0][i+1][j+1][0] = 0;
            all_mv8x8[dir][0][i+1][j+1][1] = 0;
        }
    }

    // Handle remaining iterations if any
    for (; j < jj; j++)
        for (i = i0; i < ii; i++) {
            all_mv8x8[dir][0][i][j][0] = 0;
            all_mv8x8[dir][0][i][j][1] = 0;
        }
}
