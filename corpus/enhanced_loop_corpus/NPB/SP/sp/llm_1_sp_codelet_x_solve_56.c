#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int i2;
extern int m;



void loop(){
for (i = grid_points[0] - 3; i >= 0; i--) {
    i1 = i + 1;
    i2 = i + 2;
    for (m = 0; m < 3; m++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                double temp_rhs = rhs[m][i][j][k];
                double temp_rhs_i1 = rhs[m][i1][j][k];
                double temp_rhs_i2 = rhs[m][i2][j][k];
                double lhs_n3 = lhs[n + 3][i][j][k];
                double lhs_n4 = lhs[n + 4][i][j][k];
                rhs[m][i][j][k] = temp_rhs - lhs_n3 * temp_rhs_i1 - lhs_n4 * temp_rhs_i2;
            }
        }
    }
}
}
