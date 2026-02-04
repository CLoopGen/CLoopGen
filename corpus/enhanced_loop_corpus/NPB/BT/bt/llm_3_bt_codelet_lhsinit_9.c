#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Consecutive memory layout simulation via index flattening
    // Flatten the 3D spatial indices (i,j,k) into a linear index to promote sequential memory writes
    // This improves cache locality by accessing lhs in row-major (C-style) order as much as possible
    int total_i = grid_points[0];
    int total_j = grid_points[1];
    int total_k = grid_points[2];

    for (int idx = 0; idx < total_i * total_j * total_k; idx++) {
        i = idx / (total_j * total_k);          // Recover i
        int rem = idx % (total_j * total_k);
        j = rem / total_k;                      // Recover j
        k = rem % total_k;                      // Recover k

        for (m = 0; m < 5; m++) {
            lhs[i][j][k][1][m][m] = 1.;
        }
    }
}
