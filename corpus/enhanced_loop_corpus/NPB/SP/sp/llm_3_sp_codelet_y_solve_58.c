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



void loop(){
for (k = 1; k <= grid_points[2] - 2; k++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 0; j <= grid_points[1] - 3; j++) {
            j1 = j + 1;
            j2 = j + 2;
            double *lhs_n2 = &lhs[n + 2][i][j][k];
            double *lhs_n3 = &lhs[n + 3][i][j][k];
            double *lhs_n4 = &lhs[n + 4][i][j][k];
            double *lhs_n1_j1 = &lhs[n + 1][i][j1][k];
            double *lhs_n2_j1 = &lhs[n + 2][i][j1][k];
            double *lhs_n3_j1 = &lhs[n + 3][i][j1][k];
            double *lhs_n0_j2 = &lhs[n + 0][i][j2][k];
            double *lhs_n1_j2 = &lhs[n + 1][i][j2][k];
            double *lhs_n2_j2 = &lhs[n + 2][i][j2][k];
            double *lhs_n4_j2 = &lhs[n + 4][i][j2][k];
            double rhs_ptrs[3];
            double rhs_j1_ptrs[3];
            double rhs_j2_ptrs[3];

            fac1 = 1.0 / (*lhs_n2);
            (*lhs_n3) *= fac1;
            (*lhs_n4) *= fac1;
            for (m = 0; m < 3; m++) {
                rhs_ptrs[m] = rhs[m][i][j][k] * fac1;
            }

            (*lhs_n2_j1) -= (*lhs_n1_j1) * (*lhs_n3);
            (*lhs_n3_j1) -= (*lhs_n1_j1) * (*lhs_n4);
            for (m = 0; m < 3; m++) {
                rhs_j1_ptrs[m] = rhs[m][i][j1][k] - (*lhs_n1_j1) * rhs_ptrs[m];
            }

            (*lhs_n1_j2) -= (*lhs_n0_j2) * (*lhs_n3);
            (*lhs_n2_j2) -= (*lhs_n0_j2) * (*lhs_n4);
            for (m = 0; m < 3; m++) {
                rhs_j2_ptrs[m] = rhs[m][i][j2][k] - (*lhs_n0_j2) * rhs_ptrs[m];
            }

            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k] = rhs_ptrs[m];
                rhs[m][i][j1][k] = rhs_j1_ptrs[m];
                rhs[m][i][j2][k] = rhs_j2_ptrs[m];
            }
        }
    }
}
}
