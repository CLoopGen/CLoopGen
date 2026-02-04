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
for (i = grid_points[0] - 2; i >= 0; i--) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            double *rhs_ik = &rhs[i][j][k][0];
            double *rhs_ip1k = &rhs[i + 1][j][k][0];
            for (m = 0; m < 5; m++) {
                double temp = rhs_ik[m];
                for (n = 0; n < 5; n++) {
                    temp -= lhs[i][j][k][2][m][n] * rhs_ip1k[n];
                }
                rhs_ik[m] = temp;
            }
        }
    }
}
}
