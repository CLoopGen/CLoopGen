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



void loop(){
for (m = 0; m < 3; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            for (j = grid_points[1] - 3; j >= 0; j--) {
                j1 = j + 1;
                j2 = j + 2;
                double temp_lhs3 = lhs[n + 3][i][j][k];
                double temp_lhs4 = lhs[n + 4][i][j][k];
                double temp_rhs_j1 = rhs[m][i][j1][k];
                double temp_rhs_j2 = rhs[m][i][j2][k];
                rhs[m][i][j][k] = rhs[m][i][j][k] - temp_lhs3 * temp_rhs_j1 - temp_lhs4 * temp_rhs_j2;
            }
        }
    }
}
}
