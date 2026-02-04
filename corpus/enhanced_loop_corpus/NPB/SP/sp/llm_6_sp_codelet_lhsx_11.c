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
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double temp1 = lhs[2][i][j][k] + comz5;
            double temp2 = lhs[3][i][j][k] - comz4;
            double temp3 = lhs[4][i][j][k] + comz1;
            lhs[2][i][j][k] = temp1;
            lhs[3][i][j][k] = temp2;
            lhs[4][i][j][k] = temp3;

            double temp4 = lhs[1][i + 1][j][k] - comz4;
            double temp5 = lhs[2][i + 1][j][k] + comz6;
            double temp6 = lhs[3][i + 1][j][k] - comz4;
            double temp7 = lhs[4][i + 1][j][k] + comz1;
            lhs[1][i + 1][j][k] = temp4;
            lhs[2][i + 1][j][k] = temp5;
            lhs[3][i + 1][j][k] = temp6;
            lhs[4][i + 1][j][k] = temp7;
        }
    }
}
