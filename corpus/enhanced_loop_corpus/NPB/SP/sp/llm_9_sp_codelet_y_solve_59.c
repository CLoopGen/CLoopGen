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
for (i = 1; i <= grid_points[0] - 4; i += 2) {
    for (k = 1; k <= grid_points[2] - 4; k += 2) {
        fac1 = 1.0 / lhs[n + 2][i][j][k];
        lhs[n + 3][i][j][k] *= fac1;
        lhs[n + 4][i][j][k] *= fac1;
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k] *= fac1;
        }
        double update1 = lhs[n + 1][i][j1][k] * lhs[n + 3][i][j][k];
        double update2 = lhs[n + 1][i][j1][k] * lhs[n + 4][i][j][k];
        lhs[n + 2][i][j1][k] -= update1;
        lhs[n + 3][i][j1][k] -= update2;
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] -= lhs[n + 1][i][j1][k] * rhs[m][i][j][k];
        }
        fac2 = 1.0 / lhs[n + 2][i][j1][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] *= fac2;
        }
        if (i + 1 < grid_points[0] - 2 && k + 1 < grid_points[2] - 2) {
            int i2 = i + 1;
            int k2 = k + 1;
            double fac1b = 1.0 / lhs[n + 2][i2][j][k2];
            lhs[n + 3][i2][j][k2] *= fac1b;
            lhs[n + 4][i2][j][k2] *= fac1b;
            for (m = 0; m < 3; m++) {
                rhs[m][i2][j][k2] *= fac1b;
            }
            lhs[n + 2][i2][j1][k2] -= lhs[n + 1][i2][j1][k2] * lhs[n + 3][i2][j][k2];
            lhs[n + 3][i2][j1][k2] -= lhs[n + 1][i2][j1][k2] * lhs[n + 4][i2][j][k2];
            for (m = 0; m < 3; m++) {
                rhs[m][i2][j1][k2] -= lhs[n + 1][i2][j1][k2] * rhs[m][i2][j][k2];
            }
            double fac2b = 1.0 / lhs[n + 2][i2][j1][k2];
            for (m = 0; m < 3; m++) {
                rhs[m][i2][j1][k2] *= fac2b;
            }
        }
    }
}
}
