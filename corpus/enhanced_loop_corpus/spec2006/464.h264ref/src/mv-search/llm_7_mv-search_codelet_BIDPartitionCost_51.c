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
    int local_mvd_bits = mvd_bits;
    for (v = by0[parttype][block8x8]; v < by0[parttype][block8x8] + step_v0; v += step_v) {
        int row_accum = 0;
        for (h = bx0[parttype][block8x8]; h < bx0[parttype][block8x8] + step_h0; h += step_h) {
            row_accum += mvbits[all_mv[h][v][0][fw_ref][blocktype][0] - p_mv[h][v][0][fw_ref][blocktype][0]];
            row_accum += mvbits[all_mv[h][v][0][fw_ref][blocktype][1] - p_mv[h][v][0][fw_ref][blocktype][1]];
            row_accum += mvbits[all_mv[h][v][1][bw_ref][blocktype][0] - p_mv[h][v][1][bw_ref][blocktype][0]];
            row_accum += mvbits[all_mv[h][v][1][bw_ref][blocktype][1] - p_mv[h][v][1][bw_ref][blocktype][1]];
        }
        local_mvd_bits += row_accum;
    }
    mvd_bits = local_mvd_bits;
}
