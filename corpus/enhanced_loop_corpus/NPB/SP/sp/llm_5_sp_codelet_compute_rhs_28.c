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
extern  double u[5][65][65][65];
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double uijk;
extern double up1;
extern double um1;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            uijk = us[i][j][k];
            up1 = us[i + 1][j][k];
            um1 = us[i - 1][j][k];

            double u0_ip1 = u[0][i + 1][j][k];
            double u0_i   = u[0][i][j][k];
            double u0_im1 = u[0][i - 1][j][k];
            double u1_ip1 = u[1][i + 1][j][k];
            double u1_im1 = u[1][i - 1][j][k];
            double u4_ip1 = u[4][i + 1][j][k];
            double u4_im1 = u[4][i - 1][j][k];
            double sq_ip1 = square[i + 1][j][k];
            double sq_im1 = square[i - 1][j][k];
            double rho_ip1 = rho_i[i + 1][j][k];
            double rho_im1 = rho_i[i - 1][j][k];

            rhs[0][i][j][k] += dx1tx1 * (u0_ip1 - 2.0 * u0_i + u0_im1) - tx2 * (u1_ip1 - u1_im1);

            double diff_u1 = u[1][i + 1][j][k] - 2. * u[1][i][j][k] + u[1][i - 1][j][k];
            double conv_term1 = xxcon2 * con43 * (up1 - 2. * uijk + um1);
            double nonlin1 = u1_ip1 * up1 - u1_im1 * um1;
            double source1 = (u4_ip1 - sq_ip1 - u4_im1 + sq_im1) * c2;
            rhs[1][i][j][k] += dx2tx1 * diff_u1 + conv_term1 - tx2 * (nonlin1 + source1);

            rhs[2][i][j][k] += dx3tx1 * (u[2][i + 1][j][k] - 2. * u[2][i][j][k] + u[2][i - 1][j][k]) 
                             + xxcon2 * (vs[i + 1][j][k] - 2. * vs[i][j][k] + vs[i - 1][j][k]) 
                             - tx2 * (u[2][i + 1][j][k] * up1 - u[2][i - 1][j][k] * um1);

            rhs[3][i][j][k] += dx4tx1 * (u[3][i + 1][j][k] - 2. * u[3][i][j][k] + u[3][i - 1][j][k]) 
                             + xxcon2 * (ws[i + 1][j][k] - 2. * ws[i][j][k] + ws[i - 1][j][k]) 
                             - tx2 * (u[3][i + 1][j][k] * up1 - u[3][i - 1][j][k] * um1);

            double lap_qs = qs[i + 1][j][k] - 2. * qs[i][j][k] + qs[i - 1][j][k];
            double nonlin_u4_rho = u4_ip1 * rho_ip1 - 2. * u[4][i][j][k] * rho_i[i][j][k] + u4_im1 * rho_im1;
            double quad_vel = up1 * up1 - 2. * uijk * uijk + um1 * um1;
            double flux4 = (c1 * u4_ip1 - c2 * sq_ip1) * up1 - (c1 * u4_im1 - c2 * sq_im1) * um1;
            rhs[4][i][j][k] += dx5tx1 * (u4_ip1 - 2. * u[4][i][j][k] + u4_im1) 
                             + xxcon3 * lap_qs 
                             + xxcon4 * quad_vel 
                             + xxcon5 * nonlin_u4_rho 
                             - tx2 * flux4;
        }
    }
}
}
