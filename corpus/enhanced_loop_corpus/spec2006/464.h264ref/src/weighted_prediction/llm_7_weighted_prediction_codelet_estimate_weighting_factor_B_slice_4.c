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
    // Variant 2: Eliminate all loop-carried dependencies and enable full parallelism.
    // Restructure loops to make all iterations independent (no RAW, WAR, WAW).
    // Swap loop order to expose independence and remove potential aliasing issues.

    // Pre-store default_weight locally to avoid repeated memory access (also helps independence)
    int d0 = default_weight[0];
    int d1 = default_weight[1];
    int d2 = default_weight[2];

    for (n = 0; n < 3; n++) {
        for (i = 0; i < 2 + list_offset; i++) {
            int w_val = (n == 0) ? d0 : ((n == 1) ? d1 : d2);
            for (j = 0; j < listXsize[i]; j++) {
                // All writes are independent across i,j,n — no loop-carried deps
                wp_weight[i][j][n] = w_val;
                wp_offset[i][j][n] = 0;
                offset[i][j][n] = 0;
                weight[i][j][n] = w_val;
                // No reuse of written values within the loop body -> no data dependencies
            }
        }
    }
}
