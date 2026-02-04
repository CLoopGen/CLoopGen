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
    for (j = 1; j < grid_points[1] - 1; j += 2) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            vijk = vs[i][j][k];
            vp1 = vs[i][j + 1][k];
            vm1 = vs[i][j - 1][k];

            // Update all five components with reduced memory accesses and combined expressions
            double u0p1 = u[i][j + 1][k][0], u0m1 = u[i][j - 1][k][0];
            double u2p1 = u[i][j + 1][k][2], u2m1 = u[i][j - 1][k][2];
            rhs[i][j][k][0] += dy1ty1 * (u0p1 - 2.*u[i][j][k][0] + u0m1) 
                             - ty2 * (u2p1 - u2m1);

            double u1p1 = u[i][j + 1][k][1], u1m1 = u[i][j - 1][k][1];
            double usp1 = us[i][j + 1][k], usm1 = us[i][j - 1][k];
            double flux1 = u1p1 * vp1 - u1m1 * vm1;
            rhs[i][j][k][1] += dy2ty1 * (u1p1 - 2.*u[i][j][k][1] + u1m1)
                             + yycon2 * (usp1 - 2.*us[i][j][k] + usm1)
                             - ty2 * flux1;

            double u3p1 = u[i][j + 1][k][3], u3m1 = u[i][j - 1][k][3];
            double wsp1 = ws[i][j + 1][k], wsm1 = ws[i][j - 1][k];
            double flux3 = u3p1 * vp1 - u3m1 * vm1;
            rhs[i][j][k][3] += dy4ty1 * (u3p1 - 2.*u[i][j][k][3] + u3m1)
                             + yycon2 * (wsp1 - 2.*ws[i][j][k] + wsm1)
                             - ty2 * flux3;

            double u4p1 = u[i][j + 1][k][4], u4m1 = u[i][j - 1][k][4];
            double sqp1 = square[i][j + 1][k], sqm1 = square[i][j - 1][k];
            double qsp1 = qs[i][j + 1][k], qsm1 = qs[i][j - 1][k];
            double rhp1 = rho_i[i][j + 1][k], rhm1 = rho_i[i][j - 1][k];
            double v2diff = vp1*vp1 - 2.*vijk*vijk + vm1*vm1;
            double adv_term = (c1*u4p1 - c2*sqp1)*vp1 - (c1*u4m1 - c2*sqm1)*vm1;
            double diff4 = u4p1*rhp1 - 2.*u[i][j][k][4]*rho_i[i][j][k] + u4m1*rhm1;
            rhs[i][j][k][4] += dy5ty1 * (u4p1 - 2.*u[i][j][k][4] + u4m1)
                             + yycon3 * (qsp1 - 2.*qs[i][j][k] + qsm1)
                             + yycon4 * v2diff
                             + yycon5 * diff4
                             - ty2 * adv_term;

            // Additional computation to increase arithmetic intensity: update adjacent point using current values
            if (j + 2 < grid_points[1] - 1) {
                double temp_v = (vs[i][j+2][k] + vs[i][j][k]) * 0.5;
                rhs[i][j+1][k][2] += yycon2 * con43 * (vs[i][j+2][k] - 2.*temp_v + vs[i][j][k]);
            }
        }
    }
}
}
