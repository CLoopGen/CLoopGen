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
    for (k = 1; k < grid_points[2] - 1; k++) {
        rhs[i][j][k][0] = rhs[i][j][k][0] - dssp * (u[i][j - 2][k][0] - 4. * u[i][j - 1][k][0] + 5. * u[i][j][k][0]);
        rhs[i][j][k][1] = rhs[i][j][k][1] - dssp * (u[i][j - 2][k][1] - 4. * u[i][j - 1][k][1] + 5. * u[i][j][k][1]);
        rhs[i][j][k][2] = rhs[i][j][k][2] - dssp * (u[i][j - 2][k][2] - 4. * u[i][j - 1][k][2] + 5. * u[i][j][k][2]);
        rhs[i][j][k][3] = rhs[i][j][k][3] - dssp * (u[i][j - 2][k][3] - 4. * u[i][j - 1][k][3] + 5. * u[i][j][k][3]);
        rhs[i][j][k][4] = rhs[i][j][k][4] - dssp * (u[i][j - 2][k][4] - 4. * u[i][j - 1][k][4] + 5. * u[i][j][k][4]);
    }
}
}
