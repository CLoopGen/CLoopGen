#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 0; i < grid_points[0]; i += 2) {
        for (j = 0; j < grid_points[1]; j += 2) {
            for (k = 0; k < grid_points[2]; k += 2) {
                for (m = 0; m < 5; m++) {
                    double temp = forcing[i][j][k][m] + forcing[i][j][k][m+1];
                    rhs[i][j][k][m] = temp * 0.5;
                    if (i+1 < grid_points[0]) rhs[i+1][j][k][m] = temp * 0.25;
                    if (j+1 < grid_points[1]) rhs[i][j+1][k][m] = temp * 0.25;
                    if (k+1 < grid_points[2]) rhs[i][j][k+1][m] = temp * 0.25;
                }
            }
        }
    }
}
