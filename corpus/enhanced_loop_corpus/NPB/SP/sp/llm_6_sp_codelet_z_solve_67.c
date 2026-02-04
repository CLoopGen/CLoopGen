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
            for (k = 0; k <= grid_points[2] - 3; k++) {
                k1 = k + 1;
                k2 = k + 2;
                fac1 = 1. / lhs[n + 2][i][j][k];
                // Introduce temporary variables to break some WAW and WAR dependencies
                double temp_lhs_n3 = lhs[n + 3][i][j][k];
                double temp_lhs_n4 = lhs[n + 4][i][j][k];
                double temp_rhs_m = rhs[m][i][j][k];

                // Update using temporaries to allow reordering
                lhs[n + 3][i][j][k] = fac1 * temp_lhs_n3;
                lhs[n + 4][i][j][k] = fac1 * temp_lhs_n4;
                rhs[m][i][j][k] = fac1 * temp_rhs_m;

                // Modify update order and introduce local accumulation to change dependency chain
                double update_k1_n2 = lhs[n + 2][i][j][k1] - lhs[n + 1][i][j][k1] * lhs[n + 3][i][j][k];
                double update_k1_n3 = lhs[n + 3][i][j][k1] - lhs[n + 1][i][j][k1] * lhs[n + 4][i][j][k];
                double update_k1_rhs = rhs[m][i][j][k1] - lhs[n + 1][i][j][k1] * rhs[m][i][j][k];

                lhs[n + 2][i][j][k1] = update_k1_n2;
                lhs[n + 3][i][j][k1] = update_k1_n3;
                rhs[m][i][j][k1] = update_k1_rhs;

                double update_k2_n1 = lhs[n + 1][i][j][k2] - lhs[n + 0][i][j][k2] * lhs[n + 3][i][j][k];
                double update_k2_n2 = lhs[n + 2][i][j][k2] - lhs[n + 0][i][j][k2] * lhs[n + 4][i][j][k];
                double update_k2_rhs = rhs[m][i][j][k2] - lhs[n + 0][i][j][k2] * rhs[m][i][j][k];

                lhs[n + 1][i][j][k2] = update_k2_n1;
                lhs[n + 2][i][j][k2] = update_k2_n2;
                rhs[m][i][j][k2] = update_k2_rhs;
            }
        }
    }
    k = grid_points[2] - 2;
    k1 = grid_points[2] - 1;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
            lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
            rhs[m][i][j][k] = fac1 * rhs[m][i][j][k];

            lhs[n + 2][i][j][k1] = lhs[n + 2][i][j][k1] - lhs[n + 1][i][j][k1] * lhs[n + 3][i][j][k];
            lhs[n + 3][i][j][k1] = lhs[n + 3][i][j][k1] - lhs[n + 1][i][j][k1] * lhs[n + 4][i][j][k];
            rhs[m][i][j][k1] = rhs[m][i][j][k1] - lhs[n + 1][i][j][k1] * rhs[m][i][j][k];

            fac2 = 1. / lhs[n + 2][i][j][k1];
            rhs[m][i][j][k1] = fac2 * rhs[m][i][j][k1];
        }
    }
}
}
