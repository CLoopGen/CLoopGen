#include <stdio.h>

extern  int grid_points[3];
extern  double dttx2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder the loop to access lhs with consecutive writes by iterating over the first index (base offset) in innermost loop
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                // Group memory accesses by spatial locality: write all lhs[*][i][j][k] consecutively
                double speed_im1 = speed[i - 1][j][k];
                double speed_ip1 = speed[i + 1][j][k];
                
                lhs[5][i][j][k]   = lhs[0][i][j][k];
                lhs[6][i][j][k]   = lhs[1][i][j][k] - dttx2 * speed_im1;
                lhs[7][i][j][k]   = lhs[2][i][j][k];
                lhs[8][i][j][k]   = lhs[3][i][j][k] + dttx2 * speed_ip1;
                lhs[9][i][j][k]   = lhs[4][i][j][k];
                lhs[10][i][j][k]  = lhs[0][i][j][k];
                lhs[11][i][j][k]  = lhs[1][i][j][k] + dttx2 * speed_im1;
                lhs[12][i][j][k]  = lhs[2][i][j][k];
                lhs[13][i][j][k]  = lhs[3][i][j][k] - dttx2 * speed_ip1;
                lhs[14][i][j][k]  = lhs[4][i][j][k];
            }
        }
    }
}
