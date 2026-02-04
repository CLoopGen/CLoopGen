#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int n;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive access by reordering the loops to maximize spatial locality
    // We change the loop order to iterate over m and n first, which allows consecutive memory accesses within the lhs array's last dimensions.
    for (m = 0; m < 5; m++) {
        for (n = 0; n < 5; n++) {
            for (i = 0; i < grid_points[0]; i++) {
                for (j = 0; j < grid_points[1]; j++) {
                    for (k = 0; k < grid_points[2]; k++) {
                        lhs[i][j][k][0][m][n] = 0.;
                        lhs[i][j][k][1][m][n] = 0.;
                        lhs[i][j][k][2][m][n] = 0.;
                    }
                }
            }
        }
    }
}
