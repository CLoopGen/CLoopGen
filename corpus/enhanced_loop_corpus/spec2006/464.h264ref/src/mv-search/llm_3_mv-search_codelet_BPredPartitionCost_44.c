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
    // Variant 2: Strided Memory Access Pattern with Interleaved Updates
    // Instead of iterating h outer and v inner, transpose the loop order to favor different access strides.
    // This changes access pattern from row-major to column-major-like with respect to original data layout.

    int h_start = bx0[parttype][block8x8];
    int h_end = h_start + step_h0;
    int v_start = by0[parttype][block8x8];
    int v_end = v_start + step_v0;

    // Swap nesting: now v is outer, h is inner — creates strided access across 'h' dimension when 'v' varies slowly
    for (v = v_start; v < v_end; v += step_v) {
        for (h = h_start; h < h_end; h += step_h) {
            // Access remains the same but memory stride changes due to loop interchange
            mvd_bits += mvbits[all_mv[h][v][0][fw_ref][blocktype][0] - p_mv[h][v][0][fw_ref][blocktype][0]];
            mvd_bits += mvbits[all_mv[h][v][0][fw_ref][blocktype][1] - p_mv[h][v][0][fw_ref][blocktype][1]];
            mvd_bits += mvbits[all_mv[h][v][1][bw_ref][blocktype][0] - p_mv[h][v][1][bw_ref][blocktype][0]];
            mvd_bits += mvbits[all_mv[h][v][1][bw_ref][blocktype][1] - p_mv[h][v][1][bw_ref][blocktype][1]];
        }
    }
}
