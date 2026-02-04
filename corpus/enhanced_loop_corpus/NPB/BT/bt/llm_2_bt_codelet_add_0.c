#include <stdio.h>

extern  int grid_points[3];
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use strided access with increased stride in the k-dimension
    // This changes the memory access pattern to skip every other element in the k dimension, creating a strided access pattern.
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (k = 1; k < grid_points[2] - 1; k += 2) {  // Strided access: step by 2 in k
                for (m = 0; m < 5; m++) {
                    u[i][j][k][m] = u[i][j][k][m] + rhs[i][j][k][m];
                }
            }
        }
    }
}
