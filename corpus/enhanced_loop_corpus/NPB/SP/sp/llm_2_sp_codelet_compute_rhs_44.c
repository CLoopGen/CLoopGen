#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive Access via Loop Interchange
    // We interchange the j and k loops to improve spatial locality if k has better stride access.
    // However, since k is used as a scalar in original code, we assume k is loop-invariant and instead
    // modify access pattern by reordering m and i to make inner loop accesses more cache-friendly.
    // Instead of accessing u[m][i][j][k-2], we maintain the same computation but change loop order
    // to iterate over m in the innermost loop for better temporal reuse of i,j indices.

    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (m = 0; m < 5; m++) {
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (u[m][i][j][k - 2] - 4. * u[m][i][j][k - 1] + 6. * u[m][i][j][k] - 4. * u[m][i][j][k + 1]);
            }
        }
    }
}
