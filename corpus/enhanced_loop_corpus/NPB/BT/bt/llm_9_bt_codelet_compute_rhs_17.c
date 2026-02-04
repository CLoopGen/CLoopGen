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
for (i = 2; i < grid_points[0] - 2; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k += 2) {
            uijk = us[i][j][k];
            up1 = us[i + 1][j][k];
            um1 = us[i - 1][j][k];

            double uim1 = u[i - 1][j][k][0], uip1 = u[i + 1][j][k][0], ui = u[i][j][k][0];
            rhs[i][j][k][0] += dx1tx1 * (uip1 - 2. * ui + uim1) - tx2 * (u[i + 1][j][k][1] - u[i - 1][j][k][1]);

            double vs_diff = vs[i + 1][j][k] - 2. * vs[i][j][k] + vs[i - 1][j][k];
            rhs[i][j][k][2] += dx3tx1 * (u[i + 1][j][k][2] - 2. * u[i][j][k][2] + u[i - 1][j][k][2]) +
                               xxcon2 * vs_diff -
                               tx2 * (u[i + 1][j][k][2] * up1 - u[i - 1][j][k][2] * um1);

            double ws_diff = ws[i + 1][j][k] - 2. * ws[i][j][k] + ws[i - 1][j][k];
            rhs[i][j][k][3] += dx4tx1 * (u[i + 1][j][k][3] - 2. * u[i][j][k][3] + u[i - 1][j][k][3]) +
                               xxcon2 * ws_diff -
                               tx2 * (u[i + 1][j][k][3] * up1 - u[i - 1][j][k][3] * um1);

            double q_diff = qs[i + 1][j][k] - 2. * qs[i][j][k] + qs[i - 1][j][k];
            double u4ip1 = u[i + 1][j][k][4], u4i = u[i][j][k][4], u4im1 = u[i - 1][j][k][4];
            double sqip1 = square[i + 1][j][k], sqim1 = square[i - 1][j][k];
            double rhoip1 = rho_i[i + 1][j][k], rhoi = rho_i[i][j][k], rhoim1 = rho_i[i - 1][j][k];

            rhs[i][j][k][4] += dx5tx1 * (u4ip1 - 2. * u4i + u4im1) +
                               xxcon3 * q_diff +
                               xxcon4 * (up1 * up1 - 2. * uijk * uijk + um1 * um1) +
                               xxcon5 * (u4ip1 * rhoip1 - 2. * u4i * rhoi + u4im1 * rhoim1) -
                               tx2 * ((c1 * u4ip1 - c2 * sqip1) * up1 - (c1 * u4im1 - c2 * sqim1) * um1);
        }
    }
}
}
