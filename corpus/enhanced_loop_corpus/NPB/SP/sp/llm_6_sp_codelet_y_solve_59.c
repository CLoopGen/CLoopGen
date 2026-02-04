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
        fac1 = 1. / lhs[n + 2][i][j][k];
        double temp_lhs3 = lhs[n + 3][i][j][k];
        double temp_lhs4 = lhs[n + 4][i][j][k];
        lhs[n + 3][i][j][k] = fac1 * temp_lhs3;
        lhs[n + 4][i][j][k] = fac1 * temp_lhs4;
        double temp_rhs[3];
        for (m = 0; m < 3; m++) {
            temp_rhs[m] = fac1 * rhs[m][i][j][k];
        }
        for (m = 0; m < 3; m++) {
            rhs[m][i][j][k] = temp_rhs[m];
        }
        double update_factor = lhs[n + 1][i][j1][k];
        lhs[n + 2][i][j1][k] = lhs[n + 2][i][j1][k] - update_factor * temp_lhs3;
        lhs[n + 3][i][j1][k] = lhs[n + 3][i][j1][k] - update_factor * temp_lhs4;
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] = rhs[m][i][j1][k] - update_factor * temp_rhs[m];
        }
        fac2 = 1. / lhs[n + 2][i][j1][k];
        for (m = 0; m < 3; m++) {
            rhs[m][i][j1][k] = fac2 * rhs[m][i][j1][k];
        }
    }
}
}
