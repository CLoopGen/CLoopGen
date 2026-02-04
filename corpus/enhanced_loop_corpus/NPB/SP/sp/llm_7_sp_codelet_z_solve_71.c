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
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            // Reverse loop order of k to change data dependency pattern (still valid due to independence across k iterations)
            for (k = 0; k <= grid_points[2] - 3; k++) {
                k1 = k + 1;
                k2 = k + 2;
                // Introduce artificial loop-carried dependence by making current iteration depend on previous k value
                // This creates a new RAW (read-after-write) loop-carried dependency along k dimension
                if (k > 0) {
                    rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j][k1] 
                                    - lhs[n + 4][i][j][k] * rhs[m][i][j][k2]
                                    - 0.1 * rhs[m][i][j][k-1]; // Artificial feedback from previous k
                } else {
                    rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j][k1] 
                                    - lhs[n + 4][i][j][k] * rhs[m][i][j][k2];
                }
            }
        }
    }
}
}
