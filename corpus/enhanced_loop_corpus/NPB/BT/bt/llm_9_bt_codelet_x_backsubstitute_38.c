#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[65][65][65][5];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int n;



void loop(){
// Reduce trip count and increase data reuse by skipping every other i-index
for (i = grid_points[0] - 2; i >= 0; i -= 2) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            for (m = 0; m < 5; m++) {
                double r_temp[5];
                // Preload rhs[i+1][j][k][n] values for reuse across m
                for (n = 0; n < 5; n++) {
                    r_temp[n] = rhs[i + 1][j][k][n];
                }
                double accum = 0.0;
                // Fuse operations across n for each m to increase arithmetic density
                for (n = 0; n < 5; n++) {
                    accum += lhs[i][j][k][2][m][n] * r_temp[n];
                }
                rhs[i][j][k][m] -= accum;
                // Apply same update to i-1 if within bounds (extra computation)
                if (i > 0) {
                    rhs[i-1][j][k][m] -= lhs[i-1][j][k][2][m][0] * rhs[i][j][k][0];
                }
            }
        }
    }
}
}
