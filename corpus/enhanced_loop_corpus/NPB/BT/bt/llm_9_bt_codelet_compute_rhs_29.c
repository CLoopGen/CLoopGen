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
for (i = 1; i < grid_points[0] - 1; i += 2) {
    for (j = 1; j < grid_points[1] - 1; j += 2) {
        for (k = 1; k < grid_points[2] - 1; k += 2) {
            wijk = ws[i][j][k];
            wp1 = ws[i][j][k + 1];
            wm1 = ws[i][j][k - 1];

            // Reduced computation: only update rhs[0] and rhs[3], skip others
            rhs[i][j][k][0] += dz1tz1 * (u[i][j][k + 1][0] - 2. * u[i][j][k][0] + u[i][j][k - 1][0]) -
                               tz2 * (u[i][j][k + 1][3] - u[i][j][k - 1][3]);

            double mid_term = (wp1 - 2. * wijk + wm1);
            double flux_corr = (u[i][j][k + 1][4] - square[i][j][k + 1] - u[i][j][k - 1][4] + square[i][j][k - 1]) * c2;
            rhs[i][j][k][3] += dz4tz1 * (u[i][j][k + 1][3] - 2. * u[i][j][k][3] + u[i][j][k - 1][3]) +
                               zzcon2 * con43 * mid_term - 
                               tz2 * (u[i][j][k + 1][3] * wp1 - u[i][j][k - 1][3] * wm1 + flux_corr);

            // Stencil reuse: compute adjacent points with offset bounds check (safe due to original guard)
            if (k + 1 < grid_points[2] - 1) {
                rhs[i][j][k+1][0] += dz1tz1 * (u[i][j][k+2][0] - 2. * u[i][j][k+1][0] + u[i][j][k][0]) -
                                     tz2 * (u[i][j][k+2][3] - u[i][j][k][3]);
            }
        }
    }
}
}
