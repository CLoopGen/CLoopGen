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
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (k = 1; k <= grid_points[2] - 2; k += 2) {
        double temp1 = comz5 * 2.0;
        double temp2 = comz4 * 2.0;
        double temp3 = comz1 * 2.0;
        double temp6 = comz6 * 2.0;

        lhs[2][i][j][k] = lhs[2][i][j][k] + temp1;
        lhs[3][i][j][k] = lhs[3][i][j][k] - temp2;
        lhs[4][i][j][k] = lhs[4][i][j][k] + temp3;

        if (k + 1 <= grid_points[2] - 2) {
            lhs[2][i][j][k+1] = lhs[2][i][j][k+1] + comz5;
            lhs[3][i][j][k+1] = lhs[3][i][j][k+1] - comz4;
            lhs[4][i][j][k+1] = lhs[4][i][j][k+1] + comz1;
        }

        lhs[1][i][j + 1][k] = lhs[1][i][j + 1][k] - temp2;
        lhs[2][i][j + 1][k] = lhs[2][i][j + 1][k] + temp6;
        lhs[3][i][j + 1][k] = lhs[3][i][j + 1][k] - temp2;
        lhs[4][i][j + 1][k] = lhs[4][i][j + 1][k] + temp3;

        if (k + 1 <= grid_points[2] - 2) {
            lhs[1][i][j + 1][k+1] = lhs[1][i][j + 1][k+1] - comz4;
            lhs[2][i][j + 1][k+1] = lhs[2][i][j + 1][k+1] + comz6;
            lhs[3][i][j + 1][k+1] = lhs[3][i][j + 1][k+1] - comz4;
            lhs[4][i][j + 1][k+1] = lhs[4][i][j + 1][k+1] + comz1;
        }
    }
}
}
