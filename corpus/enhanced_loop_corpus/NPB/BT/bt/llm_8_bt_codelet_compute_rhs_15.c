#include <stdio.h>

extern  int grid_points[3];
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern double rho_inv;



void loop(){
for (i = 0; i < grid_points[0]; i++) {
    for (j = 0; j < grid_points[1]; j++) {
        for (k = 0; k < grid_points[2]; k += 2) { // Increased trip count granularity to reduce iterations by half, but process two elements per iteration
            rho_inv = 1. / u[i][j][k][0];
            rho_i[i][j][k] = rho_inv;
            us[i][j][k] = u[i][j][k][1] * rho_inv;
            vs[i][j][k] = u[i][j][k][2] * rho_inv;
            ws[i][j][k] = u[i][j][k][3] * rho_inv;
            square[i][j][k] = 0.5 * (u[i][j][k][1] * u[i][j][k][1] + u[i][j][k][2] * u[i][j][k][2] + u[i][j][k][3] * u[i][j][k][3]) * rho_inv;
            qs[i][j][k] = square[i][j][k] * rho_inv;

            // Process second element in vectorized fashion if within bounds
            if (k + 1 < grid_points[2]) {
                double rho_inv2 = 1. / u[i][j][k+1][0];
                rho_i[i][j][k+1] = rho_inv2;
                us[i][j][k+1] = u[i][j][k+1][1] * rho_inv2;
                vs[i][j][k+1] = u[i][j][k+1][2] * rho_inv2;
                ws[i][j][k+1] = u[i][j][k+1][3] * rho_inv2;
                square[i][j][k+1] = 0.5 * (u[i][j][k+1][1]*u[i][j][k+1][1] + u[i][j][k+1][2]*u[i][j][k+1][2] + u[i][j][k+1][3]*u[i][j][k+1][3]) * rho_inv2;
                qs[i][j][k+1] = square[i][j][k+1] * rho_inv2;
            }
        }
    }
}
}
