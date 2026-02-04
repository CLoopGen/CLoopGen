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
// Variant: Modify memory access pattern to promote spatial locality using reordered nested loops (j-k-i instead of i-j-k) 
// and ensure consecutive access in innermost dimension (k)
for (k = grid_points[2] - 3; k >= 0; k--) {
    k1 = k + 1;
    k2 = k + 2;
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (i = 1; i <= grid_points[0] - 2; i++) {
            for (m = 0; m < 3; m++) {
                // Now the innermost loop is over m, which may improve cache reuse if m dimension is small and contiguous
                // Accesses to rhs[m][i][j][k], rhs[m][i][j][k1], etc., become more consecutive as m varies last
                rhs[m][i][j][k] = rhs[m][i][j][k] - lhs[n + 3][i][j][k] * rhs[m][i][j][k1] - lhs[n + 4][i][j][k] * rhs[m][i][j][k2];
            }
        }
    }
}
}
