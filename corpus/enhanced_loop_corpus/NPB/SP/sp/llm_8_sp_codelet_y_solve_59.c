#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int j1;
extern int m;
extern double fac1;
extern double fac2;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (k = 1; k <= grid_points[2] - 2; k += 2) {
        fac1 = 1.0 / lhs[n + 2][i][j][k];
        lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
        lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
        rhs[0][i][j][k] = fac1 * rhs[0][i][j][k];
        rhs[1][i][j][k] = fac1 * rhs[1][i][j][k];
        rhs[2][i][j][k] = fac1 * rhs[2][i][j][k];
        double temp1 = lhs[n + 1][i][j1][k] * lhs[n + 3][i][j][k];
        double temp2 = lhs[n + 1][i][j1][k] * lhs[n + 4][i][j][k];
        double temp_rhs0 = lhs[n + 1][i][j1][k] * rhs[0][i][j][k];
        double temp_rhs1 = lhs[n + 1][i][j1][k] * rhs[1][i][j][k];
        double temp_rhs2 = lhs[n + 1][i][j1][k] * rhs[2][i][j][k];
        lhs[n + 2][i][j1][k] -= temp1;
        lhs[n + 3][i][j1][k] -= temp2;
        rhs[0][i][j1][k] -= temp_rhs0;
        rhs[1][i][j1][k] -= temp_rhs1;
        rhs[2][i][j1][k] -= temp_rhs2;
        fac2 = 1.0 / lhs[n + 2][i][j1][k];
        rhs[0][i][j1][k] *= fac2;
        rhs[1][i][j1][k] *= fac2;
        rhs[2][i][j1][k] *= fac2;
    }
}
}
