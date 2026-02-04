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
    for (j = 1; j <= grid_points[1] - 2; j += 2) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            vijk = vs[i][j][k];
            vp1 = vs[i][j + 1][k];
            vm1 = vs[i][j - 1][k];
            rhs[0][i][j][k] = rhs[0][i][j][k] + dy1ty1 * (u[0][i][j + 1][k] - 2. * u[0][i][j][k] + u[0][i][j - 1][k]) - ty2 * (u[2][i][j + 1][k] - u[2][i][j - 1][k]);
            rhs[1][i][j][k] = rhs[1][i][j][k] + dy2ty1 * (u[1][i][j + 1][k] - 2. * u[1][i][j][k] + u[1][i][j - 1][k]) + yycon2 * (us[i][j + 1][k] - 2. * us[i][j][k] + us[i][j - 1][k]) - ty2 * (u[1][i][j + 1][k] * vp1 - u[1][i][j - 1][k] * vm1);
            rhs[2][i][j][k] = rhs[2][i][j][k] + dy3ty1 * (u[2][i][j + 1][k] - 2. * u[2][i][j][k] + u[2][i][j - 1][k]) + yycon2 * con43 * (vp1 - 2. * vijk + vm1) - ty2 * (u[2][i][j + 1][k] * vp1 - u[2][i][j - 1][k] * vm1 + (u[4][i][j + 1][k] - square[i][j + 1][k] - u[4][i][j - 1][k] + square[i][j - 1][k]) * c2);
            rhs[3][i][j][k] = rhs[3][i][j][k] + dy4ty1 * (u[3][i][j + 1][k] - 2. * u[3][i][j][k] + u[3][i][j - 1][k]) + yycon2 * (ws[i][j + 1][k] - 2. * ws[i][j][k] + ws[i][j - 1][k]) - ty2 * (u[3][i][j + 1][k] * vp1 - u[3][i][j - 1][k] * vm1);
            rhs[4][i][j][k] = rhs[4][i][j][k] + dy5ty1 * (u[4][i][j + 1][k] - 2. * u[4][i][j][k] + u[4][i][j - 1][k]) + yycon3 * (qs[i][j + 1][k] - 2. * qs[i][j][k] + qs[i][j - 1][k]) + yycon4 * (vp1 * vp1 - 2. * vijk * vijk + vm1 * vm1) + yycon5 * (u[4][i][j + 1][k] * rho_i[i][j + 1][k] - 2. * u[4][i][j][k] * rho_i[i][j][k] + u[4][i][j - 1][k] * rho_i[i][j - 1][k]) - ty2 * ((c1 * u[4][i][j + 1][k] - c2 * square[i][j + 1][k]) * vp1 - (c1 * u[4][i][j - 1][k] - c2 * square[i][j - 1][k]) * vm1);

            if (j + 1 <= grid_points[1] - 2) {
                int j2 = j + 1;
                double vijk2 = vs[i][j2][k];
                double vp1_2 = vs[i][j2 + 1][k];
                double vm1_2 = vs[i][j2 - 1][k];
                rhs[0][i][j2][k] = rhs[0][i][j2][k] + dy1ty1 * (u[0][i][j2 + 1][k] - 2. * u[0][i][j2][k] + u[0][i][j2 - 1][k]) - ty2 * (u[2][i][j2 + 1][k] - u[2][i][j2 - 1][k]);
                rhs[1][i][j2][k] = rhs[1][i][j2][k] + dy2ty1 * (u[1][i][j2 + 1][k] - 2. * u[1][i][j2][k] + u[1][i][j2 - 1][k]) + yycon2 * (us[i][j2 + 1][k] - 2. * us[i][j2][k] + us[i][j2 - 1][k]) - ty2 * (u[1][i][j2 + 1][k] * vp1_2 - u[1][i][j2 - 1][k] * vm1_2);
                rhs[2][i][j2][k] = rhs[2][i][j2][k] + dy3ty1 * (u[2][i][j2 + 1][k] - 2. * u[2][i][j2][k] + u[2][i][j2 - 1][k]) + yycon2 * con43 * (vp1_2 - 2. * vijk2 + vm1_2) - ty2 * (u[2][i][j2 + 1][k] * vp1_2 - u[2][i][j2 - 1][k] * vm1_2 + (u[4][i][j2 + 1][k] - square[i][j2 + 1][k] - u[4][i][j2 - 1][k] + square[i][j2 - 1][k]) * c2);
                rhs[3][i][j2][k] = rhs[3][i][j2][k] + dy4ty1 * (u[3][i][j2 + 1][k] - 2. * u[3][i][j2][k] + u[3][i][j2 - 1][k]) + yycon2 * (ws[i][j2 + 1][k] - 2. * ws[i][j2][k] + ws[i][j2 - 1][k]) - ty2 * (u[3][i][j2 + 1][k] * vp1_2 - u[3][i][j2 - 1][k] * vm1_2);
                rhs[4][i][j2][k] = rhs[4][i][j2][k] + dy5ty1 * (u[4][i][j2 + 1][k] - 2. * u[4][i][j2][k] + u[4][i][j2 - 1][k]) + yycon3 * (qs[i][j2 + 1][k] - 2. * qs[i][j2][k] + qs[i][j2 - 1][k]) + yycon4 * (vp1_2 * vp1_2 - 2. * vijk2 * vijk2 + vm1_2 * vm1_2) + yycon5 * (u[4][i][j2 + 1][k] * rho_i[i][j2 + 1][k] - 2. * u[4][i][j2][k] * rho_i[i][j2][k] + u[4][i][j2 - 1][k] * rho_i[i][j2 - 1][k]) - ty2 * ((c1 * u[4][i][j2 + 1][k] - c2 * square[i][j2 + 1][k]) * vp1_2 - (c1 * u[4][i][j2 - 1][k] - c2 * square[i][j2 - 1][k]) * vm1_2);
            }
        }
    }
}
}
