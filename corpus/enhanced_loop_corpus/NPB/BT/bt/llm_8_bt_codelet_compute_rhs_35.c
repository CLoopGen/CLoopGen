#include <stdio.h>

extern  int grid_points[3];
extern  double dt;
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (j = 2; j < grid_points[1] - 2; j++) {
        for (k = 2; k < grid_points[2] - 2; k++) {
            for (m = 0; m < 5; m++) {
                double temp1, temp2;
                for (i = 2; i < grid_points[0] - 2; i++) {
                    temp1 = rhs[i][j][k][m] * dt;
                    temp2 = rhs[i-1][j][k][m] * dt;
                    rhs[i][j][k][m] = temp1 + temp2 - rhs[i][j][k][m];
                }
            }
        }
    }
}
