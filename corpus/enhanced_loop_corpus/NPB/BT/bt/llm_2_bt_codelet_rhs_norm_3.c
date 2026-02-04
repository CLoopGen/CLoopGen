#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[65][65][65][5];
extern double rms[5];
extern int i;
extern int j;
extern int k;
extern int m;
extern double add;



void loop(){
    // Variant 1: Change memory access pattern to strided access by processing every second element
    // This modifies the iteration stride in i, j, k dimensions to access non-consecutive elements
    for (i = 1; i < grid_points[0] - 1; i += 2) {
        for (j = 1; j < grid_points[1] - 1; j += 2) {
            for (k = 1; k < grid_points[2] - 1; k += 2) {
                for (m = 0; m < 5; m++) {
                    add = rhs[i][j][k][m];
                    rms[m] = rms[m] + add * add;
                }
            }
        }
    }
}
