#include <stdio.h>

extern  int grid_points[3];
extern  double dt;
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (j = 1; j < grid_points[1] - 1; j += 2) {
        for (k = 1; k < grid_points[2] - 1; k += 2) {
            for (i = 1; i < grid_points[0] - 1; i += 2) {
                for (m = 0; m < 5; m++) {
                    rhs[i][j][k][m] *= dt;
                    if (i + 1 < grid_points[0] - 1) rhs[i+1][j][k][m] *= dt;
                    if (k + 1 < grid_points[2] - 1) rhs[i][j][k+1][m] *= dt;
                }
            }
        }
    }
}
