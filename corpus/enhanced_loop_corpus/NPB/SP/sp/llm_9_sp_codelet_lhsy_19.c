#include <stdio.h>

extern  int grid_points[3];
extern  double dtty2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 2; i <= grid_points[0] - 3; i++) {
    for (j = 2; j <= grid_points[1] - 3; j++) {
        for (k = 2; k <= grid_points[2] - 3; k++) {
            double temp1 = dtty2 * speed[i][j-1][k];
            double temp2 = dtty2 * speed[i][j+1][k];
            double temp3 = dtty2 * speed[i][j][k-1];
            double temp4 = dtty2 * speed[i][j][k+1];

            lhs[5][i][j][k] = lhs[0][i][j][k];
            lhs[6][i][j][k] = lhs[1][i][j][k] - temp1;
            lhs[7][i][j][k] = lhs[2][i][j][k] + temp3;
            lhs[8][i][j][k] = lhs[3][i][j][k] + temp2;
            lhs[9][i][j][k] = lhs[4][i][j][k] - temp4;

            lhs[10][i][j][k] = lhs[0][i][j][k];
            lhs[11][i][j][k] = lhs[1][i][j][k] + temp1;
            lhs[12][i][j][k] = lhs[2][i][j][k] - temp3;
            lhs[13][i][j][k] = lhs[3][i][j][k] - temp2;
            lhs[14][i][j][k] = lhs[4][i][j][k] + temp4;

            lhs[5][i][j][k] *= 1.001;
            lhs[10][i][j][k] *= 0.999;
        }
    }
}
}
