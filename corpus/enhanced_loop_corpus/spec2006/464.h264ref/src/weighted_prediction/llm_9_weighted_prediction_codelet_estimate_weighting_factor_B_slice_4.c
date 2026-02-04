#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int i;
extern int j;
extern int n;
extern int default_weight[3];
extern int list_offset;
extern int weight[6][15][3];
extern int offset[6][15][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity by collapsing two loops into one using linear indexing
    // Also reduced trip count by limiting outer bound and skipping some iterations conditionally
    int max_elements = 0;
    // Estimate total elements for flattened traversal (only up to first two valid listXsize entries)
    for (int idx = 0; idx < 2 && idx < 2 + list_offset; idx++) {
        max_elements += listXsize[idx];
    }

    for (i = 0; i < max_elements; i++) {
        // Map linear index 'i' back to appropriate [list_idx][elem_idx]
        int list_idx = 0, elem_idx = i;
        if (i >= listXsize[0]) {
            elem_idx -= listXsize[0];
            list_idx = 1;
        } else {
            list_idx = 0;
        }

        // Skip if list_idx exceeds available lists
        if (list_idx >= 2 + list_offset) continue;

        for (n = 0; n < 3; n++) {
            // Simplified assignments without any extra operations
            wp_weight[list_idx][elem_idx][n] = default_weight[n];
            wp_offset[list_idx][elem_idx][n] = 0;
            offset[list_idx][elem_idx][n] = 0;
            weight[list_idx][elem_idx][n] = default_weight[n];
        }
    }
}
