#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int _usr_index;
extern int comp;
extern int list_offset;
extern int weight[6][15][3];
extern int offset[6][15][3];
extern int clist;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Consecutive Memory Access via Linear Indexing
    // Flatten the 3D access pattern into a linear traversal by precomputing effective indices
    // to promote better cache locality and enable potential vectorization.
    int flat_index = 0;
    int total_elements = 0;

    // Pre-calculate total number of operations for flat traversal
    for (int c = 0; c < 2 + list_offset; c++) {
        total_elements += listXsize[c] * 3; // each index has 3 components
    }

    for (flat_index = 0; flat_index < total_elements; flat_index++) {
        int c = 0;
        int remainder = flat_index;
        // Determine which clist this flat index belongs to
        int accumulated = 0;
        for (c = 0; c < 2 + list_offset; c++) {
            int segment_size = listXsize[c] * 3;
            if (remainder < accumulated + segment_size) {
                break;
            }
            accumulated += segment_size;
        }
        int local_offset = remainder - accumulated;
        int idx = local_offset / 3;      // which index in the list
        int comp = local_offset % 3;       // which component

        wp_weight[c][idx][comp] = weight[c][idx][comp];
        wp_offset[c][idx][comp] = offset[c][idx][comp];
    }
}
