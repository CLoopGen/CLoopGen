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
for (j = 1; j <= grid_points[1] - 2; j++) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        double inv_denom1 = lhs[n + 2][i][j][k];
        if (inv_denom1 == 0.0) continue;
        fac1 = 1.0 / inv_denom1;
        lhs[n + 3][i][j][k] *= fac1;
        lhs[n + 4][i][j][k] *= fac1;
        rhs[0][i][j][k] *= fac1;
        rhs[1][i][j][k] *= fac1;
        rhs[2][i][j][k] *= fac1;

        double update_factor = lhs[n + 1][i1][j][k];
        lhs[n + 2][i1][j][k] -= update_factor * lhs[n + 3][i][j][k];
        lhs[n + 3][i1][j][k] -= update_factor * lhs[n + 4][i][j][k];
        rhs[0][i1][j][k] -= update_factor * rhs[0][i][j][k];
        rhs[1][i1][j][k] -= update_factor * rhs[1][i][j][k];
        rhs[2][i1][j][k] -= update_factor * rhs[2][i][j][k];

        double inv_denom2 = lhs[n + 2][i1][j][k];
        if (inv_denom2 == 0.0) continue;
        fac2 = 1.0 / inv_denom2;
        rhs[0][i1][j][k] *= fac2;
        rhs[1][i1][j][k] *= fac2;
        rhs[2][i1][j][k] *= fac2;
    }
}
}
