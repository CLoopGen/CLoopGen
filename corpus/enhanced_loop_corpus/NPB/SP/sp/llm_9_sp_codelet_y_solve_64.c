#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int j1;
extern int j2;
extern int m;



void loop(){
for (m = 3; m < 5; m += 1) {
    n = (m - 3 + 1) * 5;
    for (j = grid_points[1] - 4; j >= 1; j--) {
        j1 = j + 1;
        j2 = j1 + 1;
        for (i = 2; i <= grid_points[0] - 3; i++) {
            for (k = 2; k <= grid_points[2] - 3; k++) {
                rhs[m][i][j][k] = rhs[m][i][j][k] 
                                - lhs[n + 3][i][j][k] * rhs[m][i][j1][k] 
                                - lhs[n + 4][i][j][k] * rhs[m][i][j2][k]
                                - lhs[n + 2][i][j][k] * rhs[m][i][j][k];
            }
        }
    }
}
}
