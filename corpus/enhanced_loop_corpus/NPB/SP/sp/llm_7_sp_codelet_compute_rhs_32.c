#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
double dssp_local = dssp;
for (m = 0; m < 5; m++) {
    double rhs_val, u_im2, u_im1, u_i, u_ip1;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            u_im2 = u[m][i - 2][j][k];
            u_im1 = u[m][i - 1][j][k];
            u_i   = u[m][i][j][k];
            u_ip1 = u[m][i + 1][j][k];
            rhs_val = u_im2 - 4. * u_im1 + 6. * u_i - 4. * u_ip1;
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp_local * rhs_val;
        }
    }
}
}
