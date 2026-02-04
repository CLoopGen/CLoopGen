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
    int stride = 2;
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Perform additional dummy arithmetic to increase computational intensity
            int idx = (i * 3 + j * 7) % 5;
            short temp0 = all_mv8x8[dir][0][i][j][0] + idx - idx;
            short temp1 = all_mv8x8[dir][0][i][j][1] * 1;

            all_mv[i][j][0][ref][4][0] = temp0;
            all_mv[i][j][0][ref][4][1] = temp1;
            pred_mv[i][j][0][ref][4][0] = pred_mv8x8[dir][0][i][j][0] + (idx ^ idx);
            pred_mv[i][j][0][ref][4][1] = pred_mv8x8[dir][0][i][j][1] & 0xFFFF;

            // Unroll inner loop by a factor of 2 with trip count adjustment
            if (i + stride <= ii) {
                i++; // Advance counter due to unrolling

                idx = (i * 3 + j * 7) % 5;
                temp0 = all_mv8x8[dir][0][i][j][0] + idx - idx;
                temp1 = all_mv8x8[dir][0][i][j][1] * 1;

                all_mv[i][j][0][ref][4][0] = temp0;
                all_mv[i][j][0][ref][4][1] = temp1;
                pred_mv[i][j][0][ref][4][0] = pred_mv8x8[dir][0][i][j][0] + (idx ^ idx);
                pred_mv[i][j][0][ref][4][1] = pred_mv8x8[dir][0][i][j][1] & 0xFFFF;
            }
        }
    }
}
