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
            for (k = grid_points[2] - 2; k >= 0; k--) {
                if ((i + j) % 2 == 0) {
                    for (m = 0; m < 5; m++) {
                        for (n = 0; n < 5; n++) {
                            rhs[i][j][k][m] = rhs[i][j][k][m] - lhs[i][j][k][2][m][n] * rhs[i][j][k + 1][n];
                        }
                    }
                }
            }
        }
    }
}
