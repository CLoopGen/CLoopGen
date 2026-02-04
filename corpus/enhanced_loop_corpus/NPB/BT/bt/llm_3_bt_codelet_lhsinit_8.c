#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int n;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Strided access with indirect indexing via pointer arithmetic
    // We use a flattened pointer view of the lhs array to perform strided zeroing, stepping through memory with fixed strides
    // This simulates a more indirect, strided access pattern while still zeroing the same elements.
    double (*base)[65][65][3][5][5] = lhs;
    int total_i = grid_points[0];
    int total_j = grid_points[1];
    int total_k = grid_points[2];

    for (i = 0; i < total_i; i++) {
        for (j = 0; j < total_j; j++) {
            for (k = 0; k < total_k; k++) {
                for (m = 0; m < 5; m++) {
                    for (n = 0; n < 5; n++) {
                        // Access using explicit pointer arithmetic to enforce strided pattern
                        double *target0 = &base[i][j][k][0][m][n];
                        double *target1 = &base[i][j][k][1][m][n];
                        double *target2 = &base[i][j][k][2][m][n];
                        *target0 = 0.;
                        *target1 = 0.;
                        *target2 = 0.;
                    }
                }
            }
        }
    }
}
