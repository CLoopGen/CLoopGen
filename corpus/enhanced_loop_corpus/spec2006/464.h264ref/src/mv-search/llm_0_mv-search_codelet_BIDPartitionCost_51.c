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
for (v = by0[parttype][block8x8]; v < by0[parttype][block8x8] + step_v0; v += step_v)
    for (h = bx0[parttype][block8x8]; h < bx0[parttype][block8x8] + step_h0; h += step_h)
        for (int ref_idx = 0; ref_idx < 2; ref_idx++) {
            int ref = (ref_idx == 0) ? fw_ref : bw_ref;
            int dir = ref_idx;
            mvd_bits += mvbits[all_mv[h][v][dir][ref][blocktype][0] - p_mv[h][v][dir][ref][blocktype][0]];
            mvd_bits += mvbits[all_mv[h][v][dir][ref][blocktype][1] - p_mv[h][v][dir][ref][blocktype][1]];
        }
}
