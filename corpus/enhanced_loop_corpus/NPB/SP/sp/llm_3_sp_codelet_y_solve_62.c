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
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (i = 1; i <= grid_points[0] - 2; i += 2) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j1][k];
            if (i + 1 <= grid_points[0] - 2) {
                rhs[m][i+1][j][k] = rhs[m][i+1][j][k] - lhs[n + 3][i+1][j][k] * rhs[m][i+1][j1][k];
            }
        }
    }
}
}
