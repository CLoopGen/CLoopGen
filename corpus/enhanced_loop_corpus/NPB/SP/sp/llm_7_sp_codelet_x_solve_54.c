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
double accumulator = 0.0;
for (m = 0; m < 3; m++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            accumulator += lhs[n + 3][i][j][k] * rhs[m][i1][j][k]; // Introduced loop-carried dependency via accumulator
            rhs[m][i][j][k] = rhs[m][i][j][k] - accumulator; // RAW dependency on updated accumulator
        }
    }
}
// Final write-back using accumulated value to maintain some semantic consistency
for (m = 0; m < 3; m++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            rhs[m][i][j][k] = rhs[m][i][j][k] + accumulator; // Compensate to avoid complete divergence
        }
    }
}
}
