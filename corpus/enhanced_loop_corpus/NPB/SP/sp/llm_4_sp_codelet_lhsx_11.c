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
            if ((j + k) % 2 == 0) {
                lhs[2][i][j][k] = lhs[2][i][j][k] + comz5;
                lhs[3][i][j][k] = lhs[3][i][j][k] - comz4;
                lhs[4][i][j][k] = lhs[4][i][j][k] + comz1;
            } else {
                lhs[1][i + 1][j][k] = lhs[1][i + 1][j][k] - comz4;
                lhs[2][i + 1][j][k] = lhs[2][i + 1][j][k] + comz6;
                lhs[3][i + 1][j][k] = lhs[3][i + 1][j][k] - comz4;
                lhs[4][i + 1][j][k] = lhs[4][i + 1][j][k] + comz1;
            }
        }
    }
}
