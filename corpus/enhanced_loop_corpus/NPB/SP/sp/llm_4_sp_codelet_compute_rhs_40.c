#include <stdio.h>

extern  int grid_points[3];
extern  double tz2;
extern  double zzcon2;
extern  double zzcon3;
extern  double zzcon4;
extern  double zzcon5;
extern  double dz1tz1;
extern  double dz2tz1;
extern  double dz3tz1;
extern  double dz4tz1;
extern  double dz5tz1;
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
extern double wijk;
extern double wp1;
extern double wm1;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            wijk = ws[i][j][k];
            wp1 = ws[i][j][k + 1];
            wm1 = ws[i][j][k - 1];
            double up1_0 = u[0][i][j][k + 1];
            double uk_0 = u[0][i][j][k];
            double um1_0 = u[0][i][j][k - 1];
            rhs[0][i][j][k] += dz1tz1 * (up1_0 - 2. * uk_0 + um1_0) - tz2 * (u[3][i][j][k + 1] - u[3][i][j][k - 1]);

            double up1_1 = u[1][i][j][k + 1];
            double uk_1 = u[1][i][j][k];
            double um1_1 = u[1][i][j][k - 1];
            double usp1 = us[i][j][k + 1];
            double usk = us[i][j][k];
            double usm1 = us[i][j][k - 1];
            rhs[1][i][j][k] += dz2tz1 * (up1_1 - 2. * uk_1 + um1_1) + zzcon2 * (usp1 - 2. * usk + usm1) - tz2 * (up1_1 * wp1 - um1_1 * wm1);

            double up1_2 = u[2][i][j][k + 1];
            double uk_2 = u[2][i][j][k];
            double um1_2 = u[2][i][j][k - 1];
            double vsp1 = vs[i][j][k + 1];
            double vsk = vs[i][j][k];
            double vsm1 = vs[i][j][k - 1];
            rhs[2][i][j][k] += dz3tz1 * (up1_2 - 2. * uk_2 + um1_2) + zzcon2 * (vsp1 - 2. * vsk + vsm1) - tz2 * (up1_2 * wp1 - um1_2 * wm1);

            double up1_3 = u[3][i][j][k + 1];
            double uk_3 = u[3][i][j][k];
            double um1_3 = u[3][i][j][k - 1];
            double up1_4 = u[4][i][j][k + 1];
            double um1_4 = u[4][i][j][k - 1];
            double sqp1 = square[i][j][k + 1];
            double sqm1 = square[i][j][k - 1];
            rhs[3][i][j][k] += dz4tz1 * (up1_3 - 2. * uk_3 + um1_3) + zzcon2 * con43 * (wp1 - 2. * wijk + wm1) - tz2 * (up1_3 * wp1 - um1_3 * wm1 + (up1_4 - sqp1 - um1_4 + sqm1) * c2);

            double up1_4_e = u[4][i][j][k + 1];
            double uk_4_e = u[4][i][j][k];
            double um1_4_e = u[4][i][j][k - 1];
            double qsp1 = qs[i][j][k + 1];
            double qsk = qs[i][j][k];
            double qsm1 = qs[i][j][k - 1];
            double rhp1 = rho_i[i][j][k + 1];
            double rhk = rho_i[i][j][k];
            double rhm1 = rho_i[i][j][k - 1];
            rhs[4][i][j][k] += dz5tz1 * (up1_4_e - 2. * uk_4_e + um1_4_e) + zzcon3 * (qsp1 - 2. * qsk + qsm1) + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1) + zzcon5 * (up1_4_e * rhp1 - 2. * uk_4_e * rhk + um1_4_e * rhm1) - tz2 * ((c1 * up1_4_e - c2 * sqp1) * wp1 - (c1 * um1_4_e - c2 * sqm1) * wm1);
        }
    }
}
}
