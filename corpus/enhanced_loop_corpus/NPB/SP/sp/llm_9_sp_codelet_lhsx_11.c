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
for (j = 1; j <= grid_points[1] - 3; j++) {
    for (k = 1; k <= grid_points[2] - 3; k++) {
        double temp1 = comz5 * 0.5;
        double temp2 = comz4 * 0.5;
        double temp3 = comz1 * 0.5;
        double temp6 = comz6 * 0.5;

        lhs[2][i][j][k] = lhs[2][i][j][k] + temp1;
        lhs[3][i][j][k] = lhs[3][i][j][k] - temp2;
        lhs[4][i][j][k] = lhs[4][i][j][k] + temp3;
        lhs[1][i + 1][j][k] = lhs[1][i + 1][j][k] - temp2;
        lhs[2][i + 1][j][k] = lhs[2][i + 1][j][k] + temp6;
        lhs[3][i + 1][j][k] = lhs[3][i + 1][j][k] - temp2;
        lhs[4][i + 1][j][k] = lhs[4][i + 1][j][k] + temp3;

        lhs[2][i][j+1][k+1] = lhs[2][i][j+1][k+1] + temp1;
        lhs[3][i][j+1][k+1] = lhs[3][i][j+1][k+1] - temp2;
        lhs[4][i][j+1][k+1] = lhs[4][i][j+1][k+1] + temp3;
        lhs[1][i + 1][j+1][k+1] = lhs[1][i + 1][j+1][k+1] - temp2;
        lhs[2][i + 1][j+1][k+1] = lhs[2][i + 1][j+1][k+1] + temp6;
        lhs[3][i + 1][j+1][k+1] = lhs[3][i + 1][j+1][k+1] - temp2;
        lhs[4][i + 1][j+1][k+1] = lhs[4][i + 1][j+1][k+1] + temp3;
    }
}
}
