#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int k2;
extern int m;



void loop(){
for (m = 0; m < 3; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = grid_points[2] - 3; k >= 0; k--) {
                k1 = k + 1;
                k2 = k + 2;
                if (lhs[n + 3][i][j][k] != 0.0) {
                    rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j][k1];
                }
                if (lhs[n + 4][i][j][k] != 0.0) {
                    rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 4][i][j][k] * rhs[m][i][j][k2];
                }
            }
        }
    }
}
}
