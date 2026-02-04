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
for (i = 4; i < grid_points[0] - 4; i++) {
    for (j = 2; j < grid_points[1] - 2; j++) {
        for (k = 2; k < grid_points[2] - 2; k++) {
            for (m = 0; m < 5; m++) {
                double temp1 = u[i - 2][j][k][m] - 4.0 * u[i - 1][j][k][m] + 6.0 * u[i][j][k][m] - 4.0 * u[i + 1][j][k][m];
                double temp2 = u[i + 2][j][k][m] - u[i - 3][j][k][m] + 4.0 * u[i - 2][j][k][m] - 6.0 * u[i - 1][j][k][m];
                rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (temp1 + temp2);
            }
        }
    }
}
}
