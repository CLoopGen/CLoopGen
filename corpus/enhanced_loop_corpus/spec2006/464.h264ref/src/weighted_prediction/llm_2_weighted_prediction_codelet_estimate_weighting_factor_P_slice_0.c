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
extern int weight[2][15][3];
extern int offset[2][15][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Flatten the 3D access into a single loop with sequential memory traversal
    // This improves cache locality by accessing memory in increasing order
    
    int idx, i_end = 2 + list_offset;
    for (idx = 0; idx < i_end * 15 * 3; idx++) {
        i = idx / (15 * 3);
        j = (idx / 3) % 15;
        n = idx % 3;

        if (i >= 2 + list_offset || j >= listXsize[i]) continue;

        weight[i][j][n] = default_weight[n];
        wp_weight[i][j][n] = default_weight[n];
        wp_offset[i][j][n] = 0;
        offset[i][j][n] = 0;
    }
}
