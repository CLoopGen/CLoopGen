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
    for (j = 1; j <= grid_points[1] - 2; j++) {
        double temp1 = lhs[2][i][j][k] + comz5;
        double temp2 = lhs[3][i][j][k] - comz4;
        double temp3 = lhs[4][i][j][k] + comz1;
        lhs[2][i][j][k] = temp1;
        lhs[3][i][j][k] = temp2;
        lhs[4][i][j][k] = temp3;

        double temp4 = lhs[1][i][j][k + 1] - comz4;
        double temp5 = lhs[2][i][j][k + 1] + comz6;
        double temp6 = lhs[3][i][j][k + 1] - comz4;
        double temp7 = lhs[4][i][j][k + 1] + comz1;
        lhs[1][i][j][k + 1] = temp4;
        lhs[2][i][j][k + 1] = temp5;
        lhs[3][i][j][k + 1] = temp6;
        lhs[4][i][j][k + 1] = temp7;
    }
}
}
