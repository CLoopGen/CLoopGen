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
    // Variant 2: Eliminate all loop-carried dependencies by unrolling and reordering operations
    // Split the original statements into independent groups that can be reordered
    // No data dependency between iterations — fully parallelizable

    // Unroll factor of 2 in i and j dimensions (partial unrolling)
    for (j = j0; j < jj; j += 2) {
        for (i = i0; i < ii; i += 2) {
            // Process block (i,j), (i+1,j), (i,j+1), (i+1,j+1) independently
            for (int dj = 0; dj < 2 && (j + dj) < jj; ++dj) {
                for (int di = 0; di < 2 && (i + di) < ii; ++di) {
                    int ci = i + di;
                    int cj = j + dj;

                    // All accesses are independent and no reuse of modified data — no loop-carried dep
                    all_mv[ci][cj][0][ref][mode][0] = all_mv8x8[dir][0][ci][cj][0];
                    all_mv[ci][cj][0][ref][mode][1] = all_mv8x8[dir][0][ci][cj][1];
                    pred_mv[ci][cj][0][ref][mode][0] = pred_mv8x8[dir][0][ci][cj][0];
                    pred_mv[ci][cj][0][ref][mode][1] = pred_mv8x8[dir][0][ci][cj][1];

                    all_mv[ci][cj][1][bw_ref][mode][0] = all_mv8x8[dir][1][ci][cj][0];
                    all_mv[ci][cj][1][bw_ref][mode][1] = all_mv8x8[dir][1][ci][cj][1];
                    pred_mv[ci][cj][1][bw_ref][mode][0] = pred_mv8x8[dir][1][ci][cj][0];
                    pred_mv[ci][cj][1][bw_ref][mode][1] = pred_mv8x8[dir][1][ci][cj][1];
                }
            }
        }
    }
}
