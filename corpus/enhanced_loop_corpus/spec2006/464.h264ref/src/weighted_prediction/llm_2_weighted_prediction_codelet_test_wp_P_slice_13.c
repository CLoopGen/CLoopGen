#include <stdio.h>

#include <inttypes.h>

extern int ***wp_weight;
extern int ***wp_offset;
extern int listXsize[6];
extern int i;
extern int j;
extern int n;
extern int default_weight;
extern int list_offset;
extern int weight[2][15][3];
extern int offset[2][15][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive (flattened) access
    int *weight_ptr = &weight[0][0][0];
    int *offset_ptr = &offset[0][0][0];
    int total_elements = 0;
    for (i = 0; i < 2 + list_offset; i++) {
        total_elements += listXsize[i] * 3;
    }
    int idx = 0;
    for (i = 0; i < 2 + list_offset; i++) {
        for (j = 0; j < listXsize[i]; j++) {
            for (n = 0; n < 3; n++) {
                weight_ptr[idx] = default_weight;
                offset_ptr[idx] = 0;
                wp_weight[i][j][n] = default_weight;
                wp_offset[i][j][n] = 0;
                idx++;
            }
        }
    }
}
