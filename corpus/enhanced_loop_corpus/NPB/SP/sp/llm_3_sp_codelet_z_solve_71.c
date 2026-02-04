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
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (k = grid_points[2] - 3; k >= 0; k--) {
        k1 = k + 1;
        k2 = k + 2;
        for (i = 1; i <= grid_points[0] - 2; i++) {
            for (j = 1; j <= grid_points[1] - 2; j++) {
                // Access pattern changed: reuse k1 and k2 in a strided manner with improved spatial locality
                double temp1 = lhs[n + 3][i][j][k] * rhs[m][i][j][k1];
                double temp2 = lhs[n + 4][i][j][k] * rhs[m][i][j][k2];
                rhs[m][i][j][k] -= temp1 + temp2;
            }
        }
    }
}
}
