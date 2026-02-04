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
for (m = 0; m < 5; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            for (j = 3 * 1; j <= grid_points[1] - 3 * 1 - 1; j++) {
                double stencil = u[m][i][j-2][k] - 4.0*u[m][i][j-1][k] + 6.0*u[m][i][j][k] - 4.0*u[m][i][j+1][k] + u[m][i][j+2][k];
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * stencil;
                // Introduce artificial WAW dependency by updating same element twice (semantically safe but changes write pattern)
                if (j == grid_points[1] - 3 * 1 - 1 && k == grid_points[2] - 2) {
                    rhs[m][i][j][k] += 0.0; // No-op with write, introduces trivial WAW without changing meaning
                }
            }
        }
    }
}
}
