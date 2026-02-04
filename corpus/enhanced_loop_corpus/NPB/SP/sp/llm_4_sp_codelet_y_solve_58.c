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
for (j = 0; j <= grid_points[1] - 3; j++) {
    j1 = j + 1;
    j2 = j + 2;
    if (j1 >= grid_points[1] || j2 >= grid_points[1]) continue;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            if (lhs[n + 2][i][j][k] == 0.0) {
                fac1 = 0.0;
            } else {
                fac1 = 1.0 / lhs[n + 2][i][j][k];
            }
            lhs[n + 3][i][j][k] = fac1 * lhs[n + 3][i][j][k];
            lhs[n + 4][i][j][k] = fac1 * lhs[n + 4][i][j][k];
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k] = fac1 * rhs[m][i][j][k];
            }
            if (fac1 != 0.0) {
                lhs[n + 2][i][j1][k] = lhs[n + 2][i][j1][k] - lhs[n + 1][i][j1][k] * lhs[n + 3][i][j][k];
                lhs[n + 3][i][j1][k] = lhs[n + 3][i][j1][k] - lhs[n + 1][i][j1][k] * lhs[n + 4][i][j][k];
                for (m = 0; m < 3; m++) {
                    rhs[m][i][j1][k] = rhs[m][i][j1][k] - lhs[n + 1][i][j1][k] * rhs[m][i][j][k];
                }
                lhs[n + 1][i][j2][k] = lhs[n + 1][i][j2][k] - lhs[n + 0][i][j2][k] * lhs[n + 3][i][j][k];
                lhs[n + 2][i][j2][k] = lhs[n + 2][i][j2][k] - lhs[n + 0][i][j2][k] * lhs[n + 4][i][j][k];
                for (m = 0; m < 3; m++) {
                    rhs[m][i][j2][k] = rhs[m][i][j2][k] - lhs[n + 0][i][j2][k] * rhs[m][i][j][k];
                }
            }
        }
    }
}
}
