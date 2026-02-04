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
    // Variant 2: Strided Memory Access Pattern with Prefetching Simulation
    // Introduce strided traversal by swapping loop nesting and modifying access pattern.
    // This variant uses vertical-major traversal (v changes fastest), creating a strided access in 'h'.
    // Also simulates potential prefetching benefit by grouping references with fixed stride.

    int base_h = bx0[parttype][block8x8];
    int base_v = by0[parttype][block8x8];
    int end_h = base_h + step_h0;
    int end_v = base_v + step_v0;

    // Swap loop order: make 'h' outer, 'v' inner -> creates stride across h-dimension
    for (h = base_h; h < end_h; h += step_h) {
        for (v = base_v; v < end_v; v += step_v) {
            // Strided access due to outer-loop h: each iteration jumps in memory layout
            mvd_bits += mvbits[all_mv[h][v][0][fw_ref][blocktype][0] - p_mv[h][v][0][fw_ref][blocktype][0]];
            mvd_bits += mvbits[all_mv[h][v][0][fw_ref][blocktype][1] - p_mv[h][v][0][fw_ref][blocktype][1]];
            mvd_bits += mvbits[all_mv[h][v][1][bw_ref][blocktype][0] - p_mv[h][v][1][bw_ref][blocktype][0]];
            mvd_bits += mvbits[all_mv[h][v][1][bw_ref][blocktype][1] - p_mv[h][v][1][bw_ref][blocktype][1]];
        }
    }
}
