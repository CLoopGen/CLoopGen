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
    // Variant 2: Memory Access Pattern Modification - Strided Access with Fixed Increments
    // Simulate strided access by jumping through higher dimensions first
    // We reverse the loop order to create a different memory traversal pattern

    // Precompute base pointers to avoid redundant indexing
    int (*w_base)[15][3] = weight;
    int (*o_base)[15][3] = offset;

    for (n = 0; n < 3; n++) {  // Outermost: loop over n (strided access across n)
        int dw = default_weight[n];
        for (i = 0; i < 2 + list_offset; i++) {
            for (j = 0; j < listXsize[i]; j++) {
                // Stride through the 'n' dimension first, accessing every 3rd element effectively
                w_base[i][j][n] = dw;
                o_base[i][j][n] = 0;
                wp_weight[i][j][n] = dw;
                wp_offset[i][j][n] = 0;
            }
        }
    }
}
