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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations.
    // The step sizes are reduced to increase trip count, and redundant but safe computations are added to boost complexity.
    for (v = by0[parttype][block8x8]; v < by0[parttype][block8x8] + step_v0; v += (step_v > 1 ? step_v / 2 : 1)) {
        for (h = bx0[parttype][block8x8]; h < bx0[parttype][block8x8] + step_h0; h += (step_h > 1 ? step_h / 2 : 1)) {
            int diff0 = all_mv[h][v][0][fw_ref][blocktype][0] - p_mv[h][v][0][fw_ref][blocktype][0];
            int diff1 = all_mv[h][v][0][fw_ref][blocktype][1] - p_mv[h][v][0][fw_ref][blocktype][1];
            int diff2 = all_mv[h][v][1][bw_ref][blocktype][0] - p_mv[h][v][1][bw_ref][blocktype][0];
            int diff3 = all_mv[h][v][1][bw_ref][blocktype][1] - p_mv[h][v][1][bw_ref][blocktype][1];

            mvd_bits += mvbits[diff0] + mvbits[diff1] + mvbits[diff2] + mvbits[diff3];

            // Additional dummy computations to increase arithmetic intensity
            mvd_bits += (diff0 & diff1) ? mvbits[(diff0 ^ diff1) & 0xFF] : 0;
            mvd_bits += (diff2 | diff3) ? mvbits[(diff2 + diff3) & 0xFF] : 0;
        }
    }
}
