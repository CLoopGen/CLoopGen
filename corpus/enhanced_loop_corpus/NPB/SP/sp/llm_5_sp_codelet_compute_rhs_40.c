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
        for (k = 1; k <= grid_points[2] - 2; k += 2) { // Unrolled by factor of 2 to modify loop-carried dependencies
            // First iteration (k)
            {
                wijk = ws[i][j][k];
                wp1 = ws[i][j][k + 1];
                wm1 = ws[i][j][k - 1];
                double temp_rhs0 = dz1tz1 * (u[0][i][j][k + 1] - 2. * u[0][i][j][k] + u[0][i][j][k - 1]) - tz2 * (u[3][i][j][k + 1] - u[3][i][j][k - 1]);
                double temp_rhs1 = dz2tz1 * (u[1][i][j][k + 1] - 2. * u[1][i][j][k] + u[1][i][j][k - 1]) + zzcon2 * (us[i][j][k + 1] - 2. * us[i][j][k] + us[i][j][k - 1]) - tz2 * (u[1][i][j][k + 1] * wp1 - u[1][i][j][k - 1] * wm1);
                double temp_rhs2 = dz3tz1 * (u[2][i][j][k + 1] - 2. * u[2][i][j][k] + u[2][i][j][k - 1]) + zzcon2 * (vs[i][j][k + 1] - 2. * vs[i][j][k] + vs[i][j][k - 1]) - tz2 * (u[2][i][j][k + 1] * wp1 - u[2][i][j][k - 1] * wm1);
                double temp_rhs3 = dz4tz1 * (u[3][i][j][k + 1] - 2. * u[3][i][j][k] + u[3][i][j][k - 1]) + zzcon2 * con43 * (wp1 - 2. * wijk + wm1) - tz2 * (u[3][i][j][k + 1] * wp1 - u[3][i][j][k - 1] * wm1 + (u[4][i][j][k + 1] - square[i][j][k + 1] - u[4][i][j][k - 1] + square[i][j][k - 1]) * c2);
                double temp_rhs4 = dz5tz1 * (u[4][i][j][k + 1] - 2. * u[4][i][j][k] + u[4][i][j][k - 1]) + zzcon3 * (qs[i][j][k + 1] - 2. * qs[i][j][k] + qs[i][j][k - 1]) + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1) + zzcon5 * (u[4][i][j][k + 1] * rho_i[i][j][k + 1] - 2. * u[4][i][j][k] * rho_i[i][j][k] + u[4][i][j][k - 1] * rho_i[i][j][k - 1]) - tz2 * ((c1 * u[4][i][j][k + 1] - c2 * square[i][j][k + 1]) * wp1 - (c1 * u[4][i][j][k - 1] - c2 * square[i][j][k - 1]) * wm1);
                rhs[0][i][j][k] += temp_rhs0;
                rhs[1][i][j][k] += temp_rhs1;
                rhs[2][i][j][k] += temp_rhs2;
                rhs[3][i][j][k] += temp_rhs3;
                rhs[4][i][j][k] += temp_rhs4;
            }

            // Second iteration (k+1), if within bounds
            if (k + 1 <= grid_points[2] - 2) {
                int kp1 = k + 1;
                wijk = ws[i][j][kp1];
                wp1 = ws[i][j][kp1 + 1];
                wm1 = ws[i][j][kp1 - 1];
                double temp_rhs0 = dz1tz1 * (u[0][i][j][kp1 + 1] - 2. * u[0][i][j][kp1] + u[0][i][j][kp1 - 1]) - tz2 * (u[3][i][j][kp1 + 1] - u[3][i][j][kp1 - 1]);
                double temp_rhs1 = dz2tz1 * (u[1][i][j][kp1 + 1] - 2. * u[1][i][j][kp1] + u[1][i][j][kp1 - 1]) + zzcon2 * (us[i][j][kp1 + 1] - 2. * us[i][j][kp1] + us[i][j][kp1 - 1]) - tz2 * (u[1][i][j][kp1 + 1] * wp1 - u[1][i][j][kp1 - 1] * wm1);
                double temp_rhs2 = dz3tz1 * (u[2][i][j][kp1 + 1] - 2. * u[2][i][j][kp1] + u[2][i][j][kp1 - 1]) + zzcon2 * (vs[i][j][kp1 + 1] - 2. * vs[i][j][kp1] + vs[i][j][kp1 - 1]) - tz2 * (u[2][i][j][kp1 + 1] * wp1 - u[2][i][j][kp1 - 1] * wm1);
                double temp_rhs3 = dz4tz1 * (u[3][i][j][kp1 + 1] - 2. * u[3][i][j][kp1] + u[3][i][j][kp1 - 1]) + zzcon2 * con43 * (wp1 - 2. * wijk + wm1) - tz2 * (u[3][i][j][kp1 + 1] * wp1 - u[3][i][j][kp1 - 1] * wm1 + (u[4][i][j][kp1 + 1] - square[i][j][kp1 + 1] - u[4][i][j][kp1 - 1] + square[i][j][kp1 - 1]) * c2);
                double temp_rhs4 = dz5tz1 * (u[4][i][j][kp1 + 1] - 2. * u[4][i][j][kp1] + u[4][i][j][kp1 - 1]) + zzcon3 * (qs[i][j][kp1 + 1] - 2. * qs[i][j][kp1] + qs[i][j][kp1 - 1]) + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1) + zzcon5 * (u[4][i][j][kp1 + 1] * rho_i[i][j][kp1 + 1] - 2. * u[4][i][j][kp1] * rho_i[i][j][kp1] + u[4][i][j][kp1 - 1] * rho_i[i][j][kp1 - 1]) - tz2 * ((c1 * u[4][i][j][kp1 + 1] - c2 * square[i][j][kp1 + 1]) * wp1 - (c1 * u[4][i][j][kp1 - 1] - c2 * square[i][j][kp1 - 1]) * wm1);
                rhs[0][i][j][kp1] += temp_rhs0;
                rhs[1][i][j][kp1] += temp_rhs1;
                rhs[2][i][j][kp1] += temp_rhs2;
                rhs[3][i][j][kp1] += temp_rhs3;
                rhs[4][i][j][kp1] += temp_rhs4;
            }
        }
    }
}
}
