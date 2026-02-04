#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
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
    // Variant 2: Strided memory access with indirect indexing using pointer arithmetic
    // Simulates non-unit stride access by stepping through indices with a fixed stride.
    const int stride = 2;
    for (int j_step = 0; j0 + j_step < jj; j_step += stride) {
        for (int i_step = 0; i0 + i_step < ii; i_step += stride) {
            int curr_i = i0 + i_step;
            int curr_j = j0 + j_step;

            // Access current and next elements if within bounds (unrolled-like behavior)
            for (int sj = 0; sj < stride && curr_j + sj < jj; ++sj) {
                for (int si = 0; si < stride && curr_i + si < ii; ++si) {
                    int effective_i = curr_i + si;
                    int effective_j = curr_j + sj;

                    all_mv[effective_i][effective_j][1][bw_ref][mode][0] = all_mv8x8[dir][1][effective_i][effective_j][0];
                    all_mv[effective_i][effective_j][1][bw_ref][mode][1] = all_mv8x8[dir][1][effective_i][effective_j][1];
                    pred_mv[effective_i][effective_j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][effective_i][effective_j][0];
                    pred_mv[effective_i][effective_j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][effective_i][effective_j][1];
                }
            }
        }
    }
}
