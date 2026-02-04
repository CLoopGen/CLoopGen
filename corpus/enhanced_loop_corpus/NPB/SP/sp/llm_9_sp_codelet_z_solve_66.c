#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int m;
extern double fac1;
extern double fac2;



void loop(){
for (i = 2; i <= grid_points[0] - 3; i++) {
    for (j = 2; j <= grid_points[1] - 3; j++) {
        fac1 = 1.0 / lhs[n + 2][i][j][k];
        lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
        lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k] = fac1 * rhs[m][i][j][k];
            rhs[m][i+1][j][k] = fac1 * rhs[m][i+1][j][k];
            rhs[m][i][j+1][k] = fac1 * rhs[m][i][j+1][k];
            rhs[m][i+1][j+1][k] = fac1 * rhs[m][i+1][j+1][k];
        }
        lhs[n + 2][i][j][k1] = lhs[n + 2][i][j][k1] - lhs[n + 1][i][j][k1] * lhs[n + 3][i][j][k];
        lhs[n + 3][i][j][k1] = lhs[n + 3][i][j][k1] - lhs[n + 1][i][j][k1] * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k1] = rhs[m][i][j][k1] - lhs[n + 1][i][j][k1] * rhs[m][i][j][k];
        }
        fac2 = 1.0 / lhs[n + 2][i][j][k1];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k1] = fac2 * rhs[m][i][j][k1];
        }
    }
}
}
