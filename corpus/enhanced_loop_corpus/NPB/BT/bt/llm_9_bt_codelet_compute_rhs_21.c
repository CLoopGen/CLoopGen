#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (j = 1; j < grid_points[1] - 1; j += 2) {
        for (k = 1; k < grid_points[2] - 1; k += 2) {
            double sum_r[5] = {0};
            double sum_u[5] = {0};
            for (m = 0; m < 5; m++) {
                sum_r[m] = rhs[i][j][k][m];
                sum_u[m] = u[i-2][j][k][m] - 4.0 * u[i-1][j][k][m] + 6.0 * u[i][j][k][m] - 4.0 * u[i+1][j][k][m];
            }
            for (m = 0; m < 5; m++) {
                rhs[i][j][k][m] = sum_r[m] - dssp * sum_u[m];
            }
        }
    }
}
