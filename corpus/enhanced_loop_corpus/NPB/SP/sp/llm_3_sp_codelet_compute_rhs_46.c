#include <stdio.h>

extern  int grid_points[3];
extern  double dt;
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Change memory access pattern to consecutive by reordering loops for better spatial locality
    // Original order: m, i, j, k → New order: m, k, j, i to improve cache line utilization assuming row-major order
    for (m = 0; m < 5; m++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            for (j = 1; j <= grid_points[1] - 2; j++) {
                for (i = 1; i <= grid_points[0] - 2; i++) {
                    rhs[m][i][j][k] = rhs[m][i][j][k] * dt;
                }
            }
        }
    }
}
