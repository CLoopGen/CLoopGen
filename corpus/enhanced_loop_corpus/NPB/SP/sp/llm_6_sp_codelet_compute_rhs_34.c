#include <stdio.h>

extern  int grid_points[3];
extern  double ty2;
extern  double yycon2;
extern  double yycon3;
extern  double yycon4;
extern  double yycon5;
extern  double dy1ty1;
extern  double dy2ty1;
extern  double dy3ty1;
extern  double dy4ty1;
extern  double dy5ty1;
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
extern double vijk;
extern double vp1;
extern double vm1;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            vijk = vs[i][j][k];
            vp1 = vs[i][j + 1][k];
            vm1 = vs[i][j - 1][k];

            double u0_term = dy1ty1 * (u[0][i][j + 1][k] - 2. * u[0][i][j][k] + u[0][i][j - 1][k]);
            double flux0_term = ty2 * (u[2][i][j + 1][k] - u[2][i][j - 1][k]);
            rhs[0][i][j][k] += u0_term - flux0_term;

            double u1_term = dy2ty1 * (u[1][i][j + 1][k] - 2. * u[1][i][j][k] + u[1][i][j - 1][k]);
            double diff_us = yycon2 * (us[i][j + 1][k] - 2. * us[i][j][k] + us[i][j - 1][k]);
            double conv1_term = ty2 * (u[1][i][j + 1][k] * vp1 - u[1][i][j - 1][k] * vm1);
            rhs[1][i][j][k] += u1_term + diff_us - conv1_term;

            double u2_term = dy3ty1 * (u[2][i][j + 1][k] - 2. * u[2][i][j][k] + u[2][i][j - 1][k]);
            double diff_v = yycon2 * con43 * (vp1 - 2. * vijk + vm1);
            double square_diff = (u[4][i][j + 1][k] - square[i][j + 1][k] - u[4][i][j - 1][k] + square[i][j - 1][k]) * c2;
            double conv2_term = ty2 * (u[2][i][j + 1][k] * vp1 - u[2][i][j - 1][k] * vm1 + square_diff);
            rhs[2][i][j][k] += u2_term + diff_v - conv2_term;

            double u3_term = dy4ty1 * (u[3][i][j + 1][k] - 2. * u[3][i][j][k] + u[3][i][j - 1][k]);
            double diff_ws = yycon2 * (ws[i][j + 1][k] - 2. * ws[i][j][k] + ws[i][j - 1][k]);
            double conv3_term = ty2 * (u[3][i][j + 1][k] * vp1 - u[3][i][j - 1][k] * vm1);
            rhs[3][i][j][k] += u3_term + diff_ws - conv3_term;

            double u4_term = dy5ty1 * (u[4][i][j + 1][k] - 2. * u[4][i][j][k] + u[4][i][j - 1][k]);
            double diff_qs = yycon3 * (qs[i][j + 1][k] - 2. * qs[i][j][k] + qs[i][j - 1][k]);
            double nonlin_v = yycon4 * (vp1 * vp1 - 2. * vijk * vijk + vm1 * vm1);
            double mixed_u4_rho = yycon5 * (u[4][i][j + 1][k] * rho_i[i][j + 1][k] - 2. * u[4][i][j][k] * rho_i[i][j][k] + u[4][i][j - 1][k] * rho_i[i][j - 1][k]);
            double conv4_term = ty2 * ((c1 * u[4][i][j + 1][k] - c2 * square[i][j + 1][k]) * vp1 - (c1 * u[4][i][j - 1][k] - c2 * square[i][j - 1][k]) * vm1);
            rhs[4][i][j][k] += u4_term + diff_qs + nonlin_v + mixed_u4_rho - conv4_term;
        }
    }
}
}
