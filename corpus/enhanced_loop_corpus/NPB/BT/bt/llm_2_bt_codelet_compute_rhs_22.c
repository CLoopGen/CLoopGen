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
for (j = 1; j < grid_points[1] - 1; j++) {
    for (k = 1; k < grid_points[2] - 1; k++) {
        double *rhs_ptr = &rhs[i][j][k][0];
        const double *u_im2 = &u[i-2][j][k][0];
        const double *u_im1 = &u[i-1][j][k][0];
        const double *u_i   = &u[i][j][k][0];
        for (m = 0; m < 5; m++) {
            rhs_ptr[m] = rhs_ptr[m] - dssp * (u_im2[m] - 4. * u_im1[m] + 5. * u_i[m]);
        }
    }
}
}
