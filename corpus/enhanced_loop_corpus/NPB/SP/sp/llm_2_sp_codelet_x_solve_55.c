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



void loop(){
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double *rhs_m = &rhs[m][i][j][k];
            double *lhs_n = &lhs[n + 3][i][j][k];
            double *rhs_m1 = &rhs[m][i1][j][k];
            *rhs_m = *rhs_m - (*lhs_n) * (*rhs_m1);
        }
    }
}
}
