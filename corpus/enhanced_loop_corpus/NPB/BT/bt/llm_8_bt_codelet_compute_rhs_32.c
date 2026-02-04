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
for (i = 2; i < grid_points[0] - 2; i++) {
    for (j = 2; j < grid_points[1] - 2; j++) {
        for (k = 3; k < grid_points[2] - 3; k++) {
            double temp[5];
            for (m = 0; m < 5; m++) {
                temp[m] = u[i][j][k-2][m] - 4.0 * u[i][j][k-1][m] + 6.0 * u[i][j][k][m] - 4.0 * u[i][j][k+1][m] + u[i][j][k+2][m];
            }
            for (m = 0; m < 5; m++) {
                rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * temp[m];
            }
        }
    }
}
}
