#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int fw_ref;
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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access by unrolling the inner loop with a stride of 2,
    // simulating non-unit stride memory accesses, potentially modeling block-based processing.
    int stride = 2;
    for (j = j0; j < jj; j += stride)
        for (i = i0; i < ii; i += stride) {
            // Handle up to 2x2 block with stride, ensuring bounds
            for (int sj = 0; sj < stride && (j + sj) < jj; ++sj)
                for (int si = 0; si < stride && (i + si) < ii; ++si) {
                    int ci = i + si;
                    int cj = j + sj;
                    all_mv8x8[dir][0][ci][cj][0] = all_mv[ci][cj][0][fw_ref][mode][0];
                    all_mv8x8[dir][0][ci][cj][1] = all_mv[ci][cj][0][fw_ref][mode][1];
                    pred_mv8x8[dir][0][ci][cj][0] = pred_mv[ci][cj][0][fw_ref][mode][0];
                    pred_mv8x8[dir][0][ci][cj][1] = pred_mv[ci][cj][0][fw_ref][mode][1];
                }
        }
}
