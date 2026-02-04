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
    // Variant 1: Memory Access Pattern Modification - Consecutive Access via Pointer Arithmetic
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            double *rhs_ptr = &rhs[i][j][k][0];
            double *u_k_minus_2 = &u[i][j][k - 2][0];
            double *u_k_minus_1 = &u[i][j][k - 1][0];
            double *u_k         = &u[i][j][k][0];
            double *u_k_plus_1  = &u[i][j][k + 1][0];

            for (m = 0; m < 5; m++) {
                rhs_ptr[m] = rhs_ptr[m] - dssp * (u_k_minus_2[m] - 4. * u_k_minus_1[m] + 6. * u_k[m] - 4. * u_k_plus_1[m]);
            }
        }
    }
}
