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
extern double wijk;
extern double wp1;
extern double wm1;



void loop(){
for (i = 2; i < grid_points[0] - 2; i++) {
    for (j = 2; j < grid_points[1] - 2; j++) {
        for (k = 2; k < grid_points[2] - 2; k++) {
            wijk = ws[i][j][k];
            wp1 = ws[i][j][k + 1];
            wm1 = ws[i][j][k - 1];
            double diff_u0 = u[i][j][k + 1][0] - 2. * u[i][j][k][0] + u[i][j][k - 1][0];
            double diff_u3 = u[i][j][k + 1][3] - u[i][j][k - 1][3];
            rhs[i][j][k][0] += dz1tz1 * diff_u0 - tz2 * diff_u3;

            double diff_u1 = u[i][j][k + 1][1] - 2. * u[i][j][k][1] + u[i][j][k - 1][1];
            double diff_us = us[i][j][k + 1] - 2. * us[i][j][k] + us[i][j][k - 1];
            double conv1 = u[i][j][k + 1][1] * wp1 - u[i][j][k - 1][1] * wm1;
            rhs[i][j][k][1] += dz2tz1 * diff_u1 + zzcon2 * diff_us - tz2 * conv1;

            double diff_u2 = u[i][j][k + 1][2] - 2. * u[i][j][k][2] + u[i][j][k - 1][2];
            double diff_vs = vs[i][j][k + 1] - 2. * vs[i][j][k] + vs[i][j][k - 1];
            double conv2 = u[i][j][k + 1][2] * wp1 - u[i][j][k - 1][2] * wm1;
            rhs[i][j][k][2] += dz3tz1 * diff_u2 + zzcon2 * diff_vs - tz2 * conv2;

            double diff_w = wp1 - 2. * wijk + wm1;
            double diff_u4_sq = (u[i][j][k + 1][4] - square[i][j][k + 1]) - (u[i][j][k - 1][4] + (-square[i][j][k - 1]));
            double conv3 = u[i][j][k + 1][3] * wp1 - u[i][j][k - 1][3] * wm1 + diff_u4_sq * c2;
            rhs[i][j][k][3] += dz4tz1 * (u[i][j][k + 1][3] - 2. * u[i][j][k][3] + u[i][j][k - 1][3]) + 
                               zzcon2 * con43 * diff_w - tz2 * conv3;

            double diff_u4 = u[i][j][k + 1][4] - 2. * u[i][j][k][4] + u[i][j][k - 1][4];
            double diff_qs = qs[i][j][k + 1] - 2. * qs[i][j][k] + qs[i][j][k - 1];
            double diff_sq = wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1;
            double diff_urho = u[i][j][k + 1][4] * rho_i[i][j][k + 1] - 2. * u[i][j][k][4] * rho_i[i][j][k] + u[i][j][k - 1][4] * rho_i[i][j][k - 1];
            double force_term = (c1 * u[i][j][k + 1][4] - c2 * square[i][j][k + 1]) * wp1 - 
                               (c1 * u[i][j][k - 1][4] - c2 * square[i][j][k - 1]) * wm1;
            rhs[i][j][k][4] += dz5tz1 * diff_u4 + zzcon3 * diff_qs + zzcon4 * diff_sq + 
                               zzcon5 * diff_urho - tz2 * force_term;
        }
    }
}
}
