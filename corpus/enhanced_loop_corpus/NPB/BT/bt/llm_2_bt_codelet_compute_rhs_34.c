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
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        double *rhs_base = &rhs[i][j][k][0];
        double *u_k2 = &u[i][j][k-2][0];
        double *u_k1 = &u[i][j][k-1][0];
        double *u_k  = &u[i][j][k][0];
        for (m = 0; m < 5; m++) {
            rhs_base[m] = rhs_base[m] - dssp * (u_k2[m] - 4. * u_k1[m] + 5. * u_k[m]);
        }
    }
}
}
