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
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 3; j <= grid_points[1] - 4; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                double temp1 = lhs[0][i][j][k] + comz1;
                double temp2 = lhs[1][i][j][k] - comz4;
                double temp3 = lhs[2][i][j][k] + comz6;
                lhs[0][i][j][k] = temp1;
                lhs[1][i][j][k] = temp2;
                lhs[2][i][j][k] = temp3;
                lhs[3][i][j][k] = temp2 - comz4; 
                lhs[4][i][j][k] = temp1 + comz1 - comz1;
            }
        }
    }
}
