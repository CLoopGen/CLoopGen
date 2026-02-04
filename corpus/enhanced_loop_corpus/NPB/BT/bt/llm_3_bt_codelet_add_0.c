#include <stdio.h>

extern  int grid_points[3];
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 2: Memory Access Pattern Modification - Reverse the iteration order to create backward consecutive access
    // This reverses the loop bounds to traverse arrays from high to low indices, maintaining unit stride but in reverse.
    for (i = grid_points[0] - 2; i >= 1; i--) {
        for (j = grid_points[1] - 2; j >= 1; j--) {
            for (k = grid_points[2] - 2; k >= 1; k--) {
                for (m = 4; m >= 0; m--) {  // Also reverse m for fully descending access
                    u[i][j][k][m] = u[i][j][k][m] + rhs[i][j][k][m];
                }
            }
        }
    }
}
