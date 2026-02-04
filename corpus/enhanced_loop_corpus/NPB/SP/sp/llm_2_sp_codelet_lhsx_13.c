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
for (j = 1; j <= grid_points[1] - 2; j++) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        // Change memory access to consecutive indexing via pointer arithmetic
        double *base = &lhs[0][i][j][k];
        base[0*65*65*65 + 0] += comz1;
        base[1*65*65*65 + 0] -= comz4;
        base[2*65*65*65 + 0] += comz6;
        base[3*65*65*65 + 0] -= comz4;

        double *base_next = &lhs[0][i+1][j][k];
        base_next[0*65*65*65 + 0] += comz1;
        base_next[1*65*65*65 + 0] -= comz4;
        base_next[2*65*65*65 + 0] += comz5;
    }
}
}
