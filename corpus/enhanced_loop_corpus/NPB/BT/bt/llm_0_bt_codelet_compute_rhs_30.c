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
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        rhs[i][j][k][0] = rhs[i][j][k][0] - dssp * (5. * u[i][j][k][0] - 4. * u[i][j][k + 1][0] + u[i][j][k + 2][0]);
        rhs[i][j][k][1] = rhs[i][j][k][1] - dssp * (5. * u[i][j][k][1] - 4. * u[i][j][k + 1][1] + u[i][j][k + 2][1]);
        rhs[i][j][k][2] = rhs[i][j][k][2] - dssp * (5. * u[i][j][k][2] - 4. * u[i][j][k + 1][2] + u[i][j][k + 2][2]);
        rhs[i][j][k][3] = rhs[i][j][k][3] - dssp * (5. * u[i][j][k][3] - 4. * u[i][j][k + 1][3] + u[i][j][k + 2][3]);
        rhs[i][j][k][4] = rhs[i][j][k][4] - dssp * (5. * u[i][j][k][4] - 4. * u[i][j][k + 1][4] + u[i][j][k + 2][4]);
    }
}
}
