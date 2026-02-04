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
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating in natural order, access elements with a stride of 2,
    // and handle remaining elements in a second pass to maintain correctness.
    int stride = 2;
    int j_start = j0;

    // First pass: strided access
    for (j = j_start; j < jj; j += stride)
        for (i = i0; i < ii; i++) {
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][ref][4][0];
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][ref][4][1];
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][ref][4][0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][ref][4][1];
        }

    // Second pass: handle odd indices if stride caused misses
    for (j = j_start + 1; j < jj; j += stride)
        for (i = i0; i < ii; i++) {
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][ref][4][0];
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][ref][4][1];
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][ref][4][0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][ref][4][1];
        }
}
