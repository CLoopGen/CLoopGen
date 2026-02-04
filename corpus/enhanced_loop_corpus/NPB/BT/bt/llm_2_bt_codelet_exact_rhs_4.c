#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 1: Consecutive memory access by reordering loops to access the last dimension first
    // This improves spatial locality by accessing memory in the order it is laid out (row-major)
    for (m = 0; m < 5; m++) {
        for (k = 0; k < grid_points[2]; k++) {
            for (j = 0; j < grid_points[1]; j++) {
                for (i = 0; i < grid_points[0]; i++) {
                    forcing[i][j][k][m] = 0.;
                }
            }
        }
    }
}
