#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[65][65][65][5];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;
extern int n;



void loop(){
for (j = grid_points[1] - 3; j >= 1; j--) {
    for (i = 2; i < grid_points[0] - 2; i++) {
        for (k = 2; k < grid_points[2] - 2; k++) {
            for (m = 0; m < 5; m++) {
                double r = rhs[i][j][k][m];
                r -= lhs[i][j][k][2][m][0] * rhs[i][j+1][k][0];
                r -= lhs[i][j][k][2][m][1] * rhs[i][j+1][k][1];
                r -= lhs[i][j][k][2][m][2] * rhs[i][j+1][k][2];
                r -= lhs[i][j][k][2][m][3] * rhs[i][j+1][k][3];
                r -= lhs[i][j][k][2][m][4] * rhs[i][j+1][k][4];
                rhs[i][j][k][m] = r;
            }
        }
    }
}
}
