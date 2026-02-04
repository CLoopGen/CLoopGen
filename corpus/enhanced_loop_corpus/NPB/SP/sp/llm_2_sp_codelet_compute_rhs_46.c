#include <stdio.h>

extern  int grid_points[3];
extern  double dt;
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        for (i = 1; i <= grid_points[0] - 2; i++) {
            for (j = 1; j <= grid_points[1] - 2; j++) {
                for (k = 1; k <= grid_points[2] - 2; k++) {
                    // Modify memory access to be strided by accessing every second element in k dimension
                    // Here we keep normal iteration but apply stride in access: step of 2 in k with bounds check
                    int k_step = 2;
                    if (k % k_step == 1 && k + 1 <= grid_points[2] - 2) {
                        rhs[m][i][j][k] = rhs[m][i][j][k] * dt;
                        rhs[m][i][j][k+1] = rhs[m][i][j][k+1] * dt; // process next for efficiency
                    }
                }
            }
        }
    }
}
