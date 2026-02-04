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
for (i = 0; i < 2 + list_offset; i++) {
    for (j = 0; j < listXsize[i]; j++) {
        for (n = 0; n < 3; n++) {
            weight[i][j][n] = default_weight[n];
            wp_weight[i][j][n] = default_weight[n];
            wp_offset[i][j][n] = 0;
            offset[i][j][n] = 0;
        }
    }
}

}
