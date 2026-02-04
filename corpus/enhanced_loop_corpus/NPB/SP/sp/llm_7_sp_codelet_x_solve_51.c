#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int i2;
extern int m;
extern double fac1;



void loop(){
// Reverse loop bounds to change direction of data flow and eliminate forward loop-carried dependencies
for (i = grid_points[0] - 3; i >= 0; i--) {
    i1 = i + 1;
    i2 = i + 2;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            fac1 = 1. / lhs[n + 2][i][j][k];
            // Remove redundant computation by fusing operations and reordering independent statements
            // Eliminate multiple writes to same location in quick succession (reduce WAW hazards)
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k] *= fac1;
            }
            // Introduce non-linear indexing to break regular memory access patterns (simulating irregular dependence)
            int offset_j = (j + 2) % (grid_points[1] - 1);
            if (offset_j < 1) offset_j = 1;
            // Create anti-dependence (WAR) by reading before writing at i1 and i2
            lhs[n + 2][i1][offset_j][k] = lhs[n + 2][i1][offset_j][k] - lhs[n + 1][i1][offset_j][k] * lhs[n + 3][i][j][k];
            lhs[n + 3][i1][offset_j][k] = lhs[n + 3][i1][offset_j][k] - lhs[n + 1][i1][offset_j][k] * lhs[n + 4][i][j][k];
            for (m = 0; m < 3; m++) {
                rhs[m][i1][offset_j][k] = rhs[m][i1][offset_j][k] - lhs[n + 1][i1][offset_j][k] * rhs[m][i][j][k];
            }
            lhs[n + 1][i2][offset_j][k] = lhs[n + 1][i2][offset_j][k] - lhs[n + 0][i2][offset_j][k] * lhs[n + 3][i][j][k];
            lhs[n + 2][i2][offset_j][k] = lhs[n + 2][i2][offset_j][k] - lhs[n + 0][i2][offset_j][k] * lhs[n + 4][i][j][k];
            for (m = 0; m < 3; m++) {
                rhs[m][i2][offset_j][k] = rhs[m][i2][offset_j][k] - lhs[n + 0][i2][offset_j][k] * rhs[m][i][j][k];
            }
            // Add a dummy read to create artificial RAW dependency on next iteration's value
            if (i < grid_points[0] - 3) {
                volatile double dummy = lhs[n + 2][i+1][j][k]; // enforce read after write hazard
                (void)dummy;
            }
        }
    }
}
}
