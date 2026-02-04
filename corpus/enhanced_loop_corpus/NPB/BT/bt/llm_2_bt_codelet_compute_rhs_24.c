#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Use strided access with reversed inner loop order
    // This variant changes the memory access pattern by reversing the loop over m and accessing u with a fixed offset stride
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            for (m = 4; m >= 0; m--) {  // Reverse loop direction (strided backward access)
                rhs[i][j][k][m] -= dssp * (5.0 * u[i][j][k][m] - 4.0 * u[i][j + 1][k][m] + u[i][j + 2][k][m]);
            }
        }
    }
}
