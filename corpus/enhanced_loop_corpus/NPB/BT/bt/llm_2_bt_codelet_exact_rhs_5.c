#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access with increased stride (access every second element)
    for (i = 2; i < grid_points[0] - 2; i += 2) {
        for (j = 2; j < grid_points[1] - 2; j += 2) {
            for (k = 2; k < grid_points[2] - 2; k += 2) {
                for (m = 0; m < 5; m++) {
                    forcing[i][j][k][m] = -1. * forcing[i][j][k][m];
                }
            }
        }
    }
}
