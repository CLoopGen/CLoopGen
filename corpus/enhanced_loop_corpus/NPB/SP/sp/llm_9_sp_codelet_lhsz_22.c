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
for (i = 1; i <= grid_points[0] - 4; i++) {
    for (j = 1; j <= grid_points[1] - 4; j++) {
        for (k = 3; k <= grid_points[2] - 4; k++) {
            lhs[0][i][j][k] = lhs[0][i][j][k] + comz1;
            lhs[1][i][j][k] = lhs[1][i][j][k] - comz4;
            lhs[2][i][j][k] = lhs[2][i][j][k] + comz6;
            lhs[3][i][j][k] = lhs[3][i][j][k] - comz4;
            lhs[4][i][j][k] = lhs[4][i][j][k] + comz1;

            // Additional computation to increase arithmetic intensity
            lhs[0][i+1][j+1][k] = lhs[0][i+1][j+1][k] + comz1 * 0.5;
            lhs[4][i+1][j+1][k] = lhs[4][i+1][j+1][k] + comz1 * 0.5;
        }
    }
}
}
