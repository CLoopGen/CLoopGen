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
    for (k = 1; k <= grid_points[2] - 2; k++) {
        lhs[0][i][3][k] = lhs[0][i][3][k] + comz1;
        lhs[1][i][3][k] = lhs[1][i][3][k] - comz4;
        lhs[2][i][3][k] = lhs[2][i][3][k] + comz6;
        lhs[3][i][3][k] = lhs[3][i][3][k] - comz4;
        lhs[4][i][3][k] = lhs[4][i][3][k] + comz1;
    }
}
}
