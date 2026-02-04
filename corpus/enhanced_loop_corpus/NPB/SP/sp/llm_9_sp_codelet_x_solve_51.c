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
for (i = 0; i <= grid_points[0] - 2; i += 2) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            i1 = i + 1;
            i2 = i + 2;
            double temp_fac1 = 1. / lhs[n + 2][i][j][k];
            double temp_fac2 = (i1 < grid_points[0] - 2) ? 1. / lhs[n + 2][i1][j][k] : 1.0;
            lhs[n + 3][i][j][k] *= temp_fac1;
            lhs[n + 4][i][j][k] *= temp_fac1;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k] *= temp_fac1;
            }
            if (i1 < grid_points[0] - 2) {
                lhs[n + 3][i1][j][k] *= temp_fac2;
                lhs[n + 4][i1][j][k] *= temp_fac2;
                for (m = 0; m < 3; m++) {
                    rhs[m][i1][j][k] *= temp_fac2;
                }
            }
            if (i1 < grid_points[0] - 2) {
                lhs[n + 2][i1][j][k] -= lhs[n + 1][i1][j][k] * lhs[n + 3][i][j][k];
                lhs[n + 3][i1][j][k] -= lhs[n + 1][i1][j][k] * lhs[n + 4][i][j][k];
                for (m = 0; m < 3; m++) {
                    rhs[m][i1][j][k] -= lhs[n + 1][i1][j][k] * rhs[m][i][j][k];
                }
            }
            if (i2 < grid_points[0] - 2) {
                lhs[n + 1][i2][j][k] -= lhs[n + 0][i2][j][k] * lhs[n + 3][i][j][k];
                lhs[n + 2][i2][j][k] -= lhs[n + 0][i2][j][k] * lhs[n + 4][i][j][k];
                for (m = 0; m < 3; m++) {
                    rhs[m][i2][j][k] -= lhs[n + 0][i2][j][k] * rhs[m][i][j][k];
                }
            }
        }
    }
}
}
