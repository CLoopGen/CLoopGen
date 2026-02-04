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
for (m = 0; m < 3; m += 2) {
    for (j = grid_points[1] - 2; j >= 0; j -= 2) {
        j1 = j + 1;
        for (i = 1; i <= grid_points[0] - 2; i++) {
            for (k = 1; k <= grid_points[2] - 2; k += 2) {
                rhs[m][i][j][k] -= lhs[n + 3][i][j][k] * rhs[m][i][j1][k];
                if (m + 1 < 3) {
                    rhs[m+1][i][j][k] = rhs[m+1][i][j][k] - lhs[n + 4][i][j][k] * rhs[m+1][i][j1][k];
                }
            }
        }
    }
}
}
