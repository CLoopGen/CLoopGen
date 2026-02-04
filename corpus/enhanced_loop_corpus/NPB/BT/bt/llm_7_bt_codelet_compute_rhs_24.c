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
            for (m = 0; m < 5; m++) {
                double stencil = 5. * u[i][j][k][m] 
                               - 4. * u[i][j + 1][k][m] 
                               + u[i][j + 2][k][m];
                rhs[i][j][k][m] -= dssp * stencil;
                // Introduce artificial write-after-read dependency on u by updating a future element
                // This creates a WAW and potential WAR hazard if parallelized, though not loop-carried in 'i' or 'k'
                // Semantically safe since we're writing to a different index space (j+3), assuming bounds allow
                if (j + 3 < 65) {
                    u[i][j + 3][k][m] += dssp * stencil * 0.1;  // weak feedback: modifies future u, introducing new dependency
                }
            }
        }
    }
}
