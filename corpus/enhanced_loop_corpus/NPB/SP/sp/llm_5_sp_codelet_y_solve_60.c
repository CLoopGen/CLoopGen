#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int j1;
extern int j2;
extern int m;
extern double fac1;
extern double fac2;



void loop(){
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    int limit_j = grid_points[1] - 2;
    for (j = 0; j < limit_j; j++) {
        j1 = j + 1;
        j2 = j + 2;
        int limit_i = grid_points[0] - 1;
        int limit_k = grid_points[2] - 1;
        for (i = 1; i < limit_i; i++) {
            for (k = 1; k < limit_k; k++) {
                fac1 = 1.0 / lhs[n + 2][i][j][k];
                double temp3 = lhs[n + 3][i][j][k] * fac1;
                double temp4 = lhs[n + 4][i][j][k] * fac1;
                double rhs_val = rhs[m][i][j][k] * fac1;
                lhs[n + 3][i][j][k] = temp3;
                lhs[n + 4][i][j][k] = temp4;
                rhs[m][i][j][k] = rhs_val;
                if (j1 < grid_points[1]) {
                    lhs[n + 2][i][j1][k] -= lhs[n + 1][i][j1][k] * temp3;
                    lhs[n + 3][i][j1][k] -= lhs[n + 1][i][j1][k] * temp4;
                    rhs[m][i][j1][k] -= lhs[n + 1][i][j1][k] * rhs_val;
                }
                if (j2 < grid_points[1]) {
                    lhs[n + 1][i][j2][k] -= lhs[n + 0][i][j2][k] * temp3;
                    lhs[n + 2][i][j2][k] -= lhs[n + 0][i][j2][k] * temp4;
                    rhs[m][i][j2][k] -= lhs[n + 0][i][j2][k] * rhs_val;
                }
            }
        }
    }
    j = grid_points[1] - 2;
    j1 = grid_points[1] - 1;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            fac1 = 1.0 / lhs[n + 2][i][j][k];
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;
            rhs[m][i][j][k] *= fac1;
            if (j1 < 65) {
                lhs[n + 2][i][j1][k] -= lhs[n + 1][i][j1][k] * lhs[n + 3][i][j][k];
                lhs[n + 3][i][j1][k] -= lhs[n + 1][i][j1][k] * lhs[n + 4][i][j][k];
                rhs[m][i][j1][k] -= lhs[n + 1][i][j1][k] * rhs[m][i][j][k];
                if (lhs[n + 2][i][j1][k] != 0.0) {
                    fac2 = 1.0 / lhs[n + 2][i][j1][k];
                    rhs[m][i][j1][k] *= fac2;
                }
            }
        }
    }
}
}
