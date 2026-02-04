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
    for (k = 1; k <= grid_points[2] - 2; k++) {
        int idx4 = ((n + 2) * 65 + i) * 65 * 65 + j * 65 + k;
        int idx3 = (n + 3) * 65 * 65 * 65 + i * 65 * 65 + j * 65 + k;
        int idx5 = (n + 4) * 65 * 65 * 65 + i * 65 * 65 + j * 65 + k;
        int idy = (n + 1) * 65 * 65 * 65 + i * 65 * 65 + j1 * 65 + k;
        fac1 = 1. / lhs[n + 2][i][j][k];
        lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
        lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k] = fac1 * rhs[m][i][j][k];
        }
        lhs[n + 2][i][j1][k] = lhs[n + 2][i][j1][k] - lhs[n + 1][i][j1][k] * lhs[n + 3][i][j][k];
        lhs[n + 3][i][j1][k] = lhs[n + 3][i][j1][k] - lhs[n + 1][i][j1][k] * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] = rhs[m][i][j1][k] - lhs[n + 1][i][j1][k] * rhs[m][i][j][k];
        }
        fac2 = 1. / lhs[n + 2][i][j1][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] = fac2 * rhs[m][i][j1][k];
        }
    }
}
}
