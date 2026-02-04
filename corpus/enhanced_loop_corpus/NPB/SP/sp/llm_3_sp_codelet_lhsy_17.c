#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    // Strided access pattern: reverse the iteration order to create non-unit stride in the first index
    for (k = 1; k <= grid_points[2] - 2; k++) {
        for (j = 3; j <= grid_points[1] - 4; j++) {
            for (i = 1; i <= grid_points[0] - 2; i++) {
                // Now accessing along the first dimension as innermost, creating strided memory access
                lhs[0][i][j][k] = lhs[0][i][j][k] + comz1;
                lhs[1][i][j][k] = lhs[1][i][j][k] - comz4;
                lhs[2][i][j][k] = lhs[2][i][j][k] + comz6;
                lhs[3][i][j][k] = lhs[3][i][j][k] - comz4;
                lhs[4][i][j][k] = lhs[4][i][j][k] + comz1;
            }
        }
    }
}
