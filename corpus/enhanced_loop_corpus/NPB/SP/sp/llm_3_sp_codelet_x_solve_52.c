#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int m;
extern double fac1;
extern double fac2;



void loop(){
for (k = 1; k <= grid_points[2] - 2; k += 2) {
    for (j = 1; j <= grid_points[1] - 2; j += 2) {
        double *lhs_base_curr = &lhs[n + 2][i][j][k];
        double *lhs_base_next = &lhs[n + 2][i1][j][k];
        fac1 = 1.0 / (*lhs_base_curr);
        lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
        lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k] = fac1 * rhs[m][i][j][k];
        }
        lhs_base_next[0] = lhs_base_next[0] - lhs[n + 1][i1][j][k] * lhs[n + 3][i][j][k];
        lhs_base_next[1] = lhs_base_next[1] - lhs[n + 1][i1][j][k] * lhs[n + 4][i][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i1][j][k] = rhs[m][i1][j][k] - lhs[n + 1][i1][j][k] * rhs[m][i][j][k];
        }
        fac2 = 1.0 / lhs[n + 2][i1][j][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i1][j][k] = fac2 * rhs[m][i1][j][k];
        }
    }
}
}
