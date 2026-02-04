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
    for (i = 0; i < 2 + list_offset; i++) {
        for (n = 0; n < 3; n++) {
            int base_weight = default_weight;
            int base_offset = 0;
            for (j = 0; j < listXsize[i]; j++) {
                weight[i][j][n] = base_weight;
                wp_weight[i][j][n] = base_weight;
                wp_offset[i][j][n] = base_offset;
                offset[i][j][n] = base_offset;
                // Introduce WAW dependency artificially by reassigning in a chain
                base_weight = wp_weight[i][j][n] + 1;
            }
        }
    }
}
