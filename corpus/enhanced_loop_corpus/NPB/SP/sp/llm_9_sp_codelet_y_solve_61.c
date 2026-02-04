#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int j1;
extern int m;



void loop(){
for (m = 0; m < 2; m++) {
    for (i = 1; i <= grid_points[0] - 4; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                rhs[m][i][j][k] -= lhs[n + 3][i][j][k] * rhs[m][i][j][k];
                rhs[m+1][i][j][k] -= lhs[n + 2][i][j][k] * rhs[m+1][i][j1][k];
            }
        }
    }
}
}
