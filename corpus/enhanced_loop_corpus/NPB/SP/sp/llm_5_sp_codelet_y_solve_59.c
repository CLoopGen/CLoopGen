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
        double temp_denom1 = lhs[n + 2][i][j][k];
        double temp_denom2;
        int valid1 = (temp_denom1 != 0.0);
        int valid2;

        if (valid1) {
            fac1 = 1. / temp_denom1;
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k] *= fac1;
            }
        } else {
            continue;
        }

        lhs[n + 2][i][j1][k] -= lhs[n + 1][i][j1][k] * lhs[n + 3][i][j][k];
        lhs[n + 3][i][j1][k] -= lhs[n + 1][i][j1][k] * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] -= lhs[n + 1][i][j1][k] * rhs[m][i][j][k];
        }

        temp_denom2 = lhs[n + 2][i][j1][k];
        valid2 = (temp_denom2 != 0.0);

        if (valid2) {
            fac2 = 1. / temp_denom2;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j1][k] *= fac2;
            }
        } else {
            for (m = 0; m < 3; m++) {
                rhs[m][i][j1][k] = 0.0;
            }
        }
    }
}
}
