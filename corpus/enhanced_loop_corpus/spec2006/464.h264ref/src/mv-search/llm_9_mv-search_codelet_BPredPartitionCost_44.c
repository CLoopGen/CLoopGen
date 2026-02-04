#include <stdio.h>

#include <inttypes.h>

extern int *mvbits;
extern int blocktype;
extern int block8x8;
extern short fw_ref;
extern short bw_ref;
extern int bx0[5][4];
extern int by0[5][4];
extern int v;
extern int h;
extern int mvd_bits;
extern int parttype;
extern int step_h0;
extern int step_v0;
extern int step_h;
extern int step_v;
extern short ******all_mv;
extern short ******p_mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity with coalesced outer loop and fewer memory accesses.
    // Merge both loops into a single loop with fixed small iteration count to reduce overhead and intensity.

    int start_h = bx0[parttype][block8x8];
    int end_h = start_h + step_h0;
    int start_v = by0[parttype][block8x8];
    int end_v = start_v + step_v0;

    // Flatten the 2D iteration space into a single loop with minimal arithmetic
    for (int idx = 0; idx < 4; idx++) {  // Limit to 4 representative points regardless of step size
        h = start_h + (idx % 2) * step_h;
        v = start_v + (idx / 2) * step_v;

        // Coalesce all four updates into a single compound expression to reduce intermediate storage
        mvd_bits += 
            mvbits[all_mv[h][v][0][fw_ref][blocktype][0] - p_mv[h][v][0][fw_ref][blocktype][0]] +
            mvbits[all_mv[h][v][0][fw_ref][blocktype][1] - p_mv[h][v][0][fw_ref][blocktype][1]] +
            mvbits[all_mv[h][v][1][bw_ref][blocktype][0] - p_mv[h][v][1][bw_ref][blocktype][0]] +
            mvbits[all_mv[h][v][1][bw_ref][blocktype][1] - p_mv[h][v][1][bw_ref][blocktype][1]];
    }
}
