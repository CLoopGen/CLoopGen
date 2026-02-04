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
for (i = 0; i < 2 + list_offset; i++) {
    for (j = 0; j < listXsize[i]; j++) {
        wp_weight[i][j][0] = default_weight[0];
        wp_offset[i][j][0] = 0;
        offset[i][j][0] = 0;
        weight[i][j][0] = default_weight[0];
        
        wp_weight[i][j][1] = default_weight[1];
        wp_offset[i][j][1] = 0;
        offset[i][j][1] = 0;
        weight[i][j][1] = default_weight[1];
        
        wp_weight[i][j][2] = default_weight[2];
        wp_offset[i][j][2] = 0;
        offset[i][j][2] = 0;
        weight[i][j][2] = default_weight[2];
    }
}
}
