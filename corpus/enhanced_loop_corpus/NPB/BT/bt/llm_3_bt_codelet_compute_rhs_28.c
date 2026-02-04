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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access pattern in the k-loop with step size of 2
    // This reduces temporal locality and increases stride in k-dimension
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (k = 1; k < grid_points[2] - 1; k += 2) {  // Stride of 2 in k
            for (m = 0; m < 5; m++) {
                rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (u[i][j - 2][k][m] - 4. * u[i][j - 1][k][m] + 5. * u[i][j][k][m]);
                // Handle next k index if within bounds (to maintain correctness)
                if (k + 1 < grid_points[2] - 1) {
                    rhs[i][j][k+1][m] = rhs[i][j][k+1][m] - dssp * (u[i][j - 2][k+1][m] - 4. * u[i][j - 1][k+1][m] + 5. * u[i][j][k+1][m]);
                }
            }
        }
    }
}
