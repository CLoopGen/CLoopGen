#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz5;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        // Change memory access to use consecutive indexing via pointer arithmetic
        double *base = &lhs[0][i][j][k];
        base[0 * 65*65*65 + 0] += comz1;
        base[1 * 65*65*65 + 0] -= comz4;
        base[2 * 65*65*65 + 0] += comz6;
        base[3 * 65*65*65 + 0] -= comz4;

        double *base_j1 = &lhs[0][i][j+1][k];
        base_j1[0 * 65*65*65 + 0] += comz1;
        base_j1[1 * 65*65*65 + 0] -= comz4;
        base_j1[2 * 65*65*65 + 0] += comz5;
    }
}
}
