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
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            // Add control condition to skip center plane in k-dimension
            if (k == grid_points[2] / 2) continue;
            for (m = 0; m < 5; m++) {
                // Modify computation based on index parity (introduce data-path condition)
                if ((j + k) % 2 == 0) {
                    rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (u[i][j - 2][k][m] - 4. * u[i][j - 1][k][m] + 6. * u[i][j][k][m] - 4. * u[i][j + 1][k][m]);
                } else {
                    // Alternate lightweight operation to maintain validity
                    rhs[i][j][k][m] += 0.001; // Minimal perturbation as alternate path
                }
            }
        }
    }
}
