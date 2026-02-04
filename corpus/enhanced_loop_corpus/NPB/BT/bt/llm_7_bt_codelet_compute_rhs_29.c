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
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 2; k < grid_points[2] - 2; k++) {  // Modified bounds to enable k+2 and k-2 accesses
            // Modify data dependency pattern by using k+2 and k-2 instead of k+1 and k-1
            // This reduces loop-carried dependencies across consecutive iterations
            wijk = ws[i][j][k];
            wp1 = ws[i][j][k + 2];  // Forward by 2
            wm1 = ws[i][j][k - 2];  // Backward by 2

            rhs[i][j][k][0] += dz1tz1 * (u[i][j][k + 2][0] - 2. * u[i][j][k][0] + u[i][j][k - 2][0]) - tz2 * (u[i][j][k + 2][3] - u[i][j][k - 2][3]);
            rhs[i][j][k][1] += dz2tz1 * (u[i][j][k + 2][1] - 2. * u[i][j][k][1] + u[i][j][k - 2][1]) + zzcon2 * (us[i][j][k + 2] - 2. * us[i][j][k] + us[i][j][k - 2]) - tz2 * (u[i][j][k + 2][1] * wp1 - u[i][j][k - 2][1] * wm1);
            rhs[i][j][k][2] += dz3tz1 * (u[i][j][k + 2][2] - 2. * u[i][j][k][2] + u[i][j][k - 2][2]) + zzcon2 * (vs[i][j][k + 2] - 2. * vs[i][j][k] + vs[i][j][k - 2]) - tz2 * (u[i][j][k + 2][2] * wp1 - u[i][j][k - 2][2] * wm1);
            rhs[i][j][k][3] += dz4tz1 * (u[i][j][k + 2][3] - 2. * u[i][j][k][3] + u[i][j][k - 2][3]) + zzcon2 * con43 * (wp1 - 2. * wijk + wm1) - tz2 * (u[i][j][k + 2][3] * wp1 - u[i][j][k - 2][3] * wm1 + (u[i][j][k + 2][4] - square[i][j][k + 2] - u[i][j][k - 2][4] + square[i][j][k - 2]) * c2);
            rhs[i][j][k][4] += dz5tz1 * (u[i][j][k + 2][4] - 2. * u[i][j][k][4] + u[i][j][k - 2][4]) + zzcon3 * (qs[i][j][k + 2] - 2. * qs[i][j][k] + qs[i][j][k - 2]) + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1) + zzcon5 * (u[i][j][k + 2][4] * rho_i[i][j][k + 2] - 2. * u[i][j][k][4] * rho_i[i][j][k] + u[i][j][k - 2][4] * rho_i[i][j][k - 2]) - tz2 * ((c1 * u[i][j][k + 2][4] - c2 * square[i][j][k + 2]) * wp1 - (c1 * u[i][j][k - 2][4] - c2 * square[i][j][k - 2]) * wm1);
        }
    }
}
}
