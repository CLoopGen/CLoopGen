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
for (k = 1; k <= grid_points[2] - 2; k += 2) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        double *lhs_n2_j  = &lhs[n + 2][i][j][k];
        double *lhs_n3_j  = &lhs[n + 3][i][j][k];
        double *lhs_n4_j  = &lhs[n + 4][i][j][k];
        double *lhs_n1_j1 = &lhs[n + 1][i][j1][k];
        double *lhs_n2_j1 = &lhs[n + 2][i][j1][k];
        double *lhs_n3_j1 = &lhs[n + 3][i][j1][k];
        double *lhs_n4_j1 = &lhs[n + 4][i][j1][k];
        fac1 = 1.0 / (*lhs_n2_j);
        (*lhs_n3_j) *= fac1;
        (*lhs_n4_j) *= fac1;
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k] *= fac1;
        }
        (*lhs_n2_j1) -= (*lhs_n1_j1) * (*lhs_n3_j);
        (*lhs_n3_j1) -= (*lhs_n1_j1) * (*lhs_n4_j);
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] -= (*lhs_n1_j1) * rhs[m][i][j][k];
        }
        fac2 = 1.0 / (*lhs_n2_j1);
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] *= fac2;
        }
    }
}
}
