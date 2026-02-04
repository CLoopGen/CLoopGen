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
for (i = 0; i <= grid_points[0] - 5; i++) {
    i1 = i + 1;
    i2 = i + 2;
    for (j = 2; j <= grid_points[1] - 3; j++) {
        for (k = 2; k <= grid_points[2] - 3; k++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
            lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
            rhs[0][i][j][k] = fac1 * rhs[0][i][j][k];
            rhs[1][i][j][k] = fac1 * rhs[1][i][j][k];
            rhs[2][i][j][k] = fac1 * rhs[2][i][j][k];
            lhs[n + 2][i1][j][k] = lhs[n + 2][i1][j][k] - lhs[n + 1][i1][j][k] * lhs[n + 3][i][j][k];
            lhs[n + 3][i1][j][k] = lhs[n + 3][i1][j][k] - lhs[n + 1][i1][j][k] * lhs[n + 4][i][j][k];
            rhs[0][i1][j][k] = rhs[0][i1][j][k] - lhs[n + 1][i1][j][k] * rhs[0][i][j][k];
            rhs[1][i1][j][k] = rhs[1][i1][j][k] - lhs[n + 1][i1][j][k] * rhs[1][i][j][k];
            rhs[2][i1][j][k] = rhs[2][i1][j][k] - lhs[n + 1][i1][j][k] * rhs[2][i][j][k];
            lhs[n + 1][i2][j][k] = lhs[n + 1][i2][j][k] - lhs[n + 0][i2][j][k] * lhs[n + 3][i][j][k];
            lhs[n + 2][i2][j][k] = lhs[n + 2][i2][j][k] - lhs[n + 0][i2][j][k] * lhs[n + 4][i][j][k];
            rhs[0][i2][j][k] = rhs[0][i2][j][k] - lhs[n + 0][i2][j][k] * rhs[0][i][j][k];
            rhs[1][i2][j][k] = rhs[1][i2][j][k] - lhs[n + 0][i2][j][k] * rhs[1][i][j][k];
            rhs[2][i2][j][k] = rhs[2][i2][j][k] - lhs[n + 0][i2][j][k] * rhs[2][i][j][k];
        }
    }
}
}
