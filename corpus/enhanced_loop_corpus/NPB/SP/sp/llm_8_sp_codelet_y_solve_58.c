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



void loop(){
for (j = 0; j <= grid_points[1] - 3; j++) {
    j1 = j + 1;
    j2 = j + 2;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;
            rhs[0][i][j][k] = fac1 * rhs[0][i][j][k];
            rhs[1][i][j][k] = fac1 * rhs[1][i][j][k];
            rhs[2][i][j][k] = fac1 * rhs[2][i][j][k];
            double temp1 = lhs[n + 3][i][j][k];
            double temp2 = lhs[n + 4][i][j][k];
            double lhsm1 = lhs[n + 1][i][j1][k];
            lhs[n + 2][i][j1][k] -= lhsm1 * temp1;
            lhs[n + 3][i][j1][k] -= lhsm1 * temp2;
            rhs[0][i][j1][k] -= lhsm1 * rhs[0][i][j][k];
            rhs[1][i][j1][k] -= lhsm1 * rhs[1][i][j][k];
            rhs[2][i][j1][k] -= lhsm1 * rhs[2][i][j][k];
            double lhsm0 = lhs[n + 0][i][j2][k];
            lhs[n + 1][i][j2][k] -= lhsm0 * temp1;
            lhs[n + 2][i][j2][k] -= lhsm0 * temp2;
            rhs[0][i][j2][k] -= lhsm0 * rhs[0][i][j][k];
            rhs[1][i][j2][k] -= lhsm0 * rhs[1][i][j][k];
            rhs[2][i][j2][k] -= lhsm0 * rhs[2][i][j][k];
        }
    }
}
}
