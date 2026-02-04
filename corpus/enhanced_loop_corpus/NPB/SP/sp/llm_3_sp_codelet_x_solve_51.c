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



void loop(){
for (i = 0; i <= grid_points[0] - 3; i += 2) {
    i1 = i + 1;
    i2 = i + 2;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k += 2) {
            double *lhs_n2_ik = lhs[n + 2][i][j];
            double *lhs_n3_ik = lhs[n + 3][i][j];
            double *lhs_n4_ik = lhs[n + 4][i][j];
            double *lhs_n1_i1k = lhs[n + 1][i1][j];
            double *lhs_n2_i1k = lhs[n + 2][i1][j];
            double *lhs_n3_i1k = lhs[n + 3][i1][j];
            double *lhs_n4_i1k = lhs[n + 4][i1][j];
            double *lhs_n0_i2k = lhs[n + 0][i2][j];
            double *lhs_n1_i2k = lhs[n + 1][i2][j];
            double *lhs_n2_i2k = lhs[n + 2][i2][j];

            double *rhs_0_ik = rhs[0][i][j];
            double *rhs_1_ik = rhs[1][i][j];
            double *rhs_2_ik = rhs[2][i][j];
            double *rhs_0_i1k = rhs[0][i1][j];
            double *rhs_1_i1k = rhs[1][i1][j];
            double *rhs_2_i1k = rhs[2][i1][j];
            double *rhs_0_i2k = rhs[0][i2][j];
            double *rhs_1_i2k = rhs[1][i2][j];
            double *rhs_2_i2k = rhs[2][i2][j];

            for (int kk = k; kk < k + 2 && kk <= grid_points[2] - 2; kk++) {
                fac1 = 1. / lhs_n2_ik[kk];
                lhs_n3_ik[kk] *= fac1;
                lhs_n4_ik[kk] *= fac1;
                rhs_0_ik[kk] *= fac1;
                rhs_1_ik[kk] *= fac1;
                rhs_2_ik[kk] *= fac1;

                lhs_n2_i1k[kk] -= lhs_n1_i1k[kk] * lhs_n3_ik[kk];
                lhs_n3_i1k[kk] -= lhs_n1_i1k[kk] * lhs_n4_ik[kk];
                rhs_0_i1k[kk] -= lhs_n1_i1k[kk] * rhs_0_ik[kk];
                rhs_1_i1k[kk] -= lhs_n1_i1k[kk] * rhs_1_ik[kk];
                rhs_2_i1k[kk] -= lhs_n1_i1k[kk] * rhs_2_ik[kk];

                lhs_n1_i2k[kk] -= lhs_n0_i2k[kk] * lhs_n3_ik[kk];
                lhs_n2_i2k[kk] -= lhs_n0_i2k[kk] * lhs_n4_ik[kk];
                rhs_0_i2k[kk] -= lhs_n0_i2k[kk] * rhs_0_ik[kk];
                rhs_1_i2k[kk] -= lhs_n0_i2k[kk] * rhs_1_ik[kk];
                rhs_2_i2k[kk] -= lhs_n0_i2k[kk] * rhs_2_ik[kk];
            }
        }
    }
}
}
