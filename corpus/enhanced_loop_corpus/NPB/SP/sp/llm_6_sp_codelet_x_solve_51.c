#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int i2;
extern int m;
extern double fac1;



void loop(){
for (i = 0; i <= grid_points[0] - 3; i++) {
    i1 = i + 1;
    i2 = i + 2;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            // Introduce temporary variables to break direct WAW and WAR dependencies
            double temp_lhs_3 = fac1 * lhs[n + 3][i][j][k];
            double temp_lhs_4 = fac1 * lhs[n + 4][i][j][k];
            double temp_rhs[3];
            for (m = 0; m < 3; m++) {
                temp_rhs[m] = fac1 * rhs[m][i][j][k];
            }
            // Delayed write-back to create different write ordering (WAW dependency altered)
            lhs[n + 3][i][j][k] = temp_lhs_3;
            lhs[n + 4][i][j][k] = temp_lhs_4;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k] = temp_rhs[m];
            }
            // Modify access pattern: introduce artificial loop-carried dependency via reuse of computed values
            double prev_factor = (i > 0) ? lhs[n + 3][i-1][j][k] * 0.1 : 0.0;
            lhs[n + 2][i1][j][k] = lhs[n + 2][i1][j][k] - (lhs[n + 1][i1][j][k] + prev_factor) * lhs[n + 3][i][j][k];
            lhs[n + 3][i1][j][k] = lhs[n + 3][i1][j][k] - lhs[n + 1][i1][j][k] * lhs[n + 4][i][j][k];
            for (m = 0; m < 3; m++) {
                rhs[m][i1][j][k] = rhs[m][i1][j][k] - lhs[n + 1][i1][j][k] * rhs[m][i][j][k];
            }
            lhs[n + 1][i2][j][k] = lhs[n + 1][i2][j][k] - lhs[n + 0][i2][j][k] * lhs[n + 3][i][j][k];
            lhs[n + 2][i2][j][k] = lhs[n + 2][i2][j][k] - lhs[n + 0][i2][j][k] * lhs[n + 4][i][j][k];
            for (m = 0; m < 3; m++) {
                rhs[m][i2][j][k] = rhs[m][i2][j][k] - lhs[n + 0][i2][j][k] * rhs[m][i][j][k];
            }
        }
    }
}
}
