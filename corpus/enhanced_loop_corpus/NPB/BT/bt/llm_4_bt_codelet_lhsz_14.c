#include <stdio.h>

extern  int grid_points[3];
extern  double tz1;
extern  double tz2;
extern  double dz1;
extern  double dz2;
extern  double dz3;
extern  double dz4;
extern  double dz5;
extern  double dt;
extern  double lhs[65][65][65][3][5][5];
extern  double fjac[65][65][64][5][5];
extern  double njac[65][65][64][5][5];
extern  double tmp1;
extern  double tmp2;
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        double temp_dz[5] = {dz1, dz2, dz3, dz4, dz5};
        for (k = 1; k < grid_points[2] - 1; k++) {
            tmp1 = dt * tz1;
            tmp2 = dt * tz2;

            // Introduce local accumulation to create temporary dependencies and reduce redundant loads
            double acc[3][5][5];
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 5; n++) {
                    for (int p = 0; p < 5; p++) {
                        acc[m][n][p] = 0.0;
                    }
                }
            }

            // Use k-1 data with negative contributions (same as original but accumulated)
            for (int n = 0; n < 5; n++) {
                acc[0][0][n] += -tmp2 * fjac[i][j][k-1][0][n] - tmp1 * njac[i][j][k-1][0][n];
                acc[0][1][n] += -tmp2 * fjac[i][j][k-1][1][n] - tmp1 * njac[i][j][k-1][1][n];
                acc[0][2][n] += -tmp2 * fjac[i][j][k-1][2][n] - tmp1 * njac[i][j][k-1][2][n];
                acc[0][3][n] += -tmp2 * fjac[i][j][k-1][3][n] - tmp1 * njac[i][j][k-1][3][n];
                acc[0][4][n] += -tmp2 * fjac[i][j][k-1][4][n] - tmp1 * njac[i][j][k-1][4][n];
            }

            // Diagonal adjustments using temp_dz array to centralize constants
            acc[0][0][0] -= tmp1 * temp_dz[0];
            acc[0][1][1] -= tmp1 * temp_dz[1];
            acc[0][2][2] -= tmp1 * temp_dz[2];
            acc[0][3][3] -= tmp1 * temp_dz[3];
            acc[0][4][4] -= tmp1 * temp_dz[4];

            // Center plane: introduce positive identity and diffusion terms
            for (int n = 0; n < 5; n++) {
                for (int p = 0; p < 5; p++) {
                    acc[1][n][p] = tmp1 * 2.0 * njac[i][j][k][n][p];
                }
            }
            acc[1][0][0] += 1.0 + tmp1 * 2.0 * temp_dz[0];
            acc[1][1][1] += 1.0 + tmp1 * 2.0 * temp_dz[1];
            acc[1][2][2] += 1.0 + tmp1 * 2.0 * temp_dz[2];
            acc[1][3][3] += 1.0 + tmp1 * 2.0 * temp_dz[3];
            acc[1][4][4] += 1.0 + tmp1 * 2.0 * temp_dz[4];

            // Forward k+1 plane
            for (int n = 0; n < 5; n++) {
                acc[2][0][n] += tmp2 * fjac[i][j][k+1][0][n] - tmp1 * njac[i][j][k+1][0][n];
                acc[2][1][n] += tmp2 * fjac[i][j][k+1][1][n] - tmp1 * njac[i][j][k+1][1][n];
                acc[2][2][n] += tmp2 * fjac[i][j][k+1][2][n] - tmp1 * njac[i][j][k+1][2][n];
                acc[2][3][n] += tmp2 * fjac[i][j][k+1][3][n] - tmp1 * njac[i][j][k+1][3][n];
                acc[2][4][n] += tmp2 * fjac[i][j][k+1][4][n] - tmp1 * njac[i][j][k+1][4][n];
            }

            acc[2][0][0] -= tmp1 * temp_dz[0];
            acc[2][1][1] -= tmp1 * temp_dz[1];
            acc[2][2][2] -= tmp1 * temp_dz[2];
            acc[2][3][3] -= tmp1 * temp_dz[3];
            acc[2][4][4] -= tmp1 * temp_dz[4];

            // Final store with structured write
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 5; n++) {
                    for (int p = 0; p < 5; p++) {
                        lhs[i][j][k][m][n][p] = acc[m][n][p];
                    }
                }
            }
        }
    }
}
}
