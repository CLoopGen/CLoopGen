#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int k2;
extern int m;
extern double fac1;
extern double fac2;



void loop(){
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 0; k <= grid_points[2] - 3; k += 2) {
                k1 = k + 1;
                k2 = k + 2;
                fac1 = 1. / lhs[n + 2][i][j][k];
                double temp_fac1 = fac1;
                double temp_rhs = rhs[m][i][j][k];
                double temp_lhs3 = lhs[n + 3][i][j][k];
                double temp_lhs4 = lhs[n + 4][i][j][k];

                lhs[n + 3][i][j][k] = temp_fac1 * temp_lhs3;
                lhs[n + 4][i][j][k] = temp_fac1 * temp_lhs4;
                rhs[m][i][j][k] = temp_fac1 * temp_rhs;

                if (k1 <= grid_points[2] - 2) {
                    lhs[n + 2][i][j][k1] -= lhs[n + 1][i][j][k1] * temp_lhs3;
                    lhs[n + 3][i][j][k1] -= lhs[n + 1][i][j][k1] * temp_lhs4;
                    rhs[m][i][j][k1] -= lhs[n + 1][i][j][k1] * temp_rhs;
                }

                if (k2 <= grid_points[2] - 1) {
                    lhs[n + 1][i][j][k2] -= lhs[n + 0][i][j][k2] * temp_lhs3;
                    lhs[n + 2][i][j][k2] -= lhs[n + 0][i][j][k2] * temp_lhs4;
                    rhs[m][i][j][k2] -= lhs[n + 0][i][j][k2] * temp_rhs;
                }
            }
        }
    }
    k = grid_points[2] - 2;
    k1 = grid_points[2] - 1;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;
            rhs[m][i][j][k] *= fac1;

            lhs[n + 2][i][j][k1] -= lhs[n + 1][i][j][k1] * lhs[n + 3][i][j][k];
            lhs[n + 3][i][j][k1] -= lhs[n + 1][i][j][k1] * lhs[n + 4][i][j][k];
            rhs[m][i][j][k1] -= lhs[n + 1][i][j][k1] * rhs[m][i][j][k];

            fac2 = 1. / lhs[n + 2][i][j][k1];
            rhs[m][i][j][k1] *= fac2;
        }
    }
}
}
