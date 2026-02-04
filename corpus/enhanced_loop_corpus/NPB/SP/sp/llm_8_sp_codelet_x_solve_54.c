#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int m;



void loop(){
for (m = 0; m < 3; m++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k += 2) {
            rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i1][j][k];
            if (k + 1 < grid_points[2] - 1) {
                rhs[m][i][j][k+1] = rhs[m][i][j][k+1] - lhs[n + 3][i][j][k+1] * rhs[m][i1][j][k+1];
            }
        }
    }
}
}
