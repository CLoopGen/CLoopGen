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
for (m = 3; m < 5; m++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            n = (m - 3 + 1) * 5;
            double temp = lhs[n + 3][i][j][k] * rhs[m][i1][j][k];
            rhs[m][i][j][k] = rhs[m][i][j][k] - temp;
        }
    }
}
}
