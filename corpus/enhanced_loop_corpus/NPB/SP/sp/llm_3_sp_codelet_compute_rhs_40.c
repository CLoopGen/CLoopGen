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
int stride = 65;
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k += 2) { // Strided access with step 2
            int k_prev = k - 1;
            int k_curr = k;
            int k_next = k + 1;
            int k_next2 = k + 2;

            // Process two points at a time with strided pattern
            if (k_next2 < grid_points[2] - 1) {
                // First point: k_curr
                wijk = ws[i][j][k_curr];
                wp1 = ws[i][j][k_next];
                wm1 = ws[i][j][k_prev];
                rhs[0][i][j][k_curr] = rhs[0][i][j][k_curr] + dz1tz1 * (u[0][i][j][k_next] - 2. * u[0][i][j][k_curr] + u[0][i][j][k_prev]) - tz2 * (u[3][i][j][k_next] - u[3][i][j][k_prev]);
                rhs[1][i][j][k_curr] = rhs[1][i][j][k_curr] + dz2tz1 * (u[1][i][j][k_next] - 2. * u[1][i][j][k_curr] + u[1][i][j][k_prev]) + zzcon2 * (us[i][j][k_next] - 2. * us[i][j][k_curr] + us[i][j][k_prev]) - tz2 * (u[1][i][j][k_next] * wp1 - u[1][i][j][k_prev] * wm1);
                rhs[2][i][j][k_curr] = rhs[2][i][j][k_curr] + dz3tz1 * (u[2][i][j][k_next] - 2. * u[2][i][j][k_curr] + u[2][i][j][k_prev]) + zzcon2 * (vs[i][j][k_next] - 2. * vs[i][j][k_curr] + vs[i][j][k_prev]) - tz2 * (u[2][i][j][k_next] * wp1 - u[2][i][j][k_prev] * wm1);
                rhs[3][i][j][k_curr] = rhs[3][i][j][k_curr] + dz4tz1 * (u[3][i][j][k_next] - 2. * u[3][i][j][k_curr] + u[3][i][j][k_prev]) + zzcon2 * con43 * (wp1 - 2. * wijk + wm1) - tz2 * (u[3][i][j][k_next] * wp1 - u[3][i][j][k_prev] * wm1 + (u[4][i][j][k_next] - square[i][j][k_next] - u[4][i][j][k_prev] + square[i][j][k_prev]) * c2);
                rhs[4][i][j][k_curr] = rhs[4][i][j][k_curr] + dz5tz1 * (u[4][i][j][k_next] - 2. * u[4][i][j][k_curr] + u[4][i][j][k_prev]) + zzcon3 * (qs[i][j][k_next] - 2. * qs[i][j][k_curr] + qs[i][j][k_prev]) + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1) + zzcon5 * (u[4][i][j][k_next] * rho_i[i][j][k_next] - 2. * u[4][i][j][k_curr] * rho_i[i][j][k_curr] + u[4][i][j][k_prev] * rho_i[i][j][k_prev]) - tz2 * ((c1 * u[4][i][j][k_next] - c2 * square[i][j][k_next]) * wp1 - (c1 * u[4][i][j][k_prev] - c2 * square[i][j][k_prev]) * wm1);

                // Second point: k_next2 (strided by 2)
                wijk = ws[i][j][k_next2];
                wp1 = ws[i][j][k_next2 + 1];
                wm1 = ws[i][j][k_next2 - 1];
                rhs[0][i][j][k_next2] = rhs[0][i][j][k_next2] + dz1tz1 * (u[0][i][j][k_next2 + 1] - 2. * u[0][i][j][k_next2] + u[0][i][j][k_next2 - 1]) - tz2 * (u[3][i][j][k_next2 + 1] - u[3][i][j][k_next2 - 1]);
                rhs[1][i][j][k_next2] = rhs[1][i][j][k_next2] + dz2tz1 * (u[1][i][j][k_next2 + 1] - 2. * u[1][i][j][k_next2] + u[1][i][j][k_next2 - 1]) + zzcon2 * (us[i][j][k_next2 + 1] - 2. * us[i][j][k_next2] + us[i][j][k_next2 - 1]) - tz2 * (u[1][i][j][k_next2 + 1] * wp1 - u[1][i][j][k_next2 - 1] * wm1);
                rhs[2][i][j][k_next2] = rhs[2][i][j][k_next2] + dz3tz1 * (u[2][i][j][k_next2 + 1] - 2. * u[2][i][j][k_next2] + u[2][i][j][k_next2 - 1]) + zzcon2 * (vs[i][j][k_next2 + 1] - 2. * vs[i][j][k_next2] + vs[i][j][k_next2 - 1]) - tz2 * (u[2][i][j][k_next2 + 1] * wp1 - u[2][i][j][k_next2 - 1] * wm1);
                rhs[3][i][j][k_next2] = rhs[3][i][j][k_next2] + dz4tz1 * (u[3][i][j][k_next2 + 1] - 2. * u[3][i][j][k_next2] + u[3][i][j][k_next2 - 1]) + zzcon2 * con43 * (wp1 - 2. * wijk + wm1) - tz2 * (u[3][i][j][k_next2 + 1] * wp1 - u[3][i][j][k_next2 - 1] * wm1 + (u[4][i][j][k_next2 + 1] - square[i][j][k_next2 + 1] - u[4][i][j][k_next2 - 1] + square[i][j][k_next2 - 1]) * c2);
                rhs[4][i][j][k_next2] = rhs[4][i][j][k_next2] + dz5tz1 * (u[4][i][j][k_next2 + 1] - 2. * u[4][i][j][k_next2] + u[4][i][j][k_next2 - 1]) + zzcon3 * (qs[i][j][k_next2 + 1] - 2. * qs[i][j][k_next2] + qs[i][j][k_next2 - 1]) + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1) + zzcon5 * (u[4][i][j][k_next2 + 1] * rho_i[i][j][k_next2 + 1] - 2. * u[4][i][j][k_next2] * rho_i[i][j][k_next2] + u[4][i][j][k_next2 - 1] * rho_i[i][j][k_next2 - 1]) - tz2 * ((c1 * u[4][i][j][k_next2 + 1] - c2 * square[i][j][k_next2 + 1]) * wp1 - (c1 * u[4][i][j][k_next2 - 1] - c2 * square[i][j][k_next2 - 1]) * wm1);
            } else if (k_curr <= grid_points[2] - 2) {
                // Handle edge case when only one point remains
                wijk = ws[i][j][k_curr];
                wp1 = ws[i][j][k_next];
                wm1 = ws[i][j][k_prev];
                rhs[0][i][j][k_curr] = rhs[0][i][j][k_curr] + dz1tz1 * (u[0][i][j][k_next] - 2. * u[0][i][j][k_curr] + u[0][i][j][k_prev]) - tz2 * (u[3][i][j][k_next] - u[3][i][j][k_prev]);
                rhs[1][i][j][k_curr] = rhs[1][i][j][k_curr] + dz2tz1 * (u[1][i][j][k_next] - 2. * u[1][i][j][k_curr] + u[1][i][j][k_prev]) + zzcon2 * (us[i][j][k_next] - 2. * us[i][j][k_curr] + us[i][j][k_prev]) - tz2 * (u[1][i][j][k_next] * wp1 - u[1][i][j][k_prev] * wm1);
                rhs[2][i][j][k_curr] = rhs[2][i][j][k_curr] + dz3tz1 * (u[2][i][j][k_next] - 2. * u[2][i][j][k_curr] + u[2][i][j][k_prev]) + zzcon2 * (vs[i][j][k_next] - 2. * vs[i][j][k_curr] + vs[i][j][k_prev]) - tz2 * (u[2][i][j][k_next] * wp1 - u[2][i][j][k_prev] * wm1);
                rhs[3][i][j][k_curr] = rhs[3][i][j][k_curr] + dz4tz1 * (u[3][i][j][k_next] - 2. * u[3][i][j][k_curr] + u[3][i][j][k_prev]) + zzcon2 * con43 * (wp1 - 2. * wijk + wm1) - tz2 * (u[3][i][j][k_next] * wp1 - u[3][i][j][k_prev] * wm1 + (u[4][i][j][k_next] - square[i][j][k_next] - u[4][i][j][k_prev] + square[i][j][k_prev]) * c2);
                rhs[4][i][j][k_curr] = rhs[4][i][j][k_curr] + dz5tz1 * (u[4][i][j][k_next] - 2. * u[4][i][j][k_curr] + u[4][i][j][k_prev]) + zzcon3 * (qs[i][j][k_next] - 2. * qs[i][j][k_curr] + qs[i][j][k_prev]) + zzcon4 * (wp1 * wp1 - 2. * wijk * wijk + wm1 * wm1) + zzcon5 * (u[4][i][j][k_next] * rho_i[i][j][k_next] - 2. * u[4][i][j][k_curr] * rho_i[i][j][k_curr] + u[4][i][j][k_prev] * rho_i[i][j][k_prev]) - tz2 * ((c1 * u[4][i][j][k_next] - c2 * square[i][j][k_next]) * wp1 - (c1 * u[4][i][j][k_prev] - c2 * square[i][j][k_prev]) * wm1);
            }
        }
    }
}
}
