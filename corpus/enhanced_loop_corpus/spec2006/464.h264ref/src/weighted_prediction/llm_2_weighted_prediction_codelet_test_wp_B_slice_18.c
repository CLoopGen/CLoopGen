#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int default_weight;
extern int list_offset;
extern int clist;
extern int perform_wp;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing wp_weight[clist][index][comp] in natural order,
    // we access with a fixed stride of 2 across the 'index' dimension, wrapping when necessary.
    // This creates a strided access pattern to simulate non-contiguous memory traversal.

    int stride = 2;
    for (clist = 0; clist < 2 + list_offset; clist++) {
        if (listXsize[clist] == 0) continue;
        for (index = 0; index < listXsize[clist]; index += stride) {
            for (comp = 0; comp < 3; comp++) {
                int actual_index = index + comp; // Introduce indirect-like offset within bounds
                if (actual_index >= listXsize[clist]) actual_index = listXsize[clist] - 1;

                if (wp_weight[clist][actual_index][comp] != default_weight || 
                    wp_offset[clist][actual_index][comp] != 0) {
                    perform_wp = 1;
                    goto exit_loops_1;
                }
            }
        }
    }
    return;

exit_loops_1:;
}
