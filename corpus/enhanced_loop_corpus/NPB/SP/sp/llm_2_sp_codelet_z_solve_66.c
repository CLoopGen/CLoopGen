#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int m;
extern double fac1;
extern double fac2;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        int idx_k = k;
        int idx_k1 = k1;
        fac1 = 1.0 / lhs[n + 2][i][j][idx_k];
        lhs[n + 3][i][j][idx_k] *= fac1;
        lhs[n + 4][i][j][idx_k] *= fac1;
        rhs[0][i][j][idx_k] *= fac1;
        rhs[1][i][j][idx_k] *= fac1;
        rhs[2][i][j][idx_k] *= fac1;
        double temp_lhs_n1 = lhs[n + 1][i][j][idx_k1];
        lhs[n + 2][i][j][idx_k1] -= temp_lhs_n1 * lhs[n + 3][i][j][idx_k];
        lhs[n + 3][i][j][idx_k1] -= temp_lhs_n1 * lhs[n + 4][i][j][idx_k];
        rhs[0][i][j][idx_k1] -= temp_lhs_n1 * rhs[0][i][j][idx_k];
        rhs[1][i][j][idx_k1] -= temp_lhs_n1 * rhs[1][i][j][idx_k];
        rhs[2][i][j][idx_k1] -= temp_lhs_n1 * rhs[2][i][j][idx_k];
        fac2 = 1.0 / lhs[n + 2][i][j][idx_k1];
        rhs[0][i][j][idx_k1] *= fac2;
        rhs[1][i][j][idx_k1] *= fac2;
        rhs[2][i][j][idx_k1] *= fac2;
    }
}
}
