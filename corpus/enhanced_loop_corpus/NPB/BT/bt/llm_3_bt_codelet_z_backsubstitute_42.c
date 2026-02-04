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
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = grid_points[2] - 2; k >= 0; k -= 2) {
            int k1 = k;
            int k2 = k - 1;
            for (m = 0; m < 5; m++) {
                for (n = 0; n < 5; n++) {
                    rhs[i][j][k1][m] = rhs[i][j][k1][m] - lhs[i][j][k1][2][m][n] * rhs[i][j][k1 + 1][n];
                    if (k2 >= 0) {
                        rhs[i][j][k2][m] = rhs[i][j][k2][m] - lhs[i][j][k2][2][m][n] * rhs[i][j][k2 + 1][n];
                    }
                }
            }
        }
    }
}
}
