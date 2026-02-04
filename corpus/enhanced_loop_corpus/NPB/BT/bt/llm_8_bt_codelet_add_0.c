#include <stdio.h>

extern  int grid_points[3];
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 1; i < grid_points[0] - 2; i++) {
    for (j = 1; j < grid_points[1] - 2; j++) {
        for (k = 1; k < grid_points[2] - 2; k++) {
            for (m = 0; m < 5; m++) {
                u[i][j][k][m] = u[i][j][k][m] + 2.0 * rhs[i][j][k][m] - 0.5 * rhs[i+1][j][k][m];
            }
        }
    }
}
}
