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
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k] *= fac1;
            }
            for (int offset = 1; offset <= 2; ++offset) {
                double coeff = lhs[n + (offset == 1 ? 1 : 0)][i][j + offset][k];
                lhs[n + 2 - offset][i][j + offset][k] -= coeff * lhs[n + 3][i][j][k];
                lhs[n + 3 - offset][i][j + offset][k] -= coeff * lhs[n + 4][i][j][k];
                for (m = 0; m < 3; m++) {
                    rhs[m][i][j + offset][k] -= coeff * rhs[m][i][j][k];
                }
            }
        }
    }
}
}
