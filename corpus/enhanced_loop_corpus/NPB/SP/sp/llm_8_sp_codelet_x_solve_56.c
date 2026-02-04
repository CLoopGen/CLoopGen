#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int i2;
extern int m;



void loop(){
for (i = grid_points[0] - 4; i >= 1; i--) {
    i1 = i + 1;
    i2 = i + 2;
    for (m = 0; m < 3; m++) {
        for (j = 2; j <= grid_points[1] - 3; j++) {
            for (k = 2; k <= grid_points[2] - 3; k++) {
                rhs[m][i][j][k] = rhs[m][i][j][k] 
                                - lhs[n + 3][i][j][k] * rhs[m][i1][j][k] 
                                - lhs[n + 4][i][j][k] * rhs[m][i2][j][k]
                                + lhs[n + 5][i][j][k] * rhs[m][i1][j-1][k+1];
            }
        }
    }
}
}
