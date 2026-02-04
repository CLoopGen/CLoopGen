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
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        double inv_denom1 = 1.0 / lhs[n + 2][i][j][k];
        double scaled_lhs3 = inv_denom1 * lhs[n + 3][i][j][k];
        double scaled_lhs4 = inv_denom1 * lhs[n + 4][i][j][k];
        lhs[n + 3][i][j][k] = scaled_lhs3;
        lhs[n + 4][i][j][k] = scaled_lhs4;
        double local_rhs[3];
        for (m = 0; m < 3; m++) {
            local_rhs[m] = inv_denom1 * rhs[m][i][j][k];
            rhs[m][i][j][k] = local_rhs[m];
        }
        double prev_factor = lhs[n + 1][i][j1][k];
        double new_val_lhs2 = lhs[n + 2][i][j1][k] - prev_factor * scaled_lhs3;
        double new_val_lhs3 = lhs[n + 3][i][j1][k] - prev_factor * scaled_lhs4;
        lhs[n + 2][i][j1][k] = new_val_lhs2;
        lhs[n + 3][i][j1][k] = new_val_lhs3;
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] = rhs[m][i][j1][k] - prev_factor * local_rhs[m];
        }
        double inv_denom2 = 1.0 / new_val_lhs2;
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] = inv_denom2 * rhs[m][i][j1][k];
        }
    }
}
}
