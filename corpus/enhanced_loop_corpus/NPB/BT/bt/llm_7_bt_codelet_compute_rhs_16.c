#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 1; i < grid_points[0]; i++) {
        for (j = 1; j < grid_points[1]; j++) {
            for (k = 1; k < grid_points[2]; k++) {
                for (m = 0; m < 5; m++) {
                    rhs[i][j][k][m] = forcing[i-1][j-1][k-1][m] + 
                                      forcing[i][j][k][m] - 
                                      forcing[i-1][j][k][m];
                }
            }
        }
    }
    if (grid_points[0] > 0 && grid_points[1] > 0 && grid_points[2] > 0) {
        for (m = 0; m < 5; m++) {
            rhs[0][0][0][m] = forcing[0][0][0][m];
        }
    }
}
