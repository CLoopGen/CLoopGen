#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access with Reverse Traversal
    for (m = 0; m < 5; m++) {
        for (i = grid_points[0] - 2; i >= 1; i--) {  // Reverse order in i
            for (j = 1; j <= grid_points[1] - 2; j++) {
                for (k = 3 * 1; k <= grid_points[2] - 3 * 1 - 1; k += 2) {  // Stride of 2 in k to create strided access
                    rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (u[m][i][j][k - 2] - 4. * u[m][i][j][k - 1] + 6. * u[m][i][j][k] - 4. * u[m][i][j][k + 1] + u[m][i][j][k + 2]);
                }
            }
        }
    }
}
