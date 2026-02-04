#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int ref;
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int ii;
extern int jj;
extern short ******all_mv;
extern short ******pred_mv;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 2: Eliminate potential loop-carried dependencies by unrolling and reordering operations
    // Each iteration becomes independent, enabling better vectorization and parallelization
    // No data dependency between consecutive iterations (fully parallelizable)

    // Perform full unroll simulation via direct assignment if bounds are small and known
    // Here we assume ii-i0 and jj-j0 are divisible by 2 for simplicity of unrolling
    int stride_i = 2;
    int stride_j = 2;

    for (j = j0; j < jj; j += stride_j) {
        for (i = i0; i < ii; i += stride_i) {
            // Unroll inner loop partially to eliminate address recalculation overhead
            // and make independence explicit

            // Block 1: (i,j)
            if (i < ii && j < jj) {
                all_mv[i][j][0][ref][4][0] = all_mv8x8[dir][0][i][j][0];
                all_mv[i][j][0][ref][4][1] = all_mv8x8[dir][0][i][j][1];
                pred_mv[i][j][0][ref][4][0] = pred_mv8x8[dir][0][i][j][0];
                pred_mv[i][j][0][ref][4][1] = pred_mv8x8[dir][0][i][j][1];
            }

            // Block 2: (i+1,j)
            if (i+1 < ii && j < jj) {
                all_mv[i+1][j][0][ref][4][0] = all_mv8x8[dir][0][i+1][j][0];
                all_mv[i+1][j][0][ref][4][1] = all_mv8x8[dir][0][i+1][j][1];
                pred_mv[i+1][j][0][ref][4][0] = pred_mv8x8[dir][0][i+1][j][0];
                pred_mv[i+1][j][0][ref][4][1] = pred_mv8x8[dir][0][i+1][j][1];
            }

            // Block 3: (i,j+1)
            if (i < ii && j+1 < jj) {
                all_mv[i][j+1][0][ref][4][0] = all_mv8x8[dir][0][i][j+1][0];
                all_mv[i][j+1][0][ref][4][1] = all_mv8x8[dir][0][i][j+1][1];
                pred_mv[i][j+1][0][ref][4][0] = pred_mv8x8[dir][0][i][j+1][0];
                pred_mv[i][j+1][0][ref][4][1] = pred_mv8x8[dir][0][i][j+1][1];
            }

            // Block 4: (i+1,j+1)
            if (i+1 < ii && j+1 < jj) {
                all_mv[i+1][j+1][0][ref][4][0] = all_mv8x8[dir][0][i+1][j+1][0];
                all_mv[i+1][j+1][0][ref][4][1] = all_mv8x8[dir][0][i+1][j+1][1];
                pred_mv[i+1][j+1][0][ref][4][0] = pred_mv8x8[dir][0][i+1][j+1][0];
                pred_mv[i+1][j+1][0][ref][4][1] = pred_mv8x8[dir][0][i+1][j+1][1];
            }
        }
    }
}
