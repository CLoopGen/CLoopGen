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
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double temp1 = comz1;
            double temp4 = comz4;
            double temp5 = comz5;
            double temp6 = comz6;

            lhs[0][i][j][k] = lhs[0][i][j][k] + temp1;
            lhs[1][i][j][k] = lhs[1][i][j][k] - temp4;
            lhs[2][i][j][k] = lhs[2][i][j][k] + temp6;
            lhs[3][i][j][k] = lhs[3][i][j][k] - temp4;

            lhs[0][i][j + 1][k] = lhs[0][i][j + 1][k] + temp1;
            lhs[1][i][j + 1][k] = lhs[1][i][j + 1][k] - temp4;
            lhs[2][i][j + 1][k] = lhs[2][i][j + 1][k] + temp5;
        }
    }
}
