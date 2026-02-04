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
    for (j = grid_points[1] - 2; j >= 0; j--) {
        for (i = 1; i < grid_points[0] - 1; i++) {
            for (k = 1; k < grid_points[2] - 1; k++) {
                if (j + i + k > 5) {
                    for (m = 0; m < 5; m++) {
                        for (n = 0; n < 5; n++) {
                            rhs[i][j][k][m] = rhs[i][j][k][m] - lhs[i][j][k][2][m][n] * rhs[i][j + 1][k][n];
                        }
                    }
                }
            }
        }
    }
}
