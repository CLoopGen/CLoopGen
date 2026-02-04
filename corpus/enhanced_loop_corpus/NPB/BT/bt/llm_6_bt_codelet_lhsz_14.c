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
    int i, j, k;
    double t1, t2;
    for (i = 2; i < grid_points[0] - 2; i += 2) {
        for (j = 2; j < grid_points[1] - 2; j += 2) {
            for (k = 2; k < grid_points[2] - 2; k += 2) {
                t1 = dt * tz1;
                t2 = dt * tz2;

                // Unrolled and reduced computation: only compute center of the 5x5 stencil in [3][a][b]
                lhs[i][j][k][3][2][2] = 1.0 + t1 * 4.0 * njac[i][j][k][2][2] + t1 * 4.0 * dz3;
                lhs[i][j][k][3][1][1] = 1.0 + t1 * 4.0 * njac[i][j][k][1][1] + t1 * 4.0 * dz2;
                lhs[i][j][k][3][3][3] = 1.0 + t1 * 4.0 * njac[i][j][k][3][3] + t1 * 4.0 * dz4;

                // Simplified off-center terms with combined coefficients
                lhs[i][j][k][3][2][1] = t1 * 4.0 * njac[i][j][k][2][1];
                lhs[i][j][k][3][2][3] = t1 * 4.0 * njac[i][j][k][2][3];
                lhs[i][j][k][3][1][2] = t1 * 4.0 * njac[i][j][k][1][2];
                lhs[i][j][k][3][3][2] = t1 * 4.0 * njac[i][j][k][3][2];

                // Fill symmetric positions using fewer operations
                lhs[i][j][k][3][0][0] = lhs[i][j][k][3][4][4] = 1.0 + t1 * 4.0 * dz1;
            }
        }
    }
}
