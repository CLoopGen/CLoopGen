#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz5;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 4; i += 2) {
    for (k = 1; k <= grid_points[2] - 4; k += 2) {
        // Unrolled and fused operations: increase arithmetic per memory access
        lhs[2][i][j][k]     += comz5;
        lhs[3][i][j][k]     -= comz4;
        lhs[4][i][j][k]     += comz1;
        lhs[1][i][j+1][k]   -= comz4;
        lhs[2][i][j+1][k]   += comz6;
        lhs[3][i][j+1][k]   -= comz4;
        lhs[4][i][j+1][k]   += comz1;

        lhs[2][i+1][j][k]   += comz5;
        lhs[3][i+1][j][k]   -= comz4;
        lhs[4][i+1][j][k]   += comz1;
        lhs[1][i+1][j+1][k] -= comz4;
        lhs[2][i+1][j+1][k] += comz6;
        lhs[3][i+1][j+1][k] -= comz4;
        lhs[4][i+1][j+1][k] += comz1;

        lhs[2][i][j][k+1]   += comz5;
        lhs[3][i][j][k+1]   -= comz4;
        lhs[4][i][j][k+1]   += comz1;
        lhs[1][i][j+1][k+1] -= comz4;
        lhs[2][i][j+1][k+1] += comz6;
        lhs[3][i][j+1][k+1] -= comz4;
        lhs[4][i][j+1][k+1] += comz1;

        lhs[2][i+1][j][k+1]   += comz5;
        lhs[3][i+1][j][k+1]   -= comz4;
        lhs[4][i+1][j][k+1]   += comz1;
        lhs[1][i+1][j+1][k+1] -= comz4;
        lhs[2][i+1][j+1][k+1] += comz6;
        lhs[3][i+1][j+1][k+1] -= comz4;
        lhs[4][i+1][j+1][k+1] += comz1;
    }
}
}
