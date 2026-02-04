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
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (j = grid_points[1] - 2; j >= 0; j--) {
        j1 = j + 1;
        j2 = j1 + 1;
        for (i = 0; i <= grid_points[0] - 1; i++) {
            for (k = 0; k <= grid_points[2] - 1; k++) {
                double temp1 = lhs[n + 3][i][j][k];
                double temp2 = lhs[n + 4][i][j][k];
                rhs[m][i][j][k] = rhs[m][i][j][k] 
                                - temp1 * rhs[m][i][j1][k] 
                                - temp2 * rhs[m][i][j2][k]
                                + temp1 * temp2;
            }
        }
    }
}
}
