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
            double u_temp[5];
            double up1 = us[i + 1][j][k];
            double um1 = us[i - 1][j][k];
            double uijk = us[i][j][k];

            // Load current u values to break write-after-read dependencies in accumulation
            for (int m = 0; m < 5; m++) {
                u_temp[m] = u[i][j][k][m];
            }

            // Introduce temporary variables to eliminate redundant memory reads and create local data reuse
            double diff_x1 = u[i + 1][j][k][0] - 2.0 * u_temp[0] + u[i - 1][j][k][0];
            double conv_0 = tx2 * (u[i + 1][j][k][1] - u[i - 1][j][k][1]);

            rhs[i][j][k][0] += dx1tx1 * diff_x1 - conv_0;

            double diff_u = up1 - 2.0 * uijk + um1;
            double diff_v = vs[i + 1][j][k] - 2.0 * vs[i][j][k] + vs[i - 1][j][k];
            double diff_w = ws[i + 1][j][k] - 2.0 * ws[i][j][k] + ws[i - 1][j][k];
            double diff_q = qs[i + 1][j][k] - 2.0 * qs[i][j][k] + qs[i - 1][j][k];
            double diff_e = u[i + 1][j][k][4] - 2.0 * u_temp[4] + u[i - 1][j][k][4];
            double diff_rho_i = u[i + 1][j][k][4] * rho_i[i + 1][j][k] - 2.0 * u_temp[4] * rho_i[i][j][k] + u[i - 1][j][k][4] * rho_i[i - 1][j][k];

            double conv_1 = tx2 * (u[i + 1][j][k][1] * up1 - u[i - 1][j][k][1] * um1 + (u[i + 1][j][k][4] - square[i + 1][j][k] - u[i - 1][j][k][4] + square[i - 1][j][k]) * c2);
            double conv_2 = tx2 * (u[i + 1][j][k][2] * up1 - u[i - 1][j][k][2] * um1);
            double conv_3 = tx2 * (u[i + 1][j][k][3] * up1 - u[i - 1][j][k][3] * um1);
            double conv_4 = tx2 * ((c1 * u[i + 1][j][k][4] - c2 * square[i + 1][j][k]) * up1 - (c1 * u[i - 1][j][k][4] - c2 * square[i - 1][j][k]) * um1);

            double sq_diff = xxcon4 * (up1 * up1 - 2.0 * uijk * uijk + um1 * um1);

            rhs[i][j][k][1] += dx2tx1 * (u[i + 1][j][k][1] - 2.0 * u_temp[1] + u[i - 1][j][k][1]) + 
                               xxcon2 * con43 * diff_u - conv_1;
            rhs[i][j][k][2] += dx3tx1 * (u[i + 1][j][k][2] - 2.0 * u_temp[2] + u[i - 1][j][k][2]) + 
                               xxcon2 * diff_v - conv_2;
            rhs[i][j][k][3] += dx4tx1 * (u[i + 1][j][k][3] - 2.0 * u_temp[3] + u[i - 1][j][k][3]) + 
                               xxcon2 * diff_w - conv_3;
            rhs[i][j][k][4] += dx5tx1 * diff_e + xxcon3 * diff_q + sq_diff + 
                               xxcon5 * diff_rho_i - conv_4;
        }
    }
}
}
