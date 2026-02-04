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
            // Reverse access pattern to introduce anti-dependence (WAR) via delayed write
            int ip1 = i + 1;
            int im1 = i - 1;

            // Precompute nonlinear terms to reduce repeated loads and create local data reuse
            double uijkm1_1 = u[im1][j][k][1];
            double uip1m1_1 = u[ip1][j][k][1];
            double uijkm1_2 = u[im1][j][k][2];
            double uip1m1_2 = u[ip1][j][k][2];
            double uijkm1_3 = u[im1][j][k][3];
            double uip1m1_3 = u[ip1][j][k][3];
            double uijkm1_4 = u[im1][j][k][4];
            double uip1m1_4 = u[ip1][j][k][4];
            double sq_im1 = square[im1][j][k];
            double sq_ip1 = square[ip1][j][k];
            double rho_im1 = rho_i[im1][j][k];
            double rho_ip1 = rho_i[ip1][j][k];
            double vs_im1 = vs[im1][j][k];
            double vs_ip1 = vs[ip1][j][k];
            double ws_im1 = ws[im1][j][k];
            double ws_ip1 = ws[ip1][j][k];
            double qs_im1 = qs[im1][j][k];
            double qs_ip1 = qs[ip1][j][k];
            double us_im1 = us[im1][j][k];
            double us_ip1 = us[ip1][j][k];

            // Staged computation: split diffusion and convection to modify dependency chain
            double diff_0 = dx1tx1 * (uip1m1_1 - 2.0 * u[i][j][k][0] + uijkm1_1);
            double conv_0 = tx2 * (uip1m1_1 - uijkm1_1);
            rhs[i][j][k][0] += diff_0 - conv_0;

            double diff_1 = dx2tx1 * (uip1m1_1 - 2.0 * u[i][j][k][1] + uijkm1_1);
            double nonlin_1 = xxcon2 * con43 * (us_ip1 - 2.0 * us[i][j][k] + us_im1);
            double conv_1 = tx2 * (uip1m1_1 * us_ip1 - uijkm1_1 * us_im1 + 
                                  (uip1m1_4 - sq_ip1 - uijkm1_4 + sq_im1) * c2);
            rhs[i][j][k][1] += diff_1 + nonlin_1 - conv_1;

            double diff_2 = dx3tx1 * (uip1m1_2 - 2.0 * u[i][j][k][2] + uijkm1_2);
            double nonlin_2 = xxcon2 * (vs_ip1 - 2.0 * vs[i][j][k] + vs_im1);
            double conv_2 = tx2 * (uip1m1_2 * us_ip1 - uijkm1_2 * us_im1);
            rhs[i][j][k][2] += diff_2 + nonlin_2 - conv_2;

            double diff_3 = dx4tx1 * (uip1m1_3 - 2.0 * u[i][j][k][3] + uijkm1_3);
            double nonlin_3 = xxcon2 * (ws_ip1 - 2.0 * ws[i][j][k] + ws_im1);
            double conv_3 = tx2 * (uip1m1_3 * us_ip1 - uijkm1_3 * us_im1);
            rhs[i][j][k][3] += diff_3 + nonlin_3 - conv_3;

            double diff_4 = dx5tx1 * (uip1m1_4 - 2.0 * u[i][j][k][4] + uijkm1_4);
            double nonlin_4a = xxcon3 * (qs_ip1 - 2.0 * qs[i][j][k] + qs_im1);
            double nonlin_4b = xxcon4 * (us_ip1 * us_ip1 - 2.0 * us[i][j][k] * us[i][j][k] + us_im1 * us_im1);
            double nonlin_4c = xxcon5 * (uip1m1_4 * rho_ip1 - 2.0 * u[i][j][k][4] * rho_i[i][j][k] + uijkm1_4 * rho_im1);
            double conv_4 = tx2 * ((c1 * uip1m1_4 - c2 * sq_ip1) * us_ip1 - (c1 * uijkm1_4 - c2 * sq_im1) * us_im1);
            rhs[i][j][k][4] += diff_4 + nonlin_4a + nonlin_4b + nonlin_4c - conv_4;
        }
    }
}
}
