#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Introduce consecutive array-like access via pointer arithmetic
    // This variant uses pointer arithmetic to promote consecutive memory accesses, improving cache locality
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            // Compute base pointers for current [i][j][k] slice to enable linear access
            double *rhs_base = &rhs[i][j][k][0];
            double *u_base_j   = &u[i][j][k][0];
            double *u_base_jp1 = &u[i][j+1][k][0];
            double *u_base_jp2 = &u[i][j+2][k][0];

            for (m = 0; m < 5; m++) {
                rhs_base[m] = rhs_base[m] - dssp * (5.0 * u_base_j[m] - 4.0 * u_base_jp1[m] + u_base_jp2[m]);
            }
        }
    }
}
