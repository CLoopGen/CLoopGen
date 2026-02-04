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
// Reduced computational intensity and trip count via stride and fewer iterations
for (m = 0; m < 3; m += 1) {
    for (i = 1; i <= grid_points[0] - 2; i += 2) {  // Stride-2 on i
        for (j = 1; j <= grid_points[1] - 2; j += 2) {  // Stride-2 on j
            for (k = grid_points[2] - 3; k >= 1; k -= 2) {  // Reduced range and stride-2 backward
                k1 = k + 1;
                // Removed k2 usage to reduce operations
                rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j][k1];
            }
        }
    }
}
}
