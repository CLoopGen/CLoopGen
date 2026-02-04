#include <stdio.h>

extern  int grid_points[3];
extern  double tx2;
extern  double xxcon2;
extern  double xxcon3;
extern  double xxcon4;
extern  double xxcon5;
extern  double dx1tx1;
extern  double dx2tx1;
extern  double dx3tx1;
extern  double dx4tx1;
extern  double dx5tx1;
extern  double c1;
extern  double c2;
extern  double con43;
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern double uijk;
extern double up1;
extern double um1;



void loop(){
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (k = 1; k < grid_points[2] - 1; k++) {
                int ip1 = i + 1;
                int im1 = i - 1;
                uijk = us[i][j][k];
                up1 = us[ip1][j][k];
                um1 = us[im1][j][k];

                double* u_ip1 = u[ip1][j][k];
                double* u_i   = u[i][j][k];
                double* u_im1 = u[im1][j][k];
                double* rhs_ijk = rhs[i][j][k];

                rhs_ijk[0] += dx1tx1 * (u_ip1[0] - 2. * u_i[0] + u_im1[0]) - tx2 * (u_ip1[1] - u_im1[1]);
                rhs_ijk[1] += dx2tx1 * (u_ip1[1] - 2. * u_i[1] + u_im1[1]) + xxcon2 * con43 * (up1 - 2. * uijk + um1) - tx2 * (u_ip1[1] * up1 - u_im1[1] * um1 + (u_ip1[4] - square[ip1][j][k] - u_im1[4] + square[im1][j][k]) * c2);
                rhs_ijk[2] += dx3tx1 * (u_ip1[2] - 2. * u_i[2] + u_im1[2]) + xxcon2 * (vs[ip1][j][k] - 2. * vs[i][j][k] + vs[im1][j][k]) - tx2 * (u_ip1[2] * up1 - u_im1[2] * um1);
                rhs_ijk[3] += dx4tx1 * (u_ip1[3] - 2. * u_i[3] + u_im1[3]) + xxcon2 * (ws[ip1][j][k] - 2. * ws[i][j][k] + ws[im1][j][k]) - tx2 * (u_ip1[3] * up1 - u_im1[3] * um1);
                rhs_ijk[4] += dx5tx1 * (u_ip1[4] - 2. * u_i[4] + u_im1[4]) + xxcon3 * (qs[ip1][j][k] - 2. * qs[i][j][k] + qs[im1][j][k]) + xxcon4 * (up1 * up1 - 2. * uijk * uijk + um1 * um1) + xxcon5 * (u_ip1[4] * rho_i[ip1][j][k] - 2. * u_i[4] * rho_i[i][j][k] + u_im1[4] * rho_i[im1][j][k]) - tx2 * ((c1 * u_ip1[4] - c2 * square[ip1][j][k]) * up1 - (c1 * u_im1[4] - c2 * square[im1][j][k]) * um1);
            }
        }
    }
}
