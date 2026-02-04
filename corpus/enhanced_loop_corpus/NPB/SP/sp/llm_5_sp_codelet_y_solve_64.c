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
    for (j = grid_points[1] - 3; j >= 0; j--) {
        j1 = j + 1;
        j2 = j1 + 1;
        for (i = 1; i <= grid_points[0] - 2; i++) {
            // Add conditional skip based on index sum to create divergent execution path
            if ((i + j + n) % 2 == 0) {
                for (k = 1; k <= grid_points[2] - 2; k++) {
                    rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j1][k] - lhs[n + 4][i][j][k] * rhs[m][i][j2][k];
                }
            } else {
                // Skip computation for odd (i+j+n), introducing control divergence
                continue;
            }
        }
    }
}
}
