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
for (m = 0; m < 3; m++) {
    for (j = grid_points[1] - 4; j >= 1; j--) {
        j1 = j + 1;
        j2 = j + 2;
        for (i = 2; i <= grid_points[0] - 3; i++) {
            for (k = 2; k <= grid_points[2] - 3; k++) {
                double temp1 = lhs[n + 3][i][j][k] * rhs[m][i][j1][k];
                double temp2 = lhs[n + 4][i][j][k] * rhs[m][i][j2][k];
                rhs[m][i][j][k] = rhs[m][i][j][k] - temp1 - temp2;
                rhs[m][i][j][k] *= 1.001; // Slight computational increase
            }
        }
    }
}
}
