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
    // Variant 1: Memory Access Pattern Modification - Use strided access with step of 2 over k-loop (reduced iteration range accordingly)
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 2; k += 2) {  // Strided access: step by 2 in k dimension
            for (m = 0; m < 5; m++) {
                rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (u[i - 2][j][k][m] - 4. * u[i - 1][j][k][m] + 6. * u[i][j][k][m] - 4. * u[i + 1][j][k][m]);
            }
            // Handle next k+1 if within bounds to maintain correctness
            int k_next = k + 1;
            if (k_next < grid_points[2] - 1) {
                for (m = 0; m < 5; m++) {
                    rhs[i][j][k_next][m] = rhs[i][j][k_next][m] - dssp * (u[i - 2][j][k_next][m] - 4. * u[i - 1][j][k_next][m] + 6. * u[i][j][k_next][m] - 4. * u[i + 1][j][k_next][m]);
                }
            }
        }
    }
}
