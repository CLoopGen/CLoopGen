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



void loop(){
for (i = 1; i <= grid_points[0] - 3; i++) { // Reduced upper bound to decrease work
    for (j = 1; j <= grid_points[1] - 3; j++) {
        for (k = 1; k <= grid_points[2] - 4; k++) { // Shifted and reduced loop bounds
            k1 = k + 1;
            k2 = k + 2;
            // Increased computational intensity by unrolling RHS updates
            fac1 = 1.0 / lhs[n + 2][i][j][k];

            // Explicitly unroll RHS scaling (redundant but increases ops)
            rhs[0][i][j][k] *= fac1;
            rhs[1][i][j][k] *= fac1;
            rhs[2][i][j][k] *= fac1;

            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;

            // Unroll and interleave dependent updates for k1 and k2
            double lh_n1_k1 = lhs[n + 1][i][j][k1];
            double lh_n0_k2 = lhs[n + 0][i][j][k2];
            double lh_n3_k = lhs[n + 3][i][j][k];
            double lh_n4_k = lhs[n + 4][i][j][k];

            lhs[n + 2][i][j][k1] -= lh_n1_k1 * lh_n3_k;
            lhs[n + 3][i][j][k1] -= lh_n1_k1 * lh_n4_k;

            lhs[n + 1][i][j][k2] -= lh_n0_k2 * lh_n3_k;
            lhs[n + 2][i][j][k2] -= lh_n0_k2 * lh_n4_k;

            // Fully unrolled RHS updates for k1 and k2
            rhs[0][i][j][k1] -= lh_n1_k1 * rhs[0][i][j][k];
            rhs[1][i][j][k1] -= lh_n1_k1 * rhs[1][i][j][k];
            rhs[2][i][j][k1] -= lh_n1_k1 * rhs[2][i][j][k];

            rhs[0][i][j][k2] -= lh_n0_k2 * rhs[0][i][j][k];
            rhs[1][i][j][k2] -= lh_n0_k2 * rhs[1][i][j][k];
            rhs[2][i][j][k2] -= lh_n0_k2 * rhs[2][i][j][k];
        }
    }
}
}
