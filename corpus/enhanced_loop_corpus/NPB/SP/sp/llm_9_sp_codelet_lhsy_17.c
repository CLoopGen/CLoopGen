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
    for (j = 3; j <= grid_points[1] - 4; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double temp1 = lhs[0][i][j][k] + comz1;
            double temp2 = lhs[1][i][j][k] - comz4;
            double temp3 = lhs[2][i][j][k] + comz6;
            double temp4 = lhs[3][i][j][k] - comz4;
            double temp5 = lhs[4][i][j][k] + comz1;

            lhs[0][i][j][k] = temp1 * 1.1;
            lhs[1][i][j][k] = temp2 * 0.9;
            lhs[2][i][j][k] = temp3 * 1.05;
            lhs[3][i][j][k] = temp4 * 0.95;
            lhs[4][i][j][k] = temp5 * 1.1;
        }
    }
}
}
