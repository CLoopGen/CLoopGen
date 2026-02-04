#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[65][65][65][5];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int n;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = grid_points[2] - 2; k >= 0; k--) {
            double *rhs_base = &rhs[i][j][k][0];
            double *rhs_next = &rhs[i][j][k + 1][0];
            for (m = 0; m < 5; m++) {
                double temp = 0.0;
                for (n = 0; n < 5; n++) {
                    temp += lhs[i][j][k][2][m][n] * rhs_next[n];
                }
                rhs_base[m] -= temp;
            }
        }
    }
}
}
