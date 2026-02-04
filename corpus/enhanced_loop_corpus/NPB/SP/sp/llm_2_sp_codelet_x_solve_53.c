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
extern double fac2;



void loop(){
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (i = 0; i <= grid_points[0] - 3; i++) {
        i1 = i + 1;
        i2 = i + 2;
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                int idx_k = k;
                int idx_kp1 = (k + 1) % grid_points[2];
                if (idx_kp1 < 1 || idx_kp1 > grid_points[2] - 2) continue;

                fac1 = 1. / lhs[n + 2][i][j][idx_k];
                lhs[n + 3][i][j][idx_k] = fac1 * lhs[n + 3][i][j][idx_k];
                lhs[n + 4][i][j][idx_k] = fac1 * lhs[n + 4][i][j][idx_k];
                rhs[m][i][j][idx_k] = fac1 * rhs[m][i][j][idx_k];

                lhs[n + 2][i1][j][idx_kp1] = lhs[n + 2][i1][j][idx_kp1] - lhs[n + 1][i1][j][idx_kp1] * lhs[n + 3][i][j][idx_k];
                lhs[n + 3][i1][j][idx_kp1] = lhs[n + 3][i1][j][idx_kp1] - lhs[n + 1][i1][j][idx_kp1] * lhs[n + 4][i][j][idx_k];
                rhs[m][i1][j][idx_kp1] = rhs[m][i1][j][idx_kp1] - lhs[n + 1][i1][j][idx_kp1] * rhs[m][i][j][idx_k];

                lhs[n + 1][i2][j][idx_kp1] = lhs[n + 1][i2][j][idx_kp1] - lhs[n + 0][i2][j][idx_kp1] * lhs[n + 3][i][j][idx_k];
                lhs[n + 2][i2][j][idx_kp1] = lhs[n + 2][i2][j][idx_kp1] - lhs[n + 0][i2][j][idx_kp1] * lhs[n + 4][i][j][idx_k];
                rhs[m][i2][j][idx_kp1] = rhs[m][i2][j][idx_kp1] - lhs[n + 0][i2][j][idx_kp1] * rhs[m][i][j][idx_k];
            }
        }
    }
    i = grid_points[0] - 2;
    i1 = grid_points[0] - 1;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            int idx_k = k;
            int idx_km1 = (k - 1 + grid_points[2]) % grid_points[2];
            if (idx_km1 < 1 || idx_km1 > grid_points[2] - 2) continue;

            fac1 = 1. / lhs[n + 2][i][j][idx_km1];
            lhs[n + 3][i][j][idx_km1] = fac1 * lhs[n + 3][i][j][idx_km1];
            lhs[n + 4][i][j][idx_km1] = fac1 * lhs[n + 4][i][j][idx_km1];
            rhs[m][i][j][idx_km1] = fac1 * rhs[m][i][j][idx_km1];

            lhs[n + 2][i1][j][idx_k] = lhs[n + 2][i1][j][idx_k] - lhs[n + 1][i1][j][idx_k] * lhs[n + 3][i][j][idx_km1];
            lhs[n + 3][i1][j][idx_k] = lhs[n + 3][i1][j][idx_k] - lhs[n + 1][i1][j][idx_k] * lhs[n + 4][i][j][idx_km1];
            rhs[m][i1][j][idx_k] = rhs[m][i1][j][idx_k] - lhs[n + 1][i1][j][idx_k] * rhs[m][i][j][idx_km1];

            fac2 = 1. / lhs[n + 2][i1][j][idx_k];
            rhs[m][i1][j][idx_k] = fac2 * rhs[m][i1][j][idx_k];
        }
    }
}
}
