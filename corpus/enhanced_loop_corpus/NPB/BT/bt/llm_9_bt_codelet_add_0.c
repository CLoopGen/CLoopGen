#include <stdio.h>

extern  int grid_points[3];
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 2; i < grid_points[0] - 2; i += 2) {
    for (j = 2; j < grid_points[1] - 2; j += 2) {
        for (k = 2; k < grid_points[2] - 2; k += 2) {
            for (m = 0; m < 5; m++) {
                double temp1 = rhs[i][j][k][m];
                double temp2 = rhs[i-1][j][k][m] + rhs[i][j-1][k][m] + rhs[i][j][k-1][m];
                u[i][j][k][m] = u[i][j][k][m] + temp1 + 0.25 * temp2;
            }
        }
    }
}
}
