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
    // Variant 2: Memory Access Pattern Modification - Strided access with reversed loop order
    // Access pattern changed to iterate over 'n' first, then 'i', then 'j' (strided in original layout)
    for (n = 0; n < 3; n++) {
        for (i = 0; i < 2 + list_offset; i++) {
            for (j = 0; j < listXsize[i]; j++) {
                weight[i][j][n] = default_weight;
                wp_weight[i][j][n] = default_weight;
                offset[i][j][n] = 0;
                wp_offset[i][j][n] = 0;
            }
        }
    }
}
