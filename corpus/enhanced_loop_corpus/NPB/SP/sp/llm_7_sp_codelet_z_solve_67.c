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
    // Reverse the k-loop to create different loop-carried dependency pattern (backward traversal)
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            // Introduce a backward dependency by reversing the k-loop
            for (k = grid_points[2] - 3; k >= 0; k--) {
                k1 = k + 1;
                k2 = k + 2;
                fac1 = 1. / lhs[n + 2][i][j][k];

                // Fuse operations: combine scaling and eliminate intermediate writes where possible
                // This increases data reuse in registers and changes dependency timing
                lhs[n + 3][i][j][k] *= fac1;
                lhs[n + 4][i][j][k] *= fac1;
                rhs[m][i][j][k] *= fac1;

                // Reorder updates to k1 and k2 to increase overlap and modify RAW/WAR hazards
                double t1 = lhs[n + 1][i][j][k1] * lhs[n + 3][i][j][k];
                double t2 = lhs[n + 1][i][j][k1] * lhs[n + 4][i][j][k];
                double t3 = lhs[n + 1][i][j][k1] * rhs[m][i][j][k];

                lhs[n + 2][i][j][k1] -= t1;
                lhs[n + 3][i][j][k1] -= t2;
                rhs[m][i][j][k1] -= t3;

                double t4 = lhs[n + 0][i][j][k2] * lhs[n + 3][i][j][k];
                double t5 = lhs[n + 0][i][j][k2] * lhs[n + 4][i][j][k];
                double t6 = lhs[n + 0][i][j][k2] * rhs[m][i][j][k];

                lhs[n + 1][i][j][k2] -= t4;
                lhs[n + 2][i][j][k2] -= t5;
                rhs[m][i][j][k2] -= t6;
            }
        }
    }
    k = grid_points[2] - 2;
    k1 = grid_points[2] - 1;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            // Maintain final normalization steps
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
