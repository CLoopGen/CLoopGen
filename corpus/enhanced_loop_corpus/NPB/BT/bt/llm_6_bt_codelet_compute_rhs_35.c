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
            double temp[5];
            for (m = 0; m < 5; m++) {
                temp[m] = dt * rhs[1][j][k][m]; // Introduce temporary to create WAW and WAR dependencies
            }
            for (i = 1; i < grid_points[0] - 1; i++) {
                for (m = 0; m < 5; m++) {
                    rhs[i][j][k][m] = temp[m]; // Remove loop-carried dependency on previous rhs values; all now depend on initial value at i=1
                }
            }
        }
    }
}
