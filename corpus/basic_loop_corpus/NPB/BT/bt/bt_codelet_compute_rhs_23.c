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
extern double vijk;
extern double vp1;
extern double vm1;

void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            vijk = vs[i][j][k];
            vp1 = vs[i][j + 1][k];
            vm1 = vs[i][j - 1][k];
            rhs[i][j][k][0] = rhs[i][j][k][0] + dy1ty1 * (u[i][j + 1][k][0] - 2. * u[i][j][k][0] + u[i][j - 1][k][0]) - ty2 * (u[i][j + 1][k][2] - u[i][j - 1][k][2]);
            rhs[i][j][k][1] = rhs[i][j][k][1] + dy2ty1 * (u[i][j + 1][k][1] - 2. * u[i][j][k][1] + u[i][j - 1][k][1]) + yycon2 * (us[i][j + 1][k] - 2. * us[i][j][k] + us[i][j - 1][k]) - ty2 * (u[i][j + 1][k][1] * vp1 - u[i][j - 1][k][1] * vm1);
            rhs[i][j][k][2] = rhs[i][j][k][2] + dy3ty1 * (u[i][j + 1][k][2] - 2. * u[i][j][k][2] + u[i][j - 1][k][2]) + yycon2 * con43 * (vp1 - 2. * vijk + vm1) - ty2 * (u[i][j + 1][k][2] * vp1 - u[i][j - 1][k][2] * vm1 + (u[i][j + 1][k][4] - square[i][j + 1][k] - u[i][j - 1][k][4] + square[i][j - 1][k]) * c2);
            rhs[i][j][k][3] = rhs[i][j][k][3] + dy4ty1 * (u[i][j + 1][k][3] - 2. * u[i][j][k][3] + u[i][j - 1][k][3]) + yycon2 * (ws[i][j + 1][k] - 2. * ws[i][j][k] + ws[i][j - 1][k]) - ty2 * (u[i][j + 1][k][3] * vp1 - u[i][j - 1][k][3] * vm1);
            rhs[i][j][k][4] = rhs[i][j][k][4] + dy5ty1 * (u[i][j + 1][k][4] - 2. * u[i][j][k][4] + u[i][j - 1][k][4]) + yycon3 * (qs[i][j + 1][k] - 2. * qs[i][j][k] + qs[i][j - 1][k]) + yycon4 * (vp1 * vp1 - 2. * vijk * vijk + vm1 * vm1) + yycon5 * (u[i][j + 1][k][4] * rho_i[i][j + 1][k] - 2. * u[i][j][k][4] * rho_i[i][j][k] + u[i][j - 1][k][4] * rho_i[i][j - 1][k]) - ty2 * ((c1 * u[i][j + 1][k][4] - c2 * square[i][j + 1][k]) * vp1 - (c1 * u[i][j - 1][k][4] - c2 * square[i][j - 1][k]) * vm1);
        }
    }
}

}
