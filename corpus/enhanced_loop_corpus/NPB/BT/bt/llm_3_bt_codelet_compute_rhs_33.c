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
    // Variant 2: Memory Access Pattern Modification - Strided Access with Fixed Index Offset
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (m = 0; m < 5; m += 2) {  // Stride of 2 over 'm' to create strided access pattern
                // Process two elements per iteration to maintain correctness
                if (m + 1 < 5) {
                    rhs[i][j][k][m]     = rhs[i][j][k][m]     - dssp * (u[i][j][k - 2][m]     - 4. * u[i][j][k - 1][m]     + 6. * u[i][j][k][m]     - 4. * u[i][j][k + 1][m]);
                    rhs[i][j][k][m + 1] = rhs[i][j][k][m + 1] - dssp * (u[i][j][k - 2][m + 1] - 4. * u[i][j][k - 1][m + 1] + 6. * u[i][j][k][m + 1] - 4. * u[i][j][k + 1][m + 1]);
                } else {
                    rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (u[i][j][k - 2][m] - 4. * u[i][j][k - 1][m] + 6. * u[i][j][k][m] - 4. * u[i][j][k + 1][m]);
                }
            }
        }
    }
}
