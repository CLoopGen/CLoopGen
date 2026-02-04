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
    int i, j, k, ii, jj, kk;
    double local_tmp1, local_tmp2;
    const int unroll_factor = 2;

    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (k = 1; k < grid_points[2] - 1; k += unroll_factor) {

                // Process two k-values per iteration to increase arithmetic density
                for (ii = 0; ii < unroll_factor && (k + ii) < grid_points[2] - 1; ii++) {
                    int ki = k + ii;
                    local_tmp1 = dt * tz1;
                    local_tmp2 = dt * tz2;

                    // Duplicate and interleave computations for k and k+1
                    for (int m = 0; m < 5; m++) {
                        for (int n = 0; n < 5; n++) {
                            // Lower diagonal block: [0][m][n]
                            lhs[i][j][ki][0][m][n] = -local_tmp2 * fjac[i][j][ki - 1][m][n] 
                                                   - local_tmp1 * njac[i][j][ki - 1][m][n];
                            if (m == n) {
                                lhs[i][j][ki][0][m][n] -= local_tmp1 * (m == 0 ? dz1 : (m == 1 ? dz2 : (m == 2 ? dz3 : (m == 3 ? dz4 : dz5))));
                            }

                            // Main diagonal block: [1][m][n]
                            lhs[i][j][ki][1][m][n] = local_tmp1 * 2.0 * njac[i][j][ki][m][n];
                            if (m == n) {
                                lhs[i][j][ki][1][m][n] += 1.0 + local_tmp1 * 2.0 * (m == 0 ? dz1 : (m == 1 ? dz2 : (m == 2 ? dz3 : (m == 3 ? dz4 : dz5))));
                            }

                            // Upper diagonal block: [2][m][n]
                            lhs[i][j][ki][2][m][n] = local_tmp2 * fjac[i][j][ki + 1][m][n] 
                                                   - local_tmp1 * njac[i][j][ki + 1][m][n];
                            if (m == n) {
                                lhs[i][j][ki][2][m][n] -= local_tmp1 * (m == 0 ? dz1 : (m == 1 ? dz2 : (m == 2 ? dz3 : (m == 3 ? dz4 : dz5))));
                            }
                        }
                    }
                }
            }
        }
    }
}
