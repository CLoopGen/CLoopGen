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
    for (j = 0; j <= grid_points[1] - 3; j++) {
        j1 = j + 1;
        j2 = j + 2;
        for (i = 1; i <= grid_points[0] - 2; i++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                fac1 = 1. / lhs[n + 2][i][j][k];

                double update1 = fac1 * lhs[n + 3][i][j][k];
                double update2 = fac1 * lhs[n + 4][i][j][k];
                double update_rhs = fac1 * rhs[m][i][j][k];

                lhs[n + 3][i][j][k] = update1;
                lhs[n + 4][i][j][k] = update2;
                rhs[m][i][j][k] = update_rhs;

                double dep_factor = lhs[n + 1][i][j1][k];
                lhs[n + 2][i][j1][k] = lhs[n + 2][i][j1][k] - dep_factor * update1;
                lhs[n + 3][i][j1][k] = lhs[n + 3][i][j1][k] - dep_factor * update2;
                rhs[m][i][j1][k] = rhs[m][i][j1][k] - dep_factor * update_rhs;

                double dep_factor2 = lhs[n + 0][i][j2][k];
                lhs[n + 1][i][j2][k] = lhs[n + 1][i][j2][k] - dep_factor2 * update1;
                lhs[n + 2][i][j2][k] = lhs[n + 2][i][j2][k] - dep_factor2 * update2;
                rhs[m][i][j2][k] = rhs[m][i][j2][k] - dep_factor2 * update_rhs;
            }
        }
    }

    j = grid_points[1] - 2;
    j1 = grid_points[1] - 1;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            rhs[m][i][j][k] *= fac1;
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;

            double t1 = lhs[n + 1][i][j1][k] * lhs[n + 3][i][j][k];
            double t2 = lhs[n + 1][i][j1][k] * lhs[n + 4][i][j][k];
            double t3 = lhs[n + 1][i][j1][k] * rhs[m][i][j][k];

            lhs[n + 2][i][j1][k] -= t1;
            lhs[n + 3][i][j1][k] -= t2;
            rhs[m][i][j1][k] -= t3;

            fac2 = 1. / lhs[n + 2][i][j1][k];
            rhs[m][i][j1][k] *= fac2;
        }
    }
}
}
