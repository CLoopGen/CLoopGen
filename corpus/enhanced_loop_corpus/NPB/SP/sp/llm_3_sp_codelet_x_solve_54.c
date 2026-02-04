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
for (m = 0; m < 3; m++) {
    for (k = 1; k <= grid_points[2] - 2; k += 2) {  // Strided access in k dimension (stride of 2)
        for (j = 1; j <= grid_points[1] - 2; j++) {
            // Introduce strided memory access pattern to reduce cache contention
            // and modify access frequency.
            rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i1][j][k];
            
            // Handle next element if within bounds (unrolled stride handling)
            if (k + 1 <= grid_points[2] - 2) {
                rhs[m][i][j][k+1] = rhs[m][i][j][k+1] - lhs[n + 3][i][j][k+1] * rhs[m][i1][j][k+1];
            }
        }
    }
}
}
