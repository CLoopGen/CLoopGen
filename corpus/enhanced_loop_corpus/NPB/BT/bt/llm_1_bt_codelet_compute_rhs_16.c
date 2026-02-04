#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 0; i < grid_points[0]; i++) {
    for (j = 0; j < grid_points[1]; j++) {
        for (k = 0; k < grid_points[2]; k++) {
            rhs[i][j][k][0] = forcing[i][j][k][0];
            rhs[i][j][k][1] = forcing[i][j][k][1];
            rhs[i][j][k][2] = forcing[i][j][k][2];
            rhs[i][j][k][3] = forcing[i][j][k][3];
            rhs[i][j][k][4] = forcing[i][j][k][4];
        }
    }
}
}
