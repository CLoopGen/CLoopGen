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
    // Variant 2: Memory Access Pattern Modification - Strided access with indirect indexing using pointer arithmetic
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 3; j < grid_points[1] - 3; j++) {
            for (k = 1; k < grid_points[2] - 1; k++) {
                double *rhs_base = &rhs[i][j][k][0];
                double *u_base_jm2 = &u[i][j-2][k][0];
                double *u_base_jm1 = &u[i][j-1][k][0];
                double *u_base_j   = &u[i][j  ][k][0];
                double *u_base_jp1 = &u[i][j+1][k][0];
                double *u_base_jp2 = &u[i][j+2][k][0];
                for (m = 0; m < 5; m++) {
                    rhs_base[m] = rhs_base[m] - dssp * (u_base_jm2[m] - 4. * u_base_jm1[m] + 6. * u_base_j[m] - 4. * u_base_jp1[m] + u_base_jp2[m]);
                }
            }
        }
    }
}
