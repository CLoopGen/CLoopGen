#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int ref;
extern int bw_ref;
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
    // Variant 2: Strided Memory Access Pattern with Index Vectorization
    // Simulate strided access by unrolling the inner loop and accessing elements with fixed stride.
    // This variant assumes that jj - j0 is a multiple of 2 for simplicity, but works generally.
    for (j = j0; j < jj; j += 2) {
        for (i = i0; i < ii; i++) {
            // Even index j
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][ref][mode][0];
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][ref][mode][1];
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][ref][mode][0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][ref][mode][1];
            all_mv8x8[dir][1][i][j][0] = all_mv[i][j][1][bw_ref][mode][0];
            all_mv8x8[dir][1][i][j][1] = all_mv[i][j][1][bw_ref][mode][1];
            pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0];
            pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1];

            // Odd index j+1, if within bounds
            if (j + 1 < jj) {
                all_mv8x8[dir][0][i][j+1][0] = all_mv[i][j+1][0][ref][mode][0];
                all_mv8x8[dir][0][i][j+1][1] = all_mv[i][j+1][0][ref][mode][1];
                pred_mv8x8[dir][0][i][j+1][0] = pred_mv[i][j+1][0][ref][mode][0];
                pred_mv8x8[dir][0][i][j+1][1] = pred_mv[i][j+1][0][ref][mode][1];
                all_mv8x8[dir][1][i][j+1][0] = all_mv[i][j+1][1][bw_ref][mode][0];
                all_mv8x8[dir][1][i][j+1][1] = all_mv[i][j+1][1][bw_ref][mode][1];
                pred_mv8x8[dir][1][i][j+1][0] = pred_mv[i][j+1][1][bw_ref][mode][0];
                pred_mv8x8[dir][1][i][j+1][1] = pred_mv[i][j+1][1][bw_ref][mode][1];
            }
        }
    }
}
