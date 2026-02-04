#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int m;
extern double fac1;
extern double fac2;



void loop(){
for (j = 1; j <= grid_points[1] - 4; j += 2) {
    for (k = 1; k <= grid_points[2] - 4; k += 2) {
        fac1 = 1.0 / lhs[n + 2][i][j][k];
        lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
        lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k] = fac1 * rhs[m][i][j][k];
        }

        lhs[n + 2][i1][j][k] = lhs[n + 2][i1][j][k] - lhs[n + 1][i1][j][k] * lhs[n + 3][i][j][k];
        lhs[n + 3][i1][j][k] = lhs[n + 3][i1][j][k] - lhs[n + 1][i1][j][k] * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i1][j][k] = rhs[m][i1][j][k] - lhs[n + 1][i1][j][k] * rhs[m][i][j][k];
        }

        fac2 = 1.0 / lhs[n + 2][i1][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i1][j][k] = fac2 * rhs[m][i1][j][k];
        }

        int j2 = j + 1;
        int k2 = k + 1;
        if (j2 < grid_points[1] - 1 && k2 < grid_points[2] - 1) {
            fac1 = 1.0 / lhs[n + 2][i][j2][k2];
            lhs[n + 3][i][j2][k2] = fac1 * lhs[n + 3][i][j2][k2];
            lhs[n + 4][i][j2][k2] = fac1 * lhs[n + 4][i][j2][k2];
            for (m = 0; m < 3; m++) {
                rhs[m][i][j2][k2] = fac1 * rhs[m][i][j2][k2];
            }

            lhs[n + 2][i1][j2][k2] = lhs[n + 2][i1][j2][k2] - lhs[n + 1][i1][j2][k2] * lhs[n + 3][i][j2][k2];
            lhs[n + 3][i1][j2][k2] = lhs[n + 3][i1][j2][k2] - lhs[n + 1][i1][j2][k2] * lhs[n + 4][i][j2][k2];
            for (m = 0; m < 3; m++) {
                rhs[m][i1][j2][k2] = rhs[m][i1][j2][k2] - lhs[n + 1][i1][j2][k2] * rhs[m][i][j2][k2];
            }

            fac2 = 1.0 / lhs[n + 2][i1][j2][k2];
            for (m = 0; m < 3; m++) {
                rhs[m][i1][j2][k2] = fac2 * rhs[m][i1][j2][k2];
            }
        }
    }
}
}
