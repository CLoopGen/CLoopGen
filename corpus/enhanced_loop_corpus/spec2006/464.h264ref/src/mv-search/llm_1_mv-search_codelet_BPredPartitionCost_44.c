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
    // Variant 2: Decreased loop nesting depth by unrolling the inner loop logic into a single loop
    // The original double loop is flattened into one loop that iterates over both v and h manually
    int total_elements = ((step_v0 + step_v - 1) / step_v) * ((step_h0 + step_h - 1) / step_h);
    int idx;
    for (idx = 0; idx < total_elements; ++idx) {
        v = by0[parttype][block8x8] + (idx / ((step_h0 + step_h - 1) / step_h)) * step_v;
        h = bx0[parttype][block8x8] + (idx % ((step_h0 + step_h - 1) / step_h)) * step_h;

        mvd_bits += mvbits[all_mv[h][v][0][fw_ref][blocktype][0] - p_mv[h][v][0][fw_ref][blocktype][0]];
        mvd_bits += mvbits[all_mv[h][v][0][fw_ref][blocktype][1] - p_mv[h][v][0][fw_ref][blocktype][1]];
        mvd_bits += mvbits[all_mv[h][v][1][bw_ref][blocktype][0] - p_mv[h][v][1][bw_ref][blocktype][0]];
        mvd_bits += mvbits[all_mv[h][v][1][bw_ref][blocktype][1] - p_mv[h][v][1][bw_ref][blocktype][1]];
    }
}
