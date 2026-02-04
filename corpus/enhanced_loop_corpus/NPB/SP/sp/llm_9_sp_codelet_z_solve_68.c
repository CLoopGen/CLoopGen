#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int m;



void loop(){
for (m = 0; m < 2; m += 1) {
    for (i = 1; i <= grid_points[0] - 3; i++) {
        for (j = 1; j <= grid_points[1] - 3; j++) {
            for (int jj = j; jj < j + 2; jj++) {
                rhs[m][i][jj][k] = rhs[m][i][jj][k] - lhs[n + 3][i][jj][k] * rhs[m][i][jj][k1];
            }
        }
    }
}
}
