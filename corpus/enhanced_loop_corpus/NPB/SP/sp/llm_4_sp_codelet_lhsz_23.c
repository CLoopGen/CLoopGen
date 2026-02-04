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
        if ((i + j) % 2 == 0) {
            lhs[0][i][j][k] = lhs[0][i][j][k] + comz1;
            lhs[1][i][j][k] = lhs[1][i][j][k] - comz4;
            lhs[2][i][j][k] = lhs[2][i][j][k] + comz6;
            lhs[3][i][j][k] = lhs[3][i][j][k] - comz4;
        } else {
            lhs[0][i][j][k + 1] = lhs[0][i][j][k + 1] + comz1;
            lhs[1][i][j][k + 1] = lhs[1][i][j][k + 1] - comz4;
            lhs[2][i][j][k + 1] = lhs[2][i][j][k + 1] + comz5;
        }
    }
}
}
