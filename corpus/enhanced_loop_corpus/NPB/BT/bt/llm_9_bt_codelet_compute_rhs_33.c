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
for (i = 1; i < grid_points[0] - 1; i += 2) {
    for (j = 1; j < grid_points[1] - 1; j += 2) {
        for (m = 0; m < 5; m++) {
            double temp1 = u[i][j][k-2][m] - 4.0 * u[i][j][k-1][m] + 6.0 * u[i][j][k][m] - 4.0 * u[i][j][k+1][m];
            double temp2 = u[i][j][k-1][m] - 4.0 * u[i][j][k][m]   + 6.0 * u[i][j][k+1][m] - 4.0 * u[i][j][k+2][m];
            rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (temp1 + temp2) * 0.5;
        }
    }
}
}
