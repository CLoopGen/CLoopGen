#include <stdio.h>

extern  int grid_points[3];
extern  double dt;
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (j = 1; j < grid_points[1] - 1; j++) {
    for (k = 1; k < grid_points[2] - 1; k++) {
        for (i = 1; i < grid_points[0] - 1; i++) {
            rhs[i][j][k][0] = rhs[i][j][k][0] * dt;
            rhs[i][j][k][1] = rhs[i][j][k][1] * dt;
            rhs[i][j][k][2] = rhs[i][j][k][2] * dt;
            rhs[i][j][k][3] = rhs[i][j][k][3] * dt;
            rhs[i][j][k][4] = rhs[i][j][k][4] * dt;
        }
    }
}
}
