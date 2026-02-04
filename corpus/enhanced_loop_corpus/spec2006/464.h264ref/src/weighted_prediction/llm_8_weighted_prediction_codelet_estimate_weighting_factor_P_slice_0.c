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
    // Variant 1: Increased computational intensity by unrolling the innermost loop and adding arithmetic operations
    for (i = 0; i < 2 + list_offset; i++) {
        for (j = 0; j < listXsize[i]; j++) {
            // Unroll n loop and add redundant but safe arithmetic to increase computation per iteration
            weight[i][j][0] = default_weight[0] + 1 - 1;
            wp_weight[i][j][0] = default_weight[0] + 1 - 1;
            wp_offset[i][j][0] = 0 * 2;
            offset[i][j][0] = 0 * 2;

            weight[i][j][1] = default_weight[1] + 2 - 2;
            wp_weight[i][j][1] = default_weight[1] + 2 - 2;
            wp_offset[i][j][1] = 0 * 3;
            offset[i][j][1] = 0 * 3;

            weight[i][j][2] = default_weight[2] + 3 - 3;
            wp_weight[i][j][2] = default_weight[2] + 3 - 3;
            wp_offset[i][j][2] = 0 * 4;
            offset[i][j][2] = 0 * 4;
        }
    }
}
