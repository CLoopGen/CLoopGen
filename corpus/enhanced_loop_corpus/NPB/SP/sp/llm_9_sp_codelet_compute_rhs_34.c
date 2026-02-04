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
    for (j = 2; j <= grid_points[1] - 3; j++) {
        for (k = 2; k <= grid_points[2] - 3; k++) {
            vijk = vs[i][j][k];
            vp1 = vs[i][j + 1][k];
            vm1 = vs[i][j - 1][k];

            double u0jp1 = u[0][i][j + 1][k], u0jm1 = u[0][i][j - 1][k], u0j = u[0][i][j][k];
            double u1jp1 = u[1][i][j + 1][k], u1jm1 = u[1][i][j - 1][k], u1j = u[1][i][j][k];
            double u2jp1 = u[2][i][j + 1][k], u2jm1 = u[2][i][j - 1][k], u2j = u[2][i][j][k];
            double u3jp1 = u[3][i][j + 1][k], u3jm1 = u[3][i][j - 1][k], u3j = u[3][i][j][k];
            double u4jp1 = u[4][i][j + 1][k], u4jm1 = u[4][i][j - 1][k], u4j = u[4][i][j][k];

            double sjp1 = square[i][j + 1][k], sjm1 = square[i][j - 1][k];
            double rirjp1 = rho_i[i][j + 1][k], rirjm1 = rho_i[i][j - 1][k];
            double usjp1 = us[i][j + 1][k], usjm1 = us[i][j - 1][k], usj = us[i][j][k];
            double wsjp1 = ws[i][j + 1][k], wsjm1 = ws[i][j - 1][k], wsj = ws[i][j][k];
            double qsjp1 = qs[i][j + 1][k], qsjm1 = qs[i][j - 1][k], qsj = qs[i][j][k];

            rhs[0][i][j][k] += dy1ty1 * (u0jp1 - 2.0 * u0j + u0jm1) - ty2 * (u2jp1 - u2jm1);
            rhs[1][i][j][k] += dy2ty1 * (u1jp1 - 2.0 * u1j + u1jm1) + yycon2 * (usjp1 - 2.0 * usj + usjm1)
                             - ty2 * (u1jp1 * vp1 - u1jm1 * vm1);
            rhs[2][i][j][k] += dy3ty1 * (u2jp1 - 2.0 * u2j + u2jm1) + yycon2 * con43 * (vp1 - 2.0 * vijk + vm1)
                             - ty2 * (u2jp1 * vp1 - u2jm1 * vm1 + (u4jp1 - sjp1 - u4jm1 + sjm1) * c2);
            rhs[3][i][j][k] += dy4ty1 * (u3jp1 - 2.0 * u3j + u3jm1) + yycon2 * (wsjp1 - 2.0 * wsj + wsjm1)
                             - ty2 * (u3jp1 * vp1 - u3jm1 * vm1);
            rhs[4][i][j][k] += dy5ty1 * (u4jp1 - 2.0 * u4j + u4jm1) + yycon3 * (qsjp1 - 2.0 * qsj + qsjm1)
                             + yycon4 * (vp1 * vp1 - 2.0 * vijk * vijk + vm1 * vm1)
                             + yycon5 * (u4jp1 * rirjp1 - 2.0 * u4j * rho_i[i][j][k] + u4jm1 * rirjm1)
                             - ty2 * ((c1 * u4jp1 - c2 * sjp1) * vp1 - (c1 * u4jm1 - c2 * sjm1) * vm1);
        }
    }
}
}
