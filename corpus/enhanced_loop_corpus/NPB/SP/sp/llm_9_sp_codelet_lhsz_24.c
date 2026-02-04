#include <stdio.h>

extern  int grid_points[3];
extern  double dttz2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 2; i <= grid_points[0] - 3; i++) {
    for (j = 2; j <= grid_points[1] - 3; j++) {
        for (k = 2; k <= grid_points[2] - 3; k++) {
            double speed_val = speed[i][j][k];
            double factor = dttz2 * speed_val;

            lhs[5][i][j][k] = lhs[0][i][j][k] + factor;
            lhs[6][i][j][k] = lhs[1][i][j][k] - factor;
            lhs[7][i][j][k] = lhs[2][i][j][k] * 2.0;
            lhs[8][i][j][k] = lhs[3][i][j][k] + factor;
            lhs[9][i][j][k] = lhs[4][i][j][k] - factor;

            lhs[10][i][j][k] = lhs[0][i][j][k] - factor;
            lhs[11][i][j][k] = lhs[1][i][j][k] + factor;
            lhs[12][i][j][k] = lhs[2][i][j][k] * 0.5;
            lhs[13][i][j][k] = lhs[3][i][j][k] - factor;
            lhs[14][i][j][k] = lhs[4][i][j][k] + factor;

            lhs[5][i][j][k] += lhs[5][i-1][j][k];
            lhs[10][i][j][k] += lhs[10][i][j-1][k];
        }
    }
}
}
