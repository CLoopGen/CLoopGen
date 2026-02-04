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
for (i = 1; i < grid_points[0] - 2; i += 2) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = grid_points[2] - 2; k >= 0; k--) {
            for (m = 0; m < 5; m++) {
                for (n = 0; n < 5; n++) {
                    double update = lhs[i][j][k][2][m][n] * rhs[i][j][k + 1][n];
                    rhs[i][j][k][m] -= update;
                    if (i + 1 < grid_points[0] - 1) {
                        rhs[i+1][j][k][m] = rhs[i+1][j][k][m] - lhs[i+1][j][k][2][m][n] * rhs[i+1][j][k+1][n];
                    }
                }
            }
        }
    }
}
}
