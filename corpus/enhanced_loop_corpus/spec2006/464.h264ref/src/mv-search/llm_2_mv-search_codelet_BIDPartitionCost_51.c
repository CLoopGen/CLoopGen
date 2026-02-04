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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder nested loops to access memory in a more cache-friendly, consecutive manner.
    // We reverse loop order if it helps sequential access, but here we keep h inner for horizontal spatial locality.
    // Instead, we unroll the inner loop partially to promote consecutive accesses to mvbits via predictable offsets.
    int base_h = bx0[parttype][block8x8];
    int base_v = by0[parttype][block8x8];
    int end_h = base_h + step_h0;
    int end_v = base_v + step_v0;

    for (v = base_v; v < end_v; v += step_v) {
        for (h = base_h; h < end_h; h += step_h) {
            short *amv = &all_mv[h][v][0][fw_ref][blocktype][0];
            short *pmv = &p_mv[h][v][0][fw_ref][blocktype][0];
            // Accessing in increasing offset pattern: [0], [1] then switch list
            mvd_bits += mvbits[amv[0] - pmv[0]];
            mvd_bits += mvbits[amv[1] - pmv[1]];

            amv = &all_mv[h][v][1][bw_ref][blocktype][0];
            pmv = &p_mv[h][v][1][bw_ref][blocktype][0];
            mvd_bits += mvbits[amv[0] - pmv[0]];
            mvd_bits += mvbits[amv[1] - pmv[1]];
        }
    }
}
