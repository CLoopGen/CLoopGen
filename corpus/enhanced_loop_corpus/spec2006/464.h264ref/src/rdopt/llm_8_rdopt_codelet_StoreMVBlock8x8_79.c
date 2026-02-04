#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Loop bounds adjusted to process two elements per iteration, reducing trip count but increasing work per iteration
    for (j = j0; j < jj; j += 2) {
        for (i = i0; i < ii; i += 2) {
            // Process a 2x2 block to increase data reuse and operation density
            for (int dj = 0; dj < 2 && (j + dj) < jj; ++dj) {
                for (int di = 0; di < 2 && (i + di) < ii; ++di) {
                    int ci = i + di;
                    int cj = j + dj;
                    // Additional arithmetic: offset adjustment using XOR pattern (no side effects, just complexity)
                    int offset = (ci ^ cj) & 1;
                    all_mv8x8[dir][0][ci][cj][0] = all_mv[ci][cj][0][ref][mode][0] + offset - offset;
                    all_mv8x8[dir][0][ci][cj][1] = all_mv[ci][cj][0][ref][mode][1] + offset - offset;
                    pred_mv8x8[dir][0][ci][cj][0] = pred_mv[ci][cj][0][ref][mode][0] + offset - offset;
                    pred_mv8x8[dir][0][ci][cj][1] = pred_mv[ci][cj][0][ref][mode][1] + offset - offset;
                }
            }
        }
    }
}
