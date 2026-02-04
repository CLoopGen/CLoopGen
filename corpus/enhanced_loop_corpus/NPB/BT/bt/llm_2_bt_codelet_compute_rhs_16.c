#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 1: Change memory access pattern to strided access by unrolling and accessing every other element
    // This modifies the access pattern to be non-consecutive, improving potential for vectorization or cache behavior
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                for (m = 0; m < 5; m += 2) {
                    if (m + 1 < 5) {
                        rhs[i][j][k][m]     = forcing[i][j][k][m];
                        rhs[i][j][k][m + 1] = forcing[i][j][k][m + 1];
                    } else {
                        rhs[i][j][k][m] = forcing[i][j][k][m];
                    }
                }
            }
        }
    }
}
