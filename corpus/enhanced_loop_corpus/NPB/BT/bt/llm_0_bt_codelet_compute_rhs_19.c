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
for (j = 1; j < grid_points[1] - 1; j++) {
    for (k = 1; k < grid_points[2] - 1; k++) {
        rhs[i][j][k][0] = rhs[i][j][k][0] - dssp * (-4. * u[i - 1][j][k][0] + 6. * u[i][j][k][0] - 4. * u[i + 1][j][k][0] + u[i + 2][j][k][0]);
        rhs[i][j][k][1] = rhs[i][j][k][1] - dssp * (-4. * u[i - 1][j][k][1] + 6. * u[i][j][k][1] - 4. * u[i + 1][j][k][1] + u[i + 2][j][k][1]);
        rhs[i][j][k][2] = rhs[i][j][k][2] - dssp * (-4. * u[i - 1][j][k][2] + 6. * u[i][j][k][2] - 4. * u[i + 1][j][k][2] + u[i + 2][j][k][2]);
        rhs[i][j][k][3] = rhs[i][j][k][3] - dssp * (-4. * u[i - 1][j][k][3] + 6. * u[i][j][k][3] - 4. * u[i + 1][j][k][3] + u[i + 2][j][k][3]);
        rhs[i][j][k][4] = rhs[i][j][k][4] - dssp * (-4. * u[i - 1][j][k][4] + 6. * u[i][j][k][4] - 4. * u[i + 1][j][k][4] + u[i + 2][j][k][4]);
    }
}
}
